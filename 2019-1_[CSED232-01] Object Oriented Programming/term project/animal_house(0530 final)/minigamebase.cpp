#include "minigamebase.h"
#include "ui_minigamebase.h"

MiniGameBase::MiniGameBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniGameBase)
{
    ui->setupUi(this);
}

MiniGameBase::~MiniGameBase()
{
    delete ui;
}

void MiniGameBase::on_MiniGame_1_clicked()
{
    quiz = new SpeedQuiz;

    this->close();
    quiz->show();
}

void MiniGameBase::on_MiniGame_2_clicked()
{
    RSP = new Rock_Scissors_Paper;

    this->close();
    RSP->show();
}

void MiniGameBase::on_MiniGame_3_clicked()
{
    RL = new roulette;

    this->close();
    RL->show();
}

void MiniGameBase::on_Albeit_clicked()
{

}

void MiniGameBase::on_GoBack_clicked()
{
    this->close();
}
