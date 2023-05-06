
#include "styledwidget.h"

StyledWidget::StyledWidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(WIDTH, HEIGHT);

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/new/icons/grass.jpg")));
    this->setPalette(palette);
}

QFont StyledWidget::getFont() const
{
    int fontID = QFontDatabase::addApplicationFont(":/new/fonts/FerdinandFont-Regular.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontID);

    QFont font(fontFamilies.at(0), 40, QFont::Bold  );

    return font;
}

QString StyledWidget::getStyledButton() const
{
    QString styleedButton = "QPushButton { border: none; color: red; } QPushButton:hover { color: green; }";
    return styleedButton;
}

QString StyledWidget::getBackGroundImage() const
{
    QString backGroundImage = "background-image: url(:/new/icons/grass.jpg);";
    return backGroundImage;
}

int StyledWidget::getWidth() const
{
    return WIDTH;
}

int StyledWidget::getHeight() const
{
    return HEIGHT;
}
