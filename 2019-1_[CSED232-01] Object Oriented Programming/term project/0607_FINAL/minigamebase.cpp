#include "minigamebase.h"
#include "ui_minigamebase.h"

#include <QFontDatabase>
#include <QString>

MiniGameBase::MiniGameBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniGameBase)
{
    int id = QFontDatabase::addApplicationFont("./Maplestory.ttf");
    QString font = QFontDatabase::applicationFontFamilies(id).at(0);

    ui->setupUi(this);

    MiniGameBase::setFont(font);
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
