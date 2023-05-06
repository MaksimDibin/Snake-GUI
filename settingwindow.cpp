
#include "settingwindow.h"
#include "welcomewindow.h"

WelcomeWindow *welcomeWindow;

SettingWindow::SettingWindow(const int delay, StyledWidget *parent) : StyledWidget(parent), delay_(delay)
{
    setDelay(delay);

    QFont font(this->getFont());

    text = new QLabel("Выбор сложности:", this);
    text->setFont(font);
    text->setStyleSheet("color: red;");

    difficultyComboBox = new QComboBox(this);
    difficultyComboBox->setFont(font);
    difficultyComboBox->setFocusPolicy(Qt::ClickFocus);
    difficultyComboBox->setStyleSheet("background-color: grey; color: red;");
    difficultyComboBox->addItem("Легко");
    difficultyComboBox->addItem("Средне");
    difficultyComboBox->addItem("Сложно");

    if (delay_ == 400)
    {
        difficultyComboBox->setCurrentIndex(0);
    }
    else if (delay_ == 200)
    {
        difficultyComboBox->setCurrentIndex(1);
    }
    else if (delay_ == 100)
    {
        difficultyComboBox->setCurrentIndex(2);
    }

    applyButton = new QPushButton("Применить", this);
    applyButton->setFont(font);
    applyButton->setFocusPolicy(Qt::ClickFocus);
    applyButton->setStyleSheet("QPushButton { border: none; color: red; } QPushButton:hover { color: green; }");
    connect(applyButton, &QPushButton::clicked, this, &SettingWindow::onApplyButtonClicked);

    vbox = new QVBoxLayout(this);
    vbox->addWidget(text);
    vbox->addWidget(difficultyComboBox);
    vbox->addWidget(applyButton);

    vbox->setAlignment(Qt::AlignCenter);

    QPixmap cursorPixmap(":/new/icons/cursor.png");
    QCursor customCursor(cursorPixmap.scaled(35, 35));
    setCursor(customCursor);

    setWindowFlags(Qt::FramelessWindowHint);

    this->show();
}

SettingWindow::~SettingWindow()
{
    delete applyButton;
    delete text;
    delete vbox;
    delete difficultyComboBox;
    delete welcomeWindow;
}

int SettingWindow::getDelay() const
{
    return delay_;
}

void SettingWindow::setDelay(const int delay)
{
    delay_ = delay;
}

void SettingWindow::onApplyButtonClicked()
{

    difficultyComboBox = this->findChild<QComboBox*>();

    QString currentText = difficultyComboBox->currentText();

    if (currentText == "Легко")
    {
        setDelay(400);
    } else if (currentText == "Средне")
    {
        setDelay(200);
    } else if (currentText == "Сложно")
    {
        setDelay(100);
    }

    this->close();

    welcomeWindow = new WelcomeWindow(getDelay());
}
