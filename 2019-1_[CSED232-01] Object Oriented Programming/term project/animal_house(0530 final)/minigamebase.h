#ifndef MINIGAMEBASE_H
#define MINIGAMEBASE_H

#include <QWidget>
#include "speedquiz.h"
#include "rock_scissors_paper.h"
#include "roulette.h"

namespace Ui {
class MiniGameBase;
}

class MiniGameBase : public QWidget
{
    Q_OBJECT

public:
    explicit MiniGameBase(QWidget *parent = nullptr);
    ~MiniGameBase();

private slots:
    void on_MiniGame_1_clicked();

    void on_MiniGame_2_clicked();

    void on_MiniGame_3_clicked();

    void on_Albeit_clicked();

    void on_GoBack_clicked();

private:
    Ui::MiniGameBase *ui;

    SpeedQuiz* quiz;
    Rock_Scissors_Paper* RSP;
    roulette* RL;
};

#endif // MINIGAMEBASE_H
