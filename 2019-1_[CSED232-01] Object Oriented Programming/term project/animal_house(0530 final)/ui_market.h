/********************************************************************************
** Form generated from reading UI file 'market.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKET_H
#define UI_MARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_market
{
public:
    QPushButton *back_button;
    QLabel *money;
    QTabWidget *tabWidget;
    QWidget *status_tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *cold_medicine;
    QLabel *label_5;
    QPushButton *buy_cold_medicine;
    QLabel *label_6;
    QFrame *peptic;
    QLabel *label_11;
    QPushButton *buy_peptic;
    QLabel *label_12;
    QFrame *Vita500;
    QLabel *label_9;
    QPushButton *buy_vita500;
    QLabel *label_10;
    QFrame *sleeping_pill;
    QLabel *label_7;
    QPushButton *buy_sleeping_pill;
    QLabel *label_8;
    QWidget *Stat2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *ginseng;
    QLabel *label_13;
    QPushButton *buy_ginseng;
    QLabel *label_14;
    QFrame *bicycle;
    QLabel *label_15;
    QPushButton *buy_bicycle;
    QLabel *label_16;
    QFrame *effort;
    QLabel *label_17;
    QPushButton *buy_effort;
    QLabel *label_18;
    QFrame *clover;
    QLabel *label_19;
    QPushButton *buy_clover;
    QLabel *label_20;
    QWidget *stat2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QFrame *steroid;
    QLabel *label_21;
    QPushButton *buy_steriod;
    QLabel *label_22;
    QFrame *airplane;
    QLabel *label_23;
    QPushButton *buy_airplane;
    QLabel *label_24;
    QFrame *calculus;
    QLabel *label_25;
    QPushButton *buy_calculus;
    QLabel *label_26;
    QFrame *Lotto;
    QLabel *label_27;
    QPushButton *buy_Lotto;
    QLabel *label_28;
    QWidget *special;
    QFrame *honorP;
    QLabel *label_29;
    QPushButton *buy_honorP;
    QLabel *label_30;
    QLabel *label;
    QLabel *money_2;

    void setupUi(QWidget *market)
    {
        if (market->objectName().isEmpty())
            market->setObjectName(QString::fromUtf8("market"));
        market->resize(579, 809);
        market->setStyleSheet(QString::fromUtf8(""));
        back_button = new QPushButton(market);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(430, 10, 111, 41));
        money = new QLabel(market);
        money->setObjectName(QString::fromUtf8("money"));
        money->setGeometry(QRect(60, 20, 81, 31));
        money->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 198, 255);"));
        money->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(market);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 60, 621, 741));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(30, 16));
        tabWidget->setDocumentMode(true);
        status_tab = new QWidget();
        status_tab->setObjectName(QString::fromUtf8("status_tab"));
        verticalLayoutWidget = new QWidget(status_tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 551, 711));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cold_medicine = new QFrame(verticalLayoutWidget);
        cold_medicine->setObjectName(QString::fromUtf8("cold_medicine"));
        cold_medicine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        cold_medicine->setFrameShape(QFrame::StyledPanel);
        cold_medicine->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(cold_medicine);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 0, 231, 118));
        label_5->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_cold_medicine = new QPushButton(cold_medicine);
        buy_cold_medicine->setObjectName(QString::fromUtf8("buy_cold_medicine"));
        buy_cold_medicine->setGeometry(QRect(450, 60, 51, 41));
        buy_cold_medicine->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_6 = new QLabel(cold_medicine);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 10, 151, 131));
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/ColdMedicine.png);\n"
"border-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(cold_medicine);

        peptic = new QFrame(verticalLayoutWidget);
        peptic->setObjectName(QString::fromUtf8("peptic"));
        peptic->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        peptic->setFrameShape(QFrame::StyledPanel);
        peptic->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(peptic);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(180, 0, 251, 118));
        label_11->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_peptic = new QPushButton(peptic);
        buy_peptic->setObjectName(QString::fromUtf8("buy_peptic"));
        buy_peptic->setGeometry(QRect(450, 60, 51, 41));
        buy_peptic->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_12 = new QLabel(peptic);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 10, 151, 131));
        label_12->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-image: url(:/item/image/item/Peptic.png);"));

        verticalLayout->addWidget(peptic);

        Vita500 = new QFrame(verticalLayoutWidget);
        Vita500->setObjectName(QString::fromUtf8("Vita500"));
        Vita500->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        Vita500->setFrameShape(QFrame::StyledPanel);
        Vita500->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(Vita500);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(180, 0, 221, 118));
        label_9->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_vita500 = new QPushButton(Vita500);
        buy_vita500->setObjectName(QString::fromUtf8("buy_vita500"));
        buy_vita500->setGeometry(QRect(450, 70, 51, 41));
        buy_vita500->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_10 = new QLabel(Vita500);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 10, 151, 131));
        label_10->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-image: url(:/item/image/item/Vita500.png);"));

        verticalLayout->addWidget(Vita500);

        sleeping_pill = new QFrame(verticalLayoutWidget);
        sleeping_pill->setObjectName(QString::fromUtf8("sleeping_pill"));
        sleeping_pill->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        sleeping_pill->setFrameShape(QFrame::StyledPanel);
        sleeping_pill->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(sleeping_pill);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 10, 221, 118));
        label_7->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_sleeping_pill = new QPushButton(sleeping_pill);
        buy_sleeping_pill->setObjectName(QString::fromUtf8("buy_sleeping_pill"));
        buy_sleeping_pill->setGeometry(QRect(450, 60, 51, 41));
        buy_sleeping_pill->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_8 = new QLabel(sleeping_pill);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 10, 151, 131));
        label_8->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-image: url(:/item/image/item/SleepingPill.png);"));

        verticalLayout->addWidget(sleeping_pill);

        tabWidget->addTab(status_tab, QString());
        Stat2 = new QWidget();
        Stat2->setObjectName(QString::fromUtf8("Stat2"));
        verticalLayoutWidget_3 = new QWidget(Stat2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 541, 701));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ginseng = new QFrame(verticalLayoutWidget_3);
        ginseng->setObjectName(QString::fromUtf8("ginseng"));
        ginseng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        ginseng->setFrameShape(QFrame::StyledPanel);
        ginseng->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(ginseng);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(180, 0, 281, 118));
        label_13->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_ginseng = new QPushButton(ginseng);
        buy_ginseng->setObjectName(QString::fromUtf8("buy_ginseng"));
        buy_ginseng->setGeometry(QRect(470, 50, 51, 41));
        buy_ginseng->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_14 = new QLabel(ginseng);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 10, 151, 131));
        label_14->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Ginseng.png);"));

        verticalLayout_3->addWidget(ginseng);

        bicycle = new QFrame(verticalLayoutWidget_3);
        bicycle->setObjectName(QString::fromUtf8("bicycle"));
        bicycle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        bicycle->setFrameShape(QFrame::StyledPanel);
        bicycle->setFrameShadow(QFrame::Raised);
        label_15 = new QLabel(bicycle);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 10, 261, 118));
        label_15->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_bicycle = new QPushButton(bicycle);
        buy_bicycle->setObjectName(QString::fromUtf8("buy_bicycle"));
        buy_bicycle->setGeometry(QRect(470, 50, 51, 41));
        buy_bicycle->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_16 = new QLabel(bicycle);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 10, 151, 131));
        label_16->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Bicycle.png);"));

        verticalLayout_3->addWidget(bicycle);

        effort = new QFrame(verticalLayoutWidget_3);
        effort->setObjectName(QString::fromUtf8("effort"));
        effort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        effort->setFrameShape(QFrame::StyledPanel);
        effort->setFrameShadow(QFrame::Raised);
        label_17 = new QLabel(effort);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(180, 0, 271, 118));
        label_17->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_effort = new QPushButton(effort);
        buy_effort->setObjectName(QString::fromUtf8("buy_effort"));
        buy_effort->setGeometry(QRect(470, 60, 51, 41));
        buy_effort->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_18 = new QLabel(effort);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 10, 151, 131));
        label_18->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Effort.png);"));

        verticalLayout_3->addWidget(effort);

        clover = new QFrame(verticalLayoutWidget_3);
        clover->setObjectName(QString::fromUtf8("clover"));
        clover->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        clover->setFrameShape(QFrame::StyledPanel);
        clover->setFrameShadow(QFrame::Raised);
        label_19 = new QLabel(clover);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(180, 0, 241, 118));
        label_19->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_clover = new QPushButton(clover);
        buy_clover->setObjectName(QString::fromUtf8("buy_clover"));
        buy_clover->setGeometry(QRect(470, 60, 51, 41));
        buy_clover->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_20 = new QLabel(clover);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 10, 151, 131));
        label_20->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Clover.png);"));

        verticalLayout_3->addWidget(clover);

        tabWidget->addTab(Stat2, QString());
        stat2 = new QWidget();
        stat2->setObjectName(QString::fromUtf8("stat2"));
        verticalLayoutWidget_4 = new QWidget(stat2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 551, 701));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        steroid = new QFrame(verticalLayoutWidget_4);
        steroid->setObjectName(QString::fromUtf8("steroid"));
        steroid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        steroid->setFrameShape(QFrame::StyledPanel);
        steroid->setFrameShadow(QFrame::Raised);
        label_21 = new QLabel(steroid);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(180, 0, 231, 118));
        label_21->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_steriod = new QPushButton(steroid);
        buy_steriod->setObjectName(QString::fromUtf8("buy_steriod"));
        buy_steriod->setGeometry(QRect(470, 50, 51, 41));
        buy_steriod->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_22 = new QLabel(steroid);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 10, 151, 131));
        label_22->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Steroid.png);"));

        verticalLayout_4->addWidget(steroid);

        airplane = new QFrame(verticalLayoutWidget_4);
        airplane->setObjectName(QString::fromUtf8("airplane"));
        airplane->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        airplane->setFrameShape(QFrame::StyledPanel);
        airplane->setFrameShadow(QFrame::Raised);
        label_23 = new QLabel(airplane);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(180, 0, 281, 118));
        label_23->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_airplane = new QPushButton(airplane);
        buy_airplane->setObjectName(QString::fromUtf8("buy_airplane"));
        buy_airplane->setGeometry(QRect(470, 60, 51, 41));
        buy_airplane->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_24 = new QLabel(airplane);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 10, 151, 131));
        label_24->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/AirPlane.png);"));

        verticalLayout_4->addWidget(airplane);

        calculus = new QFrame(verticalLayoutWidget_4);
        calculus->setObjectName(QString::fromUtf8("calculus"));
        calculus->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        calculus->setFrameShape(QFrame::StyledPanel);
        calculus->setFrameShadow(QFrame::Raised);
        label_25 = new QLabel(calculus);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(180, 0, 291, 118));
        label_25->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_calculus = new QPushButton(calculus);
        buy_calculus->setObjectName(QString::fromUtf8("buy_calculus"));
        buy_calculus->setGeometry(QRect(470, 50, 51, 41));
        buy_calculus->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_26 = new QLabel(calculus);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 10, 151, 131));
        label_26->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Calculus.png);"));

        verticalLayout_4->addWidget(calculus);

        Lotto = new QFrame(verticalLayoutWidget_4);
        Lotto->setObjectName(QString::fromUtf8("Lotto"));
        Lotto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        Lotto->setFrameShape(QFrame::StyledPanel);
        Lotto->setFrameShadow(QFrame::Raised);
        label_27 = new QLabel(Lotto);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(180, 0, 291, 118));
        label_27->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_Lotto = new QPushButton(Lotto);
        buy_Lotto->setObjectName(QString::fromUtf8("buy_Lotto"));
        buy_Lotto->setGeometry(QRect(470, 60, 51, 41));
        buy_Lotto->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_28 = new QLabel(Lotto);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 10, 151, 131));
        label_28->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Lotto.png);"));

        verticalLayout_4->addWidget(Lotto);

        tabWidget->addTab(stat2, QString());
        special = new QWidget();
        special->setObjectName(QString::fromUtf8("special"));
        honorP = new QFrame(special);
        honorP->setObjectName(QString::fromUtf8("honorP"));
        honorP->setGeometry(QRect(0, 0, 551, 161));
        honorP->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 253, 235);"));
        honorP->setFrameShape(QFrame::StyledPanel);
        honorP->setFrameShadow(QFrame::Raised);
        label_29 = new QLabel(honorP);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(180, 0, 231, 118));
        label_29->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        buy_honorP = new QPushButton(honorP);
        buy_honorP->setObjectName(QString::fromUtf8("buy_honorP"));
        buy_honorP->setGeometry(QRect(450, 50, 51, 41));
        buy_honorP->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 149, 162);"));
        label_30 = new QLabel(honorP);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 10, 151, 131));
        label_30->setStyleSheet(QString::fromUtf8("border-image: url(:/item/image/item/Decoration.png);"));
        tabWidget->addTab(special, QString());
        label = new QLabel(market);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 171, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 255, 250);"));
        label->setAlignment(Qt::AlignCenter);
        money_2 = new QLabel(market);
        money_2->setObjectName(QString::fromUtf8("money_2"));
        money_2->setGeometry(QRect(30, 20, 41, 31));
        money_2->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 198, 255);"));
        money_2->setAlignment(Qt::AlignCenter);

        retranslateUi(market);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(market);
    } // setupUi

    void retranslateUi(QWidget *market)
    {
        market->setWindowTitle(QApplication::translate("market", "Form", nullptr));
        back_button->setText(QApplication::translate("market", "\354\203\201\354\240\220 \353\202\230\352\260\200\352\270\260", nullptr));
        money->setText(QApplication::translate("market", "money \355\221\234\354\213\234", nullptr));
        label_5->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\352\260\220\352\270\260\354\225\275</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\216\253\354\235\230 \352\260\220\352\270\260\353\245\274 \354\271\230\353\243\214\355\225\230\353\212\224 \354\225\204\354\235\264\355\205\234.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">500\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: \352\260\220\352\270\260 \354\203\201\355\203\234 \354\271\230\354\234\240</span></p></body></html>", nullptr));
        buy_cold_medicine->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_6->setText(QString());
        label_11->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\354\206\214\355\231\224\354\240\234</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\216\253\354\235\230 \353\260\260\355\203\210\353\245\274 \354\271\230\353\243\214\355\225\230\353\212\224 \354\225\204\354\235\264\355\205\234.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">500\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: \353\260\260\355\203\210 \354\203\201\355\203\234 \354\271\230\354\234\240</span></p></body></html>", nullptr));
        buy_peptic->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_12->setText(QString());
        label_9->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\353\271\204\355\203\200500</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\216\253\354\235\230 \353\252\270\354\202\264\353\245\274 \354\271\230\353\243\214\355\225\230\353\212\224 \354\225\204\354\235\264\355\205\234.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">500\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: \353\252\270\354\202\264 \354\203\201\355\203\234 \354\271\230\354\234\240</span></p></body></html>", nullptr));
        buy_vita500->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_10->setText(QString());
        label_7->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\354\210\230\353\251\264\354\240\234</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\216\253\354\235\230 \353\266\210\353\251\264\354\246\235\353\245\274 \354\271\230\353\243\214\355\225\230\353\212\224 \354\225\204\354\235\264\355\205\234.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">500\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: \353\266\210\353\251\264\354\246\235 \354\203\201\355\203\234 \354\271\230\354\234\240</span></p></body></html>", nullptr));
        buy_sleeping_pill->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_8->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(status_tab), QApplication::translate("market", "\354\203\201\355\203\234", nullptr));
        label_13->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\355\231\215\354\202\274</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\225\234\352\265\255\354\235\230 \355\212\271\354\202\260\355\222\210.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\236\230\354\235\264 \353\266\210\353\201\210\353\266\210\353\201\210 \354\206\237\353\212\224 \352\262\203 \352\260\231\353\213\244.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">1000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (100, 0, -50, 0)</span></p></body></html>", nullptr));
        buy_ginseng->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_14->setText(QString());
        label_15->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\354\236\220\354\240\204\352\261\260</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\354\236\220 \354\213\234\354\236\245\354\227\220 \353\271\240\353\245\264\352\262\214 \352\260\210 \354\210\230 \354\236\210\353\212\224 \354\210\230\353\213\250.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">(\353\213\250, \354\262\255\354\225\224 \354\226\270\353\215\225\354\227\220\354\204\240 \354\247\220\354\235\264\353\213\244.)</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">1000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (0. 100. 0, -50)</span></p></body></html>", nullptr));
        buy_bicycle->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_16->setText(QString());
        label_17->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\353\205\270\354\230\244\353\240\245</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\354\262\234\354\236\254\353\212\224 1%\354\235\230 \354\236\254\353\212\245\352\263\274</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">99%\354\235\230 \353\205\270\354\230\244\353\240\245\354\234\274\353\241\234 \354\235\264\353\243\250\354\226\264\354\247\204\353\213\244.</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">1000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (-50, 0, 100, 0)</span></p></body></html>", nullptr));
        buy_effort->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_18->setText(QString());
        label_19->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\353\204\244\354\236\216\355\201\264\353\241\234\353\262\204</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\354\230\244\353\212\230\354\235\200 \354\231\240\354\247\200 \355\226\211\354\232\264\354\235\264...\343\205\216\343\205\216</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222:</span><span style=\" font-size:8pt; font-weight:600;\"> 1000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (0, -50, 0. 100)</span></p></body></html>", nullptr));
        buy_clover->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_20->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Stat2), QApplication::translate("market", "\354\212\244\355\203\257(\352\270\260\353\263\270)", nullptr));
        label_21->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\354\212\244\355\205\214\353\241\234\354\235\264\353\223\234</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\267\274\354\234\241 \352\260\225\355\231\224\354\240\234 (\353\266\200\354\236\221\354\232\251 \354\243\274\354\235\230!!)</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">2000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (300, 200, -100, 0)</span></p></body></html>", nullptr));
        buy_steriod->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_22->setText(QString());
        label_23->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\353\271\204\355\226\211\352\270\260</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\354\240\204 \354\204\270\352\263\204 \354\226\264\353\224\224\353\223\240 \353\271\240\353\245\264\352\262\214 \354\212\235\354\212\235~</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt;\">2000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (0, 300, 200, -100)</span></p></body></html>", nullptr));
        buy_airplane->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_24->setText(QString());
        label_25->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\354\240\204\352\263\265\354\204\234\354\240\201</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\354\241\270\354\227\205\354\235\204 \354\234\204\355\225\264\354\204\240 \353\260\230\353\223\234\354\213\234 \355\225\204\354\232\224\355\225\234 \354\261\205!</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">2000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (-100, 0, 300, 200)</span></p></body></html>", nullptr));
        buy_calculus->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_26->setText(QString());
        label_27->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\353\241\234\353\230\220</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\225\234 \353\262\210\354\235\264\353\235\274\353\217\204 \353\213\271\354\262\250\353\220\230\353\251\264, \353\215\224\354\235\264\354\203\201\354\235\230 \354\206\214\354\233\220\354\235\200 \354\227\206\353\213\244!</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222:</span><span style=\" font-size:8pt; font-weight:600;\"> 2000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (200, -100, 0, 300)</span></p></body></html>", nullptr));
        buy_Lotto->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_28->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(stat2), QApplication::translate("market", "\354\212\244\355\203\257(\352\260\225\355\231\224)", nullptr));
        label_29->setText(QApplication::translate("market", "<html><head/><body><p align=\"justify\"><span style=\" font-size:8pt; font-weight:600;\">\353\252\205\354\230\210P\355\233\210\354\236\245</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\353\252\205\354\230\210\353\241\234\354\232\264 \355\217\254\354\212\244\355\205\214\355\202\244\354\225\210\354\227\220\352\262\214 \354\210\230\354\227\254\353\220\230\353\212\224 \355\233\210\354\236\245</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\352\260\222: </span><span style=\" font-size:8pt; font-weight:600;\">10000\\</span></p><p align=\"justify\"><span style=\" font-size:8pt;\">\355\232\250\352\263\274: (500, 500, 500, 500)</span></p></body></html>", nullptr));
        buy_honorP->setText(QApplication::translate("market", "\352\265\254\354\236\205", nullptr));
        label_30->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(special), QApplication::translate("market", "\355\212\271\354\210\230", nullptr));
        label->setText(QApplication::translate("market", "\354\203\201\354\240\220", nullptr));
        money_2->setText(QApplication::translate("market", "\353\217\210: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class market: public Ui_market {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKET_H
