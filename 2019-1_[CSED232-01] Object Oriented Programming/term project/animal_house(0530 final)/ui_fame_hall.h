/********************************************************************************
** Form generated from reading UI file 'fame_hall.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAME_HALL_H
#define UI_FAME_HALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fame_hall
{
public:
    QLabel *label;
    QPushButton *back_button;
    QWidget *gridLayoutWidget;
    QGridLayout *fames_view;

    void setupUi(QWidget *Fame_hall)
    {
        if (Fame_hall->objectName().isEmpty())
            Fame_hall->setObjectName(QString::fromUtf8("Fame_hall"));
        Fame_hall->resize(613, 568);
        label = new QLabel(Fame_hall);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 131, 61));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 228, 255);"));
        label->setAlignment(Qt::AlignCenter);
        back_button = new QPushButton(Fame_hall);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(520, 510, 81, 41));
        gridLayoutWidget = new QWidget(Fame_hall);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 100, 521, 401));
        fames_view = new QGridLayout(gridLayoutWidget);
        fames_view->setObjectName(QString::fromUtf8("fames_view"));
        fames_view->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Fame_hall);

        QMetaObject::connectSlotsByName(Fame_hall);
    } // setupUi

    void retranslateUi(QWidget *Fame_hall)
    {
        Fame_hall->setWindowTitle(QApplication::translate("Fame_hall", "Form", nullptr));
        label->setText(QApplication::translate("Fame_hall", "\353\252\205\354\230\210\354\235\230 \354\240\204\353\213\271", nullptr));
        back_button->setText(QApplication::translate("Fame_hall", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fame_hall: public Ui_Fame_hall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAME_HALL_H
