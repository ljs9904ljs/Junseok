/********************************************************************************
** Form generated from reading UI file 'game_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_WINDOW_H
#define UI_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game_window
{
public:
    QPushButton *quit_button;
    QPushButton *save_button;
    QWidget *meesage;
    QLabel *label_7;
    QPushButton *market;
    QPushButton *mini_game;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *stat;
    QLabel *STR;
    QLabel *DEX;
    QLabel *INT;
    QLabel *LUX;
    QPushButton *inventory;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_8;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *stat_2;
    QLabel *STR_2;
    QLabel *DEX_2;
    QLabel *INT_2;
    QLabel *LUX_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *Game_window)
    {
        if (Game_window->objectName().isEmpty())
            Game_window->setObjectName(QString::fromUtf8("Game_window"));
        Game_window->resize(659, 415);
        quit_button = new QPushButton(Game_window);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        quit_button->setGeometry(QRect(550, 10, 80, 31));
        save_button = new QPushButton(Game_window);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(420, 10, 81, 31));
        meesage = new QWidget(Game_window);
        meesage->setObjectName(QString::fromUtf8("meesage"));
        meesage->setGeometry(QRect(30, 280, 401, 101));
        label_7 = new QLabel(meesage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 40, 161, 51));
        label_7->setAlignment(Qt::AlignCenter);
        market = new QPushButton(Game_window);
        market->setObjectName(QString::fromUtf8("market"));
        market->setGeometry(QRect(10, 10, 81, 31));
        mini_game = new QPushButton(Game_window);
        mini_game->setObjectName(QString::fromUtf8("mini_game"));
        mini_game->setGeometry(QRect(270, 10, 81, 31));
        label = new QLabel(Game_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 70, 171, 191));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 210, 251);"));
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(Game_window);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 70, 41, 191));
        stat = new QVBoxLayout(verticalLayoutWidget);
        stat->setObjectName(QString::fromUtf8("stat"));
        stat->setContentsMargins(0, 0, 0, 0);
        STR = new QLabel(verticalLayoutWidget);
        STR->setObjectName(QString::fromUtf8("STR"));

        stat->addWidget(STR);

        DEX = new QLabel(verticalLayoutWidget);
        DEX->setObjectName(QString::fromUtf8("DEX"));

        stat->addWidget(DEX);

        INT = new QLabel(verticalLayoutWidget);
        INT->setObjectName(QString::fromUtf8("INT"));

        stat->addWidget(INT);

        LUX = new QLabel(verticalLayoutWidget);
        LUX->setObjectName(QString::fromUtf8("LUX"));

        stat->addWidget(LUX);

        inventory = new QPushButton(Game_window);
        inventory->setObjectName(QString::fromUtf8("inventory"));
        inventory->setGeometry(QRect(140, 10, 81, 31));
        verticalLayoutWidget_2 = new QWidget(Game_window);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(480, 70, 51, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        pushButton_8 = new QPushButton(Game_window);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(480, 250, 101, 31));
        layoutWidget = new QWidget(Game_window);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(420, 290, 231, 111));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

        verticalLayoutWidget_3 = new QWidget(Game_window);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(70, 70, 41, 191));
        stat_2 = new QVBoxLayout(verticalLayoutWidget_3);
        stat_2->setObjectName(QString::fromUtf8("stat_2"));
        stat_2->setContentsMargins(0, 0, 0, 0);
        STR_2 = new QLabel(verticalLayoutWidget_3);
        STR_2->setObjectName(QString::fromUtf8("STR_2"));

        stat_2->addWidget(STR_2);

        DEX_2 = new QLabel(verticalLayoutWidget_3);
        DEX_2->setObjectName(QString::fromUtf8("DEX_2"));

        stat_2->addWidget(DEX_2);

        INT_2 = new QLabel(verticalLayoutWidget_3);
        INT_2->setObjectName(QString::fromUtf8("INT_2"));

        stat_2->addWidget(INT_2);

        LUX_2 = new QLabel(verticalLayoutWidget_3);
        LUX_2->setObjectName(QString::fromUtf8("LUX_2"));

        stat_2->addWidget(LUX_2);

        verticalLayoutWidget_4 = new QWidget(Game_window);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(540, 70, 51, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_8 = new QLabel(verticalLayoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);


        retranslateUi(Game_window);

        QMetaObject::connectSlotsByName(Game_window);
    } // setupUi

    void retranslateUi(QWidget *Game_window)
    {
        Game_window->setWindowTitle(QApplication::translate("Game_window", "Form", nullptr));
        quit_button->setText(QString());
        save_button->setText(QString());
        label_7->setText(QApplication::translate("Game_window", "Message box", nullptr));
        market->setText(QString());
        mini_game->setText(QString());
        label->setText(QApplication::translate("Game_window", "pet_image", nullptr));
        STR->setText(QApplication::translate("Game_window", "STR", nullptr));
        DEX->setText(QApplication::translate("Game_window", "DEX", nullptr));
        INT->setText(QApplication::translate("Game_window", "INT", nullptr));
        LUX->setText(QApplication::translate("Game_window", "LUX", nullptr));
        inventory->setText(QString());
        label_5->setText(QApplication::translate("Game_window", "\354\203\201\355\203\234", nullptr));
        label_4->setText(QApplication::translate("Game_window", "\353\202\240\354\247\234", nullptr));
        label_2->setText(QApplication::translate("Game_window", "\355\224\274\353\241\234\353\217\204", nullptr));
        label_3->setText(QApplication::translate("Game_window", "\353\217\210", nullptr));
        pushButton_8->setText(QString());
        pushButton_7->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        STR_2->setText(QApplication::translate("Game_window", "STR", nullptr));
        DEX_2->setText(QApplication::translate("Game_window", "DEX", nullptr));
        INT_2->setText(QApplication::translate("Game_window", "INT", nullptr));
        LUX_2->setText(QApplication::translate("Game_window", "LUX", nullptr));
        label_6->setText(QApplication::translate("Game_window", "\354\203\201\355\203\234", nullptr));
        label_8->setText(QApplication::translate("Game_window", "\353\202\240\354\247\234", nullptr));
        label_9->setText(QApplication::translate("Game_window", "\355\224\274\353\241\234\353\217\204", nullptr));
        label_10->setText(QApplication::translate("Game_window", "\353\217\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game_window: public Ui_Game_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_WINDOW_H
