/********************************************************************************
** Form generated from reading UI file 'inventory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORY_H
#define UI_INVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inventory
{
public:
    QLabel *inventory_title;
    QPushButton *go_back;
    QLabel *money;
    QLabel *money_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *inventory)
    {
        if (inventory->objectName().isEmpty())
            inventory->setObjectName(QString::fromUtf8("inventory"));
        inventory->resize(601, 424);
        inventory_title = new QLabel(inventory);
        inventory_title->setObjectName(QString::fromUtf8("inventory_title"));
        inventory_title->setGeometry(QRect(190, 20, 131, 51));
        inventory_title->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 199, 255);"));
        inventory_title->setTextFormat(Qt::AutoText);
        inventory_title->setAlignment(Qt::AlignCenter);
        go_back = new QPushButton(inventory);
        go_back->setObjectName(QString::fromUtf8("go_back"));
        go_back->setGeometry(QRect(500, 10, 91, 51));
        money = new QLabel(inventory);
        money->setObjectName(QString::fromUtf8("money"));
        money->setGeometry(QRect(60, 30, 81, 31));
        money->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 198, 255);"));
        money->setAlignment(Qt::AlignCenter);
        money_3 = new QLabel(inventory);
        money_3->setObjectName(QString::fromUtf8("money_3"));
        money_3->setGeometry(QRect(30, 30, 41, 31));
        money_3->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 198, 255);"));
        money_3->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(inventory);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 80, 581, 311));

        retranslateUi(inventory);

        QMetaObject::connectSlotsByName(inventory);
    } // setupUi

    void retranslateUi(QWidget *inventory)
    {
        inventory->setWindowTitle(QApplication::translate("inventory", "Form", nullptr));
        inventory_title->setText(QApplication::translate("inventory", "\354\235\270\353\262\244\355\206\240\353\246\254", nullptr));
        go_back->setText(QApplication::translate("inventory", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
        money->setText(QApplication::translate("inventory", "money \355\221\234\354\213\234", nullptr));
        money_3->setText(QApplication::translate("inventory", "\353\217\210: ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("inventory", "item Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("inventory", "STR", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("inventory", "DEX", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("inventory", "INT", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("inventory", "LUX", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("inventory", "EA.", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("inventory", "USE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inventory: public Ui_inventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORY_H
