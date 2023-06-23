/********************************************************************************
** Form generated from reading UI file 'leaderboard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERBOARD_H
#define UI_LEADERBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeaderBoard
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *LeaderBoard)
    {
        if (LeaderBoard->objectName().isEmpty())
            LeaderBoard->setObjectName("LeaderBoard");
        LeaderBoard->resize(600, 600);
        tableWidget = new QTableWidget(LeaderBoard);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(40, 140, 531, 241));
        QFont font;
        font.setPointSize(15);
        tableWidget->setFont(font);
        tableWidget->setLineWidth(0);
        tableWidget->setAutoScroll(false);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setGridStyle(Qt::CustomDashLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->horizontalHeader()->setDefaultSectionSize(250);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(40);
        tableWidget->verticalHeader()->setDefaultSectionSize(70);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        retranslateUi(LeaderBoard);

        QMetaObject::connectSlotsByName(LeaderBoard);
    } // setupUi

    void retranslateUi(QWidget *LeaderBoard)
    {
        LeaderBoard->setWindowTitle(QCoreApplication::translate("LeaderBoard", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("LeaderBoard", "\320\236\321\207\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("LeaderBoard", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("LeaderBoard", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("LeaderBoard", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("LeaderBoard", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeaderBoard: public Ui_LeaderBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERBOARD_H
