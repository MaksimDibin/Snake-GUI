
#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>
#include "styledwidget.h"

class SettingWindow :public StyledWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(const int delay, StyledWidget *parent = nullptr);
    ~SettingWindow();
    int getDelay() const;
    void setDelay(const int delay);

private slots:
    void onApplyButtonClicked();

private:
    int delay_;
    QPushButton *applyButton;
    QLabel *text;
    QVBoxLayout *vbox;
    QComboBox *difficultyComboBox;
};

#endif // SETTINGWINDOW_H
