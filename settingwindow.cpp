#include "settingwindow.h"
#include "ui_settingwindow.h"
#include "mainwindow.h"

MainWindow *mainWindow;

SettingWindow::SettingWindow(const int delay, int choosingATopic, bool musicIsPlay, MusicPlayer *music, StyledWidget *parent) :
    StyledWidget(parent),
    ui(new Ui::SettingWindow),
    _music(music),
    _musicIsPlay(musicIsPlay),
    _choosingATopic(choosingATopic),
    _delay(delay)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("color: red;");
    ui->label_2->setStyleSheet("color: red;");
    ui->label_3->setStyleSheet("color: red;");
    ui->level->setStyleSheet("background-color: grey; color: red;");
    ui->theme->setStyleSheet("background-color: grey; color: red;");
    ui->apply->setStyleSheet("QPushButton { border: none; color: red; } QPushButton:hover { color: green; }");

    if (_delay == easyLevel)
    {
        ui->level->setCurrentIndex(0);
    }
    else if (_delay == middleLevel)
    {
        ui->level->setCurrentIndex(1);
    }
    else if (_delay == hardleLevel)
    {
        ui->level->setCurrentIndex(2);
    }

    if(_choosingATopic == 0)
    {
        ui->theme->setCurrentIndex(0);
    }
    else
    {
        ui->theme->setCurrentIndex(1);
    }

    if(_musicIsPlay)
    {
        ui->checkBox->setCheckState(Qt::Checked);
    }
    else
    {
        ui->checkBox->setCheckState(Qt::Unchecked);
    }

    QPixmap cursorPixmap(":/new/icons/cursor.png");
    QCursor customCursor(cursorPixmap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setCursor(customCursor);

    setWindowFlags(Qt::FramelessWindowHint);

    this->show();
}

SettingWindow::~SettingWindow()
{
    delete ui;
    delete mainWindow;
    delete _music;
}

int SettingWindow::getDelay() const
{
    return _delay;
}

void SettingWindow::setDelay(const int delay)
{
    _delay = delay;
}

int SettingWindow::getChoosingATopic() const
{
    return _choosingATopic;
}

void SettingWindow::setChoosingATopic(const int choosingATopic)
{
    _choosingATopic = choosingATopic;
}

int SettingWindow::getMusicIsPlay() const
{
    return _musicIsPlay;
}

void SettingWindow::setMusicIsPlay(const bool musicIsPla)
{
    _musicIsPlay = musicIsPla;
}

void SettingWindow::on_apply_clicked()
{
    QString currentText = ui->level->currentText();

    if (currentText == "Легко")
    {
        setDelay(easyLevel);
    }
    else if (currentText == "Средне")
    {
        setDelay(middleLevel);
    }
    else if (currentText == "Сложно")
    {
        setDelay(hardleLevel);
    }

    currentText = ui->theme->currentText();

    if(currentText == "Весёлая")
    {
        setChoosingATopic(0);
        _music->stopBackgroundActionMusic();
        _music->playBackgroundFunMusic();
    }
    else
    {
        setChoosingATopic(1);
        _music->stopBackgroundFunMusic();
        _music->playBackgroundActionMusic();
    }

    bool checked = ui->checkBox->isChecked();

    if(!checked)
    {
        _musicIsPlay = checked;
    }
    else
    {
        _musicIsPlay = checked;
        if(getChoosingATopic() == 0)
        {
            _music->playBackgroundFunMusic();
        }
        else
        {
            _music->playBackgroundActionMusic();
        }
    }

    this->close();

    mainWindow = new MainWindow(getDelay(), _music, _choosingATopic, _musicIsPlay);

    mainWindow->show();
}
