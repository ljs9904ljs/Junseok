#include "rock_scissors_paper.h"
#include "ui_rock_scissors_paper.h"


#include <QPixmap>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <string>
#include <QUrl>
#include <limits>
#include <time.h>

Rock_Scissors_Paper::Rock_Scissors_Paper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rock_Scissors_Paper)
{
    ui->setupUi(this);

    timer = new QTimer;
    win = new QTimer;
    tie = new QTimer;
    lose = new QTimer;

    win->setSingleShot(true);
    tie->setSingleShot(true);
    lose->setSingleShot(true);

    QFont title( "메이플스토리", 14, QFont::Bold);
    QFont content( "메이플스토리", 12, QFont::Thin);

    ui->Rock->setVisible(false);
    ui->Scissors->setVisible(false);
    ui->Paper->setVisible(false);
    ui->Retry_Button->setVisible(false);
    ui->Get_out_Button->setVisible(false);

    ui->Rock->setFont(content);
    ui->Scissors->setFont(content);
    ui->Paper->setFont(content);
    ui->Choose->setFont(content);
    ui->Player->setFont(content);
    ui->Opponent->setFont(content);
    ui->Retry_Button->setFont(content);
    ui->Get_out_Button->setFont(content);
    ui->Retry_Button->setFont(content);
    ui->label_3->setFont(content);

    ui->label->setFont(title);
    ui->label_2->setFont(content);
    ui->label->setText("가위바위보에 오신 것을 환영합니다!");
    ui->label_2->setText("규칙은 그림을 참고해주세요~");

    ui->Choose->setFont(title);
    ui->Choose->setText("빨리 골라보세요!!!!");
    ui->Choose->setVisible(false);

    pix.load("./image/mini_game/RSP_Rule.png");
    rock.load("./image/mini_game/Rock.png");
    scissors.load("./image/mini_game/Scissors.png");
    paper.load("./image/mini_game/Paper.png");

    win_image.load("./image/mini_game/win_image.jpg");
    lose_image.load("./image/mini_game/lose_image.jpg");
    tie_image.load("./image/mini_game/tie_image.png");

    const int w = ui->label_3->width();
    const int h = ui->label_3->height();
    ui->label_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    QIcon RockIcon(rock);
    ui->Rock->setIcon(RockIcon);
    ui->Rock->setIconSize(QSize(171,161));

    QIcon ScissorsIcon(scissors);
    ui->Scissors->setIcon(ScissorsIcon);
    ui->Scissors->setIconSize(QSize(171,161));

    QIcon PaperIcon(paper);
    ui->Paper->setIcon(PaperIcon);
    ui->Paper->setIconSize(QSize(171,161));

    connect(timer, SIGNAL(timeout()), this, SLOT(change_opponent_image()));
    connect(win, SIGNAL(timeout()), this, SLOT(win_event()));
    connect(lose, SIGNAL(timeout()), this, SLOT(lose_event()));
    connect(tie, SIGNAL(timeout()), this, SLOT(tie_event()));
}

Rock_Scissors_Paper::~Rock_Scissors_Paper()
{
    delete ui;
}

void Rock_Scissors_Paper::on_ProgressButton_clicked()
{

    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);

    ui->ProgressButton->setVisible(false);

    ui->Rock->setVisible(true);
    ui->Scissors->setVisible(true);
    ui->Paper->setVisible(true);

    ui->Choose->setVisible(true);


    timer->start(0);
}

void Rock_Scissors_Paper::change_opponent_image()
{
    if(i == std::numeric_limits<int>::max())
        i = 0;
    //오버 플로우 방지

    i++;
    timer->start(100);

    const int w = ui->Opponent->width();
    const int h = ui->Opponent->height();

    switch (i%3)
    {

    case 0: ui->Opponent->setPixmap(rock.scaled(w,h,Qt::KeepAspectRatio)); break;

    case 1: ui->Opponent->setPixmap(scissors.scaled(w,h,Qt::KeepAspectRatio)); break;

    case 2: ui->Opponent->setPixmap(paper.scaled(w,h,Qt::KeepAspectRatio)); break;

    }

}

void Rock_Scissors_Paper::on_Rock_clicked()
{
    timer->stop();

    ui->Choose->setText("");
    ui->Rock->setVisible(false);
    ui->Scissors->setVisible(false);
    ui->Paper->setVisible(false);

    const int w = ui->Opponent->width();
    const int h = ui->Opponent->height();
    //player and Opponent share the same width and height

    ui->Player->setPixmap(rock.scaled(w,h,Qt::KeepAspectRatio));
    ui->Player->setVisible(true);

    srand(time(NULL));
    auto choice_of_opponent = rand() % 3;

    switch(choice_of_opponent)
    {
    case 0:
        ui->Opponent->setPixmap(rock.scaled(w,h,Qt::KeepAspectRatio));
        tie->start(2000);
        break;

    case 1:
        ui->Opponent->setPixmap(scissors.scaled(w,h,Qt::KeepAspectRatio));
        win->start(2000);
        break;

    case 2:
        ui->Opponent->setPixmap(paper.scaled(w,h,Qt::KeepAspectRatio));
        lose->start(2000);
        break;

    }
}

void Rock_Scissors_Paper::on_Scissors_clicked()
{
    timer->stop();

    ui->Choose->setText("");
    ui->Rock->setVisible(false);
    ui->Scissors->setVisible(false);
    ui->Paper->setVisible(false);

    const int w = ui->Opponent->width();
    const int h = ui->Opponent->height();
    //player and Opponent share the same width and height

    ui->Player->setPixmap(scissors.scaled(w,h,Qt::KeepAspectRatio));
    ui->Player->setVisible(true);

    srand(time(NULL));
    auto choice_of_opponent = rand() % 3;

    switch(choice_of_opponent)
    {
    case 0:
        ui->Opponent->setPixmap(rock.scaled(w,h,Qt::KeepAspectRatio));
        lose->start(2000);
        break;

    case 1:
        ui->Opponent->setPixmap(scissors.scaled(w,h,Qt::KeepAspectRatio));
        tie->start(2000);
        break;

    case 2:
        ui->Opponent->setPixmap(paper.scaled(w,h,Qt::KeepAspectRatio));
        win->start(2000);
        break;

    }
}

void Rock_Scissors_Paper::on_Paper_clicked()
{
    timer->stop();

    ui->Choose->setText("");
    ui->Rock->setVisible(false);
    ui->Scissors->setVisible(false);
    ui->Paper->setVisible(false);

    const int w = ui->Opponent->width();
    const int h = ui->Opponent->height();
    //player and Opponent share the same width and height

    ui->Player->setPixmap(paper.scaled(w,h,Qt::KeepAspectRatio));
    ui->Player->setVisible(true);

    srand(time(NULL));
    auto choice_of_opponent = rand() % 3;

    switch(choice_of_opponent)
    {
    case 0:
        ui->Opponent->setPixmap(rock.scaled(w,h,Qt::KeepAspectRatio));
        win->start(2000);
        break;

    case 1:
        ui->Opponent->setPixmap(scissors.scaled(w,h,Qt::KeepAspectRatio));
        lose->start(2000);
        break;

    case 2:
        ui->Opponent->setPixmap(paper.scaled(w,h,Qt::KeepAspectRatio));
        tie->start(2000);
        break;

    }
}

void Rock_Scissors_Paper::win_event()
{
    ui->Opponent->setVisible(false);
    ui->Player->setVisible(false);

    ui->label_2->setText("와 이겼다~\n상금으로 500원을 드립니다!");

    for(int i = 0; i<5; i++)
        emit moneyChange();

    const int w = ui->label_3->width();
    const int h = ui->label_3->height();
    ui->label_3->setPixmap(win_image.scaled(w,h,Qt::KeepAspectRatio));

    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);

    ui->Retry_Button->setText("다시 할래!");
    ui->Get_out_Button->setText("나갈래");

    ui->Retry_Button->setVisible(true);
    ui->Get_out_Button->setVisible(true);

}

void Rock_Scissors_Paper::lose_event()
{
    ui->Opponent->setVisible(false);
    ui->Player->setVisible(false);

    ui->label_2->setText("좌절하지 마시고\n다음에 다시 도전해주세요!");
    const int w = ui->label_3->width();
    const int h = ui->label_3->height();
    ui->label_3->setPixmap(lose_image.scaled(w,h,Qt::KeepAspectRatio));

    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);

    ui->Retry_Button->setText("다시 할래!");
    ui->Get_out_Button->setText("나갈래");

    ui->Retry_Button->setVisible(true);
    ui->Get_out_Button->setVisible(true);


}

void Rock_Scissors_Paper::tie_event()
{
    ui->Opponent->setVisible(false);
    ui->Player->setVisible(false);

    ui->label_2->setText("아쉽게도 비겼네요...");
    const int w = ui->label_3->width();
    const int h = ui->label_3->height();
    ui->label_3->setPixmap(tie_image.scaled(w,h,Qt::KeepAspectRatio));

    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);

    ui->Retry_Button->setText("다시 할래!");
    ui->Get_out_Button->setText("나갈래");

    ui->Retry_Button->setVisible(true);
    ui->Get_out_Button->setVisible(true);
}



void Rock_Scissors_Paper::on_Retry_Button_clicked()
{
    //여기에 피로도 추가해야 함!!!!!!!!!!!
    ui->Retry_Button->setVisible(false);
    ui->Get_out_Button->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->Opponent->setVisible(true);

    ui->ProgressButton->setVisible(false);

    ui->Rock->setVisible(true);
    ui->Scissors->setVisible(true);
    ui->Paper->setVisible(true);

    ui->Choose->setVisible(true);


    timer->start(0);
}

void Rock_Scissors_Paper::on_Get_out_Button_clicked()
{
    this->close();
}
