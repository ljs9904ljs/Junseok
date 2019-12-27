/********************************************************************************
** Form generated from reading UI file 'rock_scissors_paper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROCK_SCISSORS_PAPER_H
#define UI_ROCK_SCISSORS_PAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rock_Scissors_Paper
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *ProgressButton;
    QLabel *Opponent;
    QPushButton *Rock;
    QPushButton *Scissors;
    QPushButton *Paper;
    QLabel *Choose;
    QLabel *Player;
    QPushButton *Retry_Button;
    QPushButton *Get_out_Button;

    void setupUi(QWidget *Rock_Scissors_Paper)
    {
        if (Rock_Scissors_Paper->objectName().isEmpty())
            Rock_Scissors_Paper->setObjectName(QString::fromUtf8("Rock_Scissors_Paper"));
        Rock_Scissors_Paper->resize(600, 800);
        label = new QLabel(Rock_Scissors_Paper);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 491, 51));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Rock_Scissors_Paper);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 80, 421, 61));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Rock_Scissors_Paper);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 170, 561, 431));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_3->setAlignment(Qt::AlignCenter);
        ProgressButton = new QPushButton(Rock_Scissors_Paper);
        ProgressButton->setObjectName(QString::fromUtf8("ProgressButton"));
        ProgressButton->setGeometry(QRect(210, 670, 181, 61));
        Opponent = new QLabel(Rock_Scissors_Paper);
        Opponent->setObjectName(QString::fromUtf8("Opponent"));
        Opponent->setGeometry(QRect(170, 80, 241, 221));
        Opponent->setAlignment(Qt::AlignCenter);
        Rock = new QPushButton(Rock_Scissors_Paper);
        Rock->setObjectName(QString::fromUtf8("Rock"));
        Rock->setGeometry(QRect(20, 590, 171, 161));
        Scissors = new QPushButton(Rock_Scissors_Paper);
        Scissors->setObjectName(QString::fromUtf8("Scissors"));
        Scissors->setGeometry(QRect(210, 590, 171, 161));
        Paper = new QPushButton(Rock_Scissors_Paper);
        Paper->setObjectName(QString::fromUtf8("Paper"));
        Paper->setGeometry(QRect(400, 590, 171, 161));
        Choose = new QLabel(Rock_Scissors_Paper);
        Choose->setObjectName(QString::fromUtf8("Choose"));
        Choose->setGeometry(QRect(90, 280, 431, 171));
        Choose->setAlignment(Qt::AlignCenter);
        Player = new QLabel(Rock_Scissors_Paper);
        Player->setObjectName(QString::fromUtf8("Player"));
        Player->setGeometry(QRect(170, 430, 241, 221));
        Player->setAlignment(Qt::AlignCenter);
        Retry_Button = new QPushButton(Rock_Scissors_Paper);
        Retry_Button->setObjectName(QString::fromUtf8("Retry_Button"));
        Retry_Button->setGeometry(QRect(70, 680, 181, 61));
        Get_out_Button = new QPushButton(Rock_Scissors_Paper);
        Get_out_Button->setObjectName(QString::fromUtf8("Get_out_Button"));
        Get_out_Button->setGeometry(QRect(340, 680, 181, 61));

        retranslateUi(Rock_Scissors_Paper);

        QMetaObject::connectSlotsByName(Rock_Scissors_Paper);
    } // setupUi

    void retranslateUi(QWidget *Rock_Scissors_Paper)
    {
        Rock_Scissors_Paper->setWindowTitle(QApplication::translate("Rock_Scissors_Paper", "Form", nullptr));
        label->setText(QApplication::translate("Rock_Scissors_Paper", "\352\260\200\354\234\204\353\260\224\354\234\204\353\263\264\354\227\220 \354\230\244\354\213\240 \352\262\203\354\235\204 \355\231\230\354\230\201\355\225\251\353\213\210\353\213\244!!", nullptr));
        label_2->setText(QApplication::translate("Rock_Scissors_Paper", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("Rock_Scissors_Paper", "TextLabel", nullptr));
        ProgressButton->setText(QApplication::translate("Rock_Scissors_Paper", "\354\213\234\354\236\221\355\225\230\352\270\260", nullptr));
        Opponent->setText(QString());
        Rock->setText(QString());
        Scissors->setText(QString());
        Paper->setText(QString());
        Choose->setText(QApplication::translate("Rock_Scissors_Paper", "TextLabel", nullptr));
        Player->setText(QString());
        Retry_Button->setText(QApplication::translate("Rock_Scissors_Paper", "PushButton", nullptr));
        Get_out_Button->setText(QApplication::translate("Rock_Scissors_Paper", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rock_Scissors_Paper: public Ui_Rock_Scissors_Paper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROCK_SCISSORS_PAPER_H
