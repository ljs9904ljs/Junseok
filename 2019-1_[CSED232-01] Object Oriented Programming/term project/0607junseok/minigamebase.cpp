#include "minigamebase.h"
#include "ui_minigamebase.h"

MiniGameBase::MiniGameBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniGameBase)
{
    ui->setupUi(this);

    QFont f( "메이플스토리", 11, QFont::Thin);
    ui->GoBack->setFont(f);
    ui->MiniGame_1->setFont(f);
    ui->MiniGame_2->setFont(f);
    ui->MiniGame_3->setFont(f);
}

MiniGameBase::~MiniGameBase()
{
    delete ui;
}

void MiniGameBase::setUserMoney()
{
  emit awardgained();
}

void MiniGameBase::on_MiniGame_1_clicked()
{
    quiz = new SpeedQuiz;
    connect(quiz, SIGNAL(moneyChange()), this, SLOT(setUserMoney()));
    this->close();
    quiz->show();
}

void MiniGameBase::on_MiniGame_2_clicked()
{
    RSP = new Rock_Scissors_Paper;
    connect(RSP, SIGNAL(moneyChange()), this, SLOT(setUserMoney()));
    this->close();
    RSP->show();
}

void MiniGameBase::on_MiniGame_3_clicked()
{
    RL = new roulette;
    connect(RL, SIGNAL(moneyChange()), this, SLOT(setUserMoney()));
    this->close();
    RL->show();
}


void MiniGameBase::on_GoBack_clicked()
{
    this->close();
}
