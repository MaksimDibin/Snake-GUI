#ifndef SCORE_H
#define SCORE_H

#include "settingwindow.h"
#include "styledwidget.h"

#include <QWidget>

using namespace std;

namespace Ui {
class Score;
}

class Score : public QWidget
{
    Q_OBJECT

public:
    explicit Score(StyledWidget *sw , QWidget *parent = nullptr);
    ~Score();
    void add();
    void checkDelay(const int delay);

private:
    Ui::Score *ui;
    SettingWindow *settingWindow;
    int score = 0;
    int multiplier;

};

#endif // SCORE_H
