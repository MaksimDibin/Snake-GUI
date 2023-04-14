
#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "welcomewindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WelcomeWindow welcomeWindow;

    welcomeWindow.setWindowTitle("Змейка");

    welcomeWindow.setFixedSize(600, 600);

    welcomeWindow.show();

    return app.exec();
}
