#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "market.h"
#include "ui_market.h"

using namespace std;

market::market(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::market)
{
    ui->setupUi(this);
    //fin.open(file_path);
}

market::~market()
{
    //fin.close();
    delete ui;
}

void market::set_money(int money)
{
    // Called by game_window or inventroy widget
    user_money = money;
    stringstream s;
    s<<user_money;
    ui->money->setText(QString::fromStdString(s.str()));
}


void market::on_back_button_clicked()
{
    this->close();
}


/* buy buttoon clicked */
void market::on_buy_cold_medicine_clicked()
{
    Item cold_medicine(1, "감기약", {0, 0, 0, 0}, 500);

    emit buyItem(cold_medicine, "'감기약'을 구입했다!");
}


void market::on_buy_peptic_clicked()
{
    Item peptic(2, "소화제", {0, 0, 0, 0}, 500);

    emit buyItem(peptic, "'소화제'을 구입했다!");
}

void market::on_buy_vita500_clicked()
{
    Item vita500(3, "비타500", {0, 0, 0, 0}, 500);

    emit buyItem(vita500, "'비타500'을 구입했다!");
}

void market::on_buy_sleeping_pill_clicked()
{
    Item sleeping_pill(4, "수면제", {0, 0, 0, 0}, 500);

    emit buyItem(sleeping_pill, "'수면제'를 구입했다!");
}

void market::on_buy_bicycle_clicked()
{
    Item bicycle(11, "자전거", {0, 100, 0, -50}, 1000);

    emit buyItem(bicycle, "'자전거'를 구입했다!");
}

void market::on_buy_clover_clicked()
{
    Item clover(13, "네잎클로버", {0, -50, 0, 100}, 1000);

    emit buyItem(clover, "'네잎클로버'를 구입했다!");
}

void market::on_buy_effort_clicked()
{
    Item effort(12, "노오력", {-50, 0, 100, 0}, 1000);

    emit buyItem(effort, "'노오력'을 구입했다!");
}

void market::on_buy_ginseng_clicked()
{
    Item ginseng(10, "홍삼", {100, 0, -50, 0}, 1000);

    emit buyItem(ginseng, "'홍삼'을 구입했다!");
}

void market::on_buy_Lotto_clicked()
{
    Item Lotto(23, "로또", {200, -100, 0, 300}, 2000);

    emit buyItem(Lotto, "'로또'를 구입했다!");
}

void market::on_buy_airplane_clicked()
{
    Item airplane(21, "비행기", {0, 300, 200, -100}, 2000);

    emit buyItem(airplane, "'비행기'를 구입했다!");
}

void market::on_buy_calculus_clicked()
{
    Item calculus(22, "전공서적", {-100, 0, 300, 200}, 2000);

    emit buyItem(calculus, "'전공서적'을 구입했다!");
}

void market::on_buy_steriod_clicked()
{
    Item steriod(20, "스테로이드", {300, 200, -100, 0}, 2000);

    emit buyItem(steriod, "'스테로이드'를 구입했다!");
}

void market::on_buy_honorP_clicked()
{
    Item honorP(30, "명예P훈장", {500, 500, 500, 500}, 10000);

    emit buyItem(honorP, "'명예P훈장'를 구입했다!");
}
