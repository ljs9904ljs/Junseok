/********************************************************************************
** Form generated from reading UI file 'roulette.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROULETTE_H
#define UI_ROULETTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roulette
{
public:
    QPushButton *Stop;
    QLabel *label;
    QLabel *image;
    QLabel *image_text;
    QPushButton *Retry_Button;
    QPushButton *Get_Out_Button;

    void setupUi(QWidget *roulette)
    {
        if (roulette->objectName().isEmpty())
            roulette->setObjectName(QString::fromUtf8("roulette"));
        roulette->resize(800, 850);
        Stop = new QPushButton(roulette);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        Stop->setGeometry(QRect(300, 750, 201, 51));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        Stop->setFont(font);
        label = new QLabel(roulette);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 700, 700));
        image = new QLabel(roulette);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(150, 50, 500, 500));
        image_text = new QLabel(roulette);
        image_text->setObjectName(QString::fromUtf8("image_text"));
        image_text->setGeometry(QRect(150, 570, 500, 91));
        image_text->setAlignment(Qt::AlignCenter);
        Retry_Button = new QPushButton(roulette);
        Retry_Button->setObjectName(QString::fromUtf8("Retry_Button"));
        Retry_Button->setGeometry(QRect(440, 670, 201, 51));
        Retry_Button->setFont(font);
        Get_Out_Button = new QPushButton(roulette);
        Get_Out_Button->setObjectName(QString::fromUtf8("Get_Out_Button"));
        Get_Out_Button->setGeometry(QRect(160, 670, 201, 51));
        Get_Out_Button->setFont(font);

        retranslateUi(roulette);

        QMetaObject::connectSlotsByName(roulette);
    } // setupUi

    void retranslateUi(QWidget *roulette)
    {
        roulette->setWindowTitle(QApplication::translate("roulette", "Form", nullptr));
        Stop->setText(QApplication::translate("roulette", "\353\251\210\354\266\260!", nullptr));
        label->setText(QString());
        image->setText(QString());
        image_text->setText(QString());
        Retry_Button->setText(QApplication::translate("roulette", "\353\213\244\354\213\234 \355\225\240\353\236\230!", nullptr));
        Get_Out_Button->setText(QApplication::translate("roulette", "\353\202\230\352\260\210\353\236\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roulette: public Ui_roulette {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROULETTE_H
