#include <QApplication>
#include "welcomewindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WelcomeWindow welcomeWindow;

    return app.exec();
}
