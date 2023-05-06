
#ifndef STYLEDWIDGET_H
#define STYLEDWIDGET_H

#include <QWidget>
#include <QString>
#include <QFontDatabase>

class StyledWidget : public QWidget
{
public:
    StyledWidget(QWidget *parent);
    QFont getFont() const;
    QString getStyledButton() const;
    QString getBackGroundImage() const;
    int getWidth() const;
    int getHeight() const;

private:
    const int WIDTH = 600;
    const int HEIGHT = 600;
};

#endif // STYLEDWIDGET_H
