#include "score.h"
#include "ui_score.h"

Score::Score(StyledWidget *sw, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Score)
{
    ui->setupUi(this);

    QRect firstWindowGeometry = sw->geometry();

    this->move(firstWindowGeometry.right() + 500, firstWindowGeometry.left() + 200);

    this->setStyleSheet("background-color: gray;");

    setCursor(Qt::BlankCursor);

    setWindowFlags(Qt::FramelessWindowHint);

    ui->score->setFont(sw->getFont(60));
    ui->score->setFrame(false);

    ui->lineEdit->setFrame(false);
    ui->lineEdit->setFont(sw->getFont(25));
    ui->lineEdit->setStyleSheet("color: green");

    this->show();
}

Score::~Score()
{
    delete ui;
}

void Score::add()
{
    score += multiplier;
    ui->score->setText(QString::number(score));
}

void Score::checkDelay(const int delay)
{
    if (delay <= 300 && delay > 200)
    {
        ui->score->setStyleSheet("color: green;");
        multiplier = 1;
    }
    else if (delay <= 200 && delay > 100)
    {
        ui->score->setStyleSheet("color: yellow;");
        multiplier = 3;
    }
    else
    {
        ui->score->setStyleSheet("color: red;");
        multiplier = 5;
    }
}
