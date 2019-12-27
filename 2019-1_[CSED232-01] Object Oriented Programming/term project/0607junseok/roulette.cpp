#include "roulette.h"
#include "ui_roulette.h"
#define PI 3.14159265

#include <iostream>

roulette::roulette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::roulette)
{
    ui->setupUi(this);

    win_image.load("./image/mini_game/win_image.jpg");
    lose_image.load("./image/mini_game/lose_image.jpg");
    tie_image.load("./image/mini_game/tie_image.png");
    start.load("./image/mini_game/roulette.jpg");

    timer = new QTimer;
    game_end = new QTimer;

    connect(game_end, SIGNAL(timeout()), this, SLOT(show_result()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    game_end->setSingleShot(1);
    timer->start(1);

    QFont content( "메이플스토리", 14, QFont::Bold);
    ui->image_text->setFont(content);
    ui->Stop->setFont(content);
    ui->Retry_Button->setFont(content);
    ui->Get_Out_Button->setFont(content);
    ui->Stop->setFont(content);
    ui->label->setFont(content);
    ui->image->setFont(content);
    ui->image_text->setFont(content);
    ui->ProgressButton->setFont(content);

    ui->Retry_Button->setVisible(false);
    ui->Get_Out_Button->setVisible(false);

    /**********************************************************/

    ui->Stop->setVisible(0);
    ui->label->setVisible(1);
    ui->image->setVisible(1);
    ui->image_text->setVisible(1);

    ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 255);");

    const int w = ui->image->width();
    const int h = ui->image->height();

    ui->image->setPixmap(start.scaled(w,h,Qt::KeepAspectRatio));
    ui->image_text->setText("인생은 한 방!\n\n 천원을 노려보세요!");

}

roulette::~roulette()
{
    delete ui;
}

void roulette::show_result()
{
    ui->Stop->setVisible(0);
    ui->Get_Out_Button->setVisible(1);
    ui->Retry_Button->setVisible(1);
    ui->label->setVisible(1);
    ui->image->setVisible(1);
    ui->image_text->setVisible(1);

    ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 255);");
    int real_stop_point;

    if(stop_point >= 720)
        real_stop_point = stop_point - 720;
    else if(stop_point >= 360)
        real_stop_point = stop_point -360;
    else
        real_stop_point = stop_point;

    if(real_stop_point < 30 ||(real_stop_point > 60 && real_stop_point <90)
                            ||(real_stop_point > 120 && real_stop_point <150)
                            ||(real_stop_point > 180 && real_stop_point <210)
                            ||(real_stop_point > 240 && real_stop_point <270)
                            ||(real_stop_point > 300 && real_stop_point <330))
        result = 0;

    if((real_stop_point > 30 && real_stop_point < 60)
    ||(real_stop_point > 150 && real_stop_point <180)
    ||(real_stop_point > 210 && real_stop_point <240)
    ||(real_stop_point > 270 && real_stop_point <300)
    ||(real_stop_point > 330 && real_stop_point <360))
        result = 1;

    if(real_stop_point > 90 && real_stop_point < 120)
        result = 2;

    const int w = ui->image->width();
    const int h = ui->image->height();

    switch(result)
    {
    case 0:
        ui->image->setPixmap(lose_image.scaled(w,h,Qt::KeepAspectRatio));
        ui->image_text->setText("아쉽지만 꽝입니다~");
        break;
    case 1:
        ui->image->setPixmap(tie_image.scaled(w,h,Qt::KeepAspectRatio));
        ui->image_text->setText("500원 당첨!");
        for(int i = 0; i<5; i++)
            emit moneyChange();
        break;
    case 2:
        ui->image->setPixmap(win_image.scaled(w,h,Qt::KeepAspectRatio));
        ui->image_text->setText("1000원 당첨!!!");
        for(int i = 0; i<10; i++)
            emit moneyChange();
        break;

    }
}

void roulette::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    int side = qMin(width(), height());
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 800.0, side / 800.0);
    QTime time = QTime::currentTime();

    static const QPoint minuteHand[3] =
    {
        QPoint(2, 8),
        QPoint(-2, 8),
        QPoint(0, -200)
    };


    QColor minuteColor(255, 127, 127, 191);

    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);
    painter.save();
    painter.rotate(time.msec());
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    /*********************여기까지 돌아가는 바늘***********************/

    QPainter board(this);
    QColor circlecolor(45, 216, 129, 250);
    QColor linecolor(112, 237, 183, 200);
    QColor miss(98,121,184,190);
    QColor good(255,111,89,255);
    QColor best(239,48,84,255);

    QPen pointpen(linecolor);
    pointpen.setWidth(2);
    QPen circlepen(circlecolor);
    circlepen.setWidth(4);
    QPen textpen(miss);
    textpen.setWidth(3);
    QPen textpen_2(good);
    textpen_2.setWidth(3);
    QPen textpen_3(best);
    textpen_3.setWidth(3);
    textpen.setWidth(3);


    board.setRenderHint(QPainter::Antialiasing);

    QPoint center = rect().center();
    QPoint points[12];
        const int radius = 240;
        const int inner_circle = 300;
        const double degree = PI / 180.0;
        board.setPen(circlepen);
        board.drawEllipse(center, inner_circle, inner_circle);

        //Draw line

        board.setPen(pointpen);

        for(int i =0; i<360; i +=30)
        {
            points[i/30].setX(center.x() + 300.0 * cos(static_cast<double>(i) * degree));
            points[i/30].setY(center.y() - 300.0 * sin(static_cast<double>(i) * degree));
        }

        for(int i = 0; i<6; i++)
        {
            board.drawLine(points[i], points[i+6]);
        }

        board.setPen(textpen);

        // Draw semicircle with texts on every 40".
        for (double i = 15.0; i < 375.0; i += 60.0) {
            QPoint p(center.x()-20 + radius * cos(i * PI / 180.0),
                     center.y() - radius * sin(i * PI / 180.0));
            board.drawText(p, "꽝");
        }

        board.setPen(textpen_2);
        for (double i = 45.0; i < 345.0; i += 60.0) {
            QPoint p(center.x()-20 + radius * cos(i * PI / 180.0),
                     center.y() - radius * sin(i * PI / 180.0));
            board.drawText(p, "500원!");

        }

        board.setPen(textpen_3);
        QPoint p(center.x()-20 + radius * cos(345.0 * PI / 180.0),
                 center.y() - radius * sin(345.0 * PI / 180.0));
        board.drawText(p, "1000원!!");





}

void roulette::on_Stop_clicked()
{
   QTime time = QTime::currentTime();
   timer->stop();
   stop_point = time.msec();
   game_end->start(3000);
}


void roulette::on_Retry_Button_clicked()
{
    //피로도 확인!!!!!!
    ui->image->setVisible(false);
    ui->image_text->setVisible(false);
    ui->Retry_Button->setVisible(false);
    ui->Get_Out_Button->setVisible(false);
    ui->label->setVisible(false);
    ui->Stop->setVisible(true);
    timer->start(0);
}

void roulette::on_Get_Out_Button_clicked()
{
    this->close();
}

void roulette::on_ProgressButton_clicked()
{
    ui->image->setVisible(false);
    ui->image_text->setVisible(false);
    ui->Retry_Button->setVisible(false);
    ui->Get_Out_Button->setVisible(false);
    ui->label->setVisible(false);
    ui->Stop->setVisible(true);
    ui->ProgressButton->setVisible(0);
}
