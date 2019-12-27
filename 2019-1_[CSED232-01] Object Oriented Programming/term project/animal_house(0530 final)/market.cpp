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
    fin.open(file_path);

}

market::~market()
{
    fin.close();
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

/*Item market::searchItem(int itemNum)
{
    while(fin.peek() != EOF){
        string temp;
        string token[7];
        getline(fin, temp);
        stringstream s(temp);
        int i=0;
        while(s >> token[i]){
            cout<<token[i]<<endl;
            i++;
        }
        if(!token[i].compare(to_string(itemNum))) break;
    }

    Item item;
}*/


void market::on_back_button_clicked()
{
    this->close();
}


/* buy buttoon clicked */
void market::on_buy_cold_medicine_clicked()
{
    Item cold_medicine(1, "감기약", {0, 0, 0, 0}, 500);
    // cout하면 Application 창에서 한글이 깨져서 나오긴 하네...

    emit buyItem(cold_medicine);
}


void market::on_buy_peptic_clicked()
{
    Item peptic(2, "소화제", {0, 0, 0, 0}, 500);

    emit buyItem(peptic);
}

void market::on_buy_vita500_clicked()
{
    Item vita500(3, "비타500", {0, 0, 0, 0}, 500);

    emit buyItem(vita500);
}

void market::on_buy_sleeping_pill_clicked()
{
    Item sleeping_pill(4, "수면제", {0, 0, 0, 0}, 500);

    emit buyItem(sleeping_pill);
}

void market::on_buy_bicycle_clicked()
{
    Item bicycle(11, "자전거", {0, 100, 0, -50}, 1000);

    emit buyItem(bicycle);
}

void market::on_buy_clover_clicked()
{
    Item clover(13, "네잎클로버", {0, -50, 0, 100}, 1000);

    emit buyItem(clover);
}

void market::on_buy_effort_clicked()
{
    Item effort(12, "노오력", {-50, 0, 100, 0}, 1000);

    emit buyItem(effort);
}

void market::on_buy_ginseng_clicked()
{
    Item ginseng(10, "홍삼", {100, 0, -50, 0}, 1000);

    emit buyItem(ginseng);
}

void market::on_buy_Lotto_clicked()
{
    Item Lotto(24, "로또", {200, -100, 0, 300}, 2000);

    emit buyItem(Lotto);
}

void market::on_buy_airplane_clicked()
{
    Item airplane(22, "비행기", {0, 300, 200, -100}, 2000);

    emit buyItem(airplane);
}

void market::on_buy_calculus_clicked()
{
    Item calculus(23, "전공서적", {-100, 0, 300, 200}, 2000);

    emit buyItem(calculus);
}

void market::on_buy_steriod_clicked()
{
    Item steriod(21, "스테로이드", {300, 200, -100, 0}, 2000);

    emit buyItem(steriod);
}

void market::on_buy_honorP_clicked()
{
    Item honorP(30, "명예P훈장", {500, 500, 500, 500}, 10000);

    emit buyItem(honorP);
}
