#ifndef MARKET_H
#define MARKET_H

#include <QWidget>
#include <QString>


#include <string>
#include <fstream>

#include "include/model/ability_point.h"
#include "include/model/item.h"

using namespace std;

namespace Ui {
class market;
}

class market : public QWidget
{
    Q_OBJECT

public:
    explicit market(QWidget *parent = nullptr);
    ~market();

    void set_money(int money);

    Item searchItem(int itemNum);

signals:
    void buyItem(Item item);

private slots:
    void on_back_button_clicked();

    void on_buy_cold_medicine_clicked();

    void on_buy_peptic_clicked();

    void on_buy_vita500_clicked();

    void on_buy_sleeping_pill_clicked();

    void on_buy_bicycle_clicked();

    void on_buy_clover_clicked();

    void on_buy_effort_clicked();

    void on_buy_ginseng_clicked();

    void on_buy_Lotto_clicked();

    void on_buy_airplane_clicked();

    void on_buy_calculus_clicked();

    void on_buy_steriod_clicked();

    void on_buy_honorP_clicked();

private:
    Ui::market *ui;


    string file_path = "item_info.txt";
    ifstream fin;

    int user_money = 0;
};

#endif // MARKET_H
