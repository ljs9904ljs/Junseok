#include <QTableWidget>
#include <QTableWidgetItem>

#include <iostream>

#include "inventory.h"
#include "ui_inventory.h"

#include <QFontDatabase>
#include <QString>

inventory::inventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inventory)
{

    int id = QFontDatabase::addApplicationFont("./Maplestory.ttf");
    QString font = QFontDatabase::applicationFontFamilies(id).at(0);

    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setColumnWidth(1, 60);
    ui->tableWidget->setColumnWidth(2, 60);
    ui->tableWidget->setColumnWidth(3, 60);
    ui->tableWidget->setColumnWidth(4, 60);
    ui->tableWidget->setColumnWidth(5, 60);
    ui->tableWidget->setColumnWidth(6, 100);


    connect(ui->tableWidget, SIGNAL(cellPressed(int, int)), this, SLOT(use_item(int, int)));

    inventory::setFont(font);
}

inventory::~inventory()
{
    ui->tableWidget->clear();
    delete ui;
}

void inventory::set_money(int money)
{
    user_money = money;
    stringstream s;
    s<<user_money;
    ui->money->setText(QString::fromStdString(s.str()));
}

void inventory::claerItemList()
{
    // clear all item list to zero.
}

void inventory::use_item(int row, int col)
{
    //connect with table cell click event
    if(col != 6) return; // didn't clicked 'USE' tab


    // item을 정말로 쓸껀지 확인해보자.

    // Pet (in the Game Window) received index of ItemList
    // And by this index, find the Item to use
    // And update the inventory list.
    int temp = row;

    emit sendItemToPet(temp);
}


void inventory::on_go_back_clicked()
{
    // go to GameWindow
    this->close();
}

void inventory::updateItemList(ItemVector* currentList){

    QTableWidget* table = ui->tableWidget;

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setRowCount(int(currentList->size()));


    for(size_t r = 0; r<currentList->size(); r++){
        // fill the table entry
        QTableWidgetItem *itemName = new QTableWidgetItem;
        itemName->setText(QString::fromStdString((*currentList)[r].first.item_name));
        table->setItem(int(r), 0, itemName);

        QTableWidgetItem *itemSTR = new QTableWidgetItem;
        itemSTR->setText(QString::number((*currentList)[r].first.stat.getSTR()));
        table->setItem(int(r), 1, itemSTR);

        QTableWidgetItem *itemDEX = new QTableWidgetItem;
        itemDEX->setText(QString::number((*currentList)[r].first.stat.getDEX()));
        table->setItem(int(r), 2, itemDEX);

        QTableWidgetItem *itemINT = new QTableWidgetItem;
        itemINT->setText(QString::number((*currentList)[r].first.stat.getINT()));
        table->setItem(int(r), 3, itemINT);

        QTableWidgetItem *itemLUX = new QTableWidgetItem;
        itemLUX->setText(QString::number((*currentList)[r].first.stat.getLUX()));
        table->setItem(int(r), 4, itemLUX);

        QTableWidgetItem *itemEA = new QTableWidgetItem;
        itemEA->setText(QString::number((*currentList)[r].second));
        table->setItem(int(r), 5, itemEA);

        QTableWidgetItem *itemUse = new QTableWidgetItem;
        itemUse->setText("사용하기");
        table->setItem(int(r), 6, itemUse);
    }
}

