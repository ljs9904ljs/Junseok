#ifndef INVENTORY_H
#define INVENTORY_H

#include <QWidget>
#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTableView>
#include <QString>

#include <iostream>
#include <fstream>
#include <sstream>

#include "market.h"

namespace Ui {
class inventory;
}

class inventory : public QWidget
{
    Q_OBJECT

public:
    explicit inventory(QWidget *parent = nullptr);
    ~inventory();

    void set_money(int money);

    void claerItemList();

private slots:
    void use_item(int, int);
    void on_go_back_clicked();

public slots:
    void updateItemList(ItemVector* current);



signals:
    //void give_item();
    void sendItemToPet(int);

private:
    Ui::inventory *ui;
    int user_money;
};

#endif // INVENTORY_H
