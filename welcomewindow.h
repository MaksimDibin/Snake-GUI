
#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit WelcomeWindow(QWidget *parent = nullptr);

private slots:
    void onPlayButtonClicked();
    void onSettingsButtonClicked();

private:
    QWidget *centralWidget;
};

#endif // WELCOMEWINDOW_H
