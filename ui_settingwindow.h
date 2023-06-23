/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *level;
    QLabel *label_2;
    QComboBox *theme;
    QLabel *label_3;
    QCheckBox *checkBox;
    QPushButton *apply;

    void setupUi(QWidget *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName("SettingWindow");
        SettingWindow->resize(600, 600);
        formLayoutWidget = new QWidget(SettingWindow);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 190, 584, 165));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        level = new QComboBox(formLayoutWidget);
        level->addItem(QString());
        level->addItem(QString());
        level->addItem(QString());
        level->setObjectName("level");
        level->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(level->sizePolicy().hasHeightForWidth());
        level->setSizePolicy(sizePolicy1);
        level->setFont(font);
        level->setFocusPolicy(Qt::NoFocus);
        level->setAutoFillBackground(true);
        level->setEditable(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, level);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        theme = new QComboBox(formLayoutWidget);
        theme->addItem(QString());
        theme->addItem(QString());
        theme->setObjectName("theme");
        theme->setEnabled(true);
        sizePolicy1.setHeightForWidth(theme->sizePolicy().hasHeightForWidth());
        theme->setSizePolicy(sizePolicy1);
        theme->setFont(font);
        theme->setFocusPolicy(Qt::NoFocus);
        theme->setEditable(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, theme);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        checkBox = new QCheckBox(formLayoutWidget);
        checkBox->setObjectName("checkBox");
        checkBox->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(20);
        checkBox->setFont(font1);
        checkBox->setAcceptDrops(true);
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox);

        apply = new QPushButton(SettingWindow);
        apply->setObjectName("apply");
        apply->setGeometry(QRect(200, 500, 161, 41));
        apply->setFont(font);

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("SettingWindow", "\320\222\321\213\320\261\320\276\321\200 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270:", nullptr));
        level->setItemText(0, QCoreApplication::translate("SettingWindow", "\320\233\320\265\320\263\320\272\320\276", nullptr));
        level->setItemText(1, QCoreApplication::translate("SettingWindow", "\320\241\321\200\320\265\320\264\320\275\320\265", nullptr));
        level->setItemText(2, QCoreApplication::translate("SettingWindow", "\320\241\320\273\320\276\320\266\320\275\320\276", nullptr));

        level->setCurrentText(QCoreApplication::translate("SettingWindow", "\320\233\320\265\320\263\320\272\320\276", nullptr));
        label_2->setText(QCoreApplication::translate("SettingWindow", "\320\222\321\213\320\261\320\276\321\200 \321\202\320\265\320\274\321\213:", nullptr));
        theme->setItemText(0, QCoreApplication::translate("SettingWindow", "\320\222\320\265\321\201\321\221\320\273\320\260\321\217", nullptr));
        theme->setItemText(1, QCoreApplication::translate("SettingWindow", "\320\255\320\272\321\210\320\265\320\275", nullptr));

        theme->setCurrentText(QCoreApplication::translate("SettingWindow", "\320\222\320\265\321\201\321\221\320\273\320\260\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("SettingWindow", "\320\234\321\203\320\267\321\213\320\272\320\260:", nullptr));
        checkBox->setText(QString());
        apply->setText(QCoreApplication::translate("SettingWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
