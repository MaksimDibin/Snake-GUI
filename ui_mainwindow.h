/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *play;
    QPushButton *setting;
    QPushButton *leaderboard;
    QPushButton *exit;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 600);
        verticalLayoutWidget = new QWidget(MainWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(53, 40, 481, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        play = new QPushButton(verticalLayoutWidget);
        play->setObjectName("play");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(play->sizePolicy().hasHeightForWidth());
        play->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(40);
        font.setItalic(false);
        play->setFont(font);
        play->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(play);

        setting = new QPushButton(verticalLayoutWidget);
        setting->setObjectName("setting");
        sizePolicy.setHeightForWidth(setting->sizePolicy().hasHeightForWidth());
        setting->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(40);
        setting->setFont(font1);
        setting->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(setting);

        leaderboard = new QPushButton(verticalLayoutWidget);
        leaderboard->setObjectName("leaderboard");
        leaderboard->setFont(font1);

        verticalLayout->addWidget(leaderboard);

        exit = new QPushButton(verticalLayoutWidget);
        exit->setObjectName("exit");
        sizePolicy.setHeightForWidth(exit->sizePolicy().hasHeightForWidth());
        exit->setSizePolicy(sizePolicy);
        exit->setFont(font1);
        exit->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(exit);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
#if QT_CONFIG(whatsthis)
        play->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt; color:#ff0000;\">\320\230\320\263\321\200\320\260\321\202\321\214</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        play->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260\321\202\321\214", nullptr));
        setting->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        leaderboard->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \320\273\320\270\320\264\320\265\321\200\320\276\320\262", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
