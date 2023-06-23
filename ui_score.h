/********************************************************************************
** Form generated from reading UI file 'score.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORE_H
#define UI_SCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Score
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *score;

    void setupUi(QWidget *Score)
    {
        if (Score->objectName().isEmpty())
            Score->setObjectName("Score");
        Score->resize(200, 200);
        QFont font;
        font.setPointSize(20);
        Score->setFont(font);
        Score->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayoutWidget = new QWidget(Score);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 201, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        score = new QLineEdit(verticalLayoutWidget);
        score->setObjectName("score");
        QFont font1;
        font1.setPointSize(60);
        score->setFont(font1);
        score->setMouseTracking(false);
        score->setFocusPolicy(Qt::NoFocus);
        score->setContextMenuPolicy(Qt::NoContextMenu);
        score->setStyleSheet(QString::fromUtf8("QLineEdit { border: none }"));
        score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(score);


        retranslateUi(Score);

        QMetaObject::connectSlotsByName(Score);
    } // setupUi

    void retranslateUi(QWidget *Score)
    {
        Score->setWindowTitle(QCoreApplication::translate("Score", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("Score", " \320\242\320\262\320\276\320\270 \320\276\321\207\320\272\320\270:", nullptr));
        score->setText(QCoreApplication::translate("Score", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Score: public Ui_Score {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORE_H
