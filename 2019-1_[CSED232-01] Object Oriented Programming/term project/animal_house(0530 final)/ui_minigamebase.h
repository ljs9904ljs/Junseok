/********************************************************************************
** Form generated from reading UI file 'minigamebase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIGAMEBASE_H
#define UI_MINIGAMEBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniGameBase
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *MiniGame_1;
    QPushButton *MiniGame_2;
    QPushButton *MiniGame_3;
    QPushButton *Albeit;
    QPushButton *GoBack;

    void setupUi(QWidget *MiniGameBase)
    {
        if (MiniGameBase->objectName().isEmpty())
            MiniGameBase->setObjectName(QString::fromUtf8("MiniGameBase"));
        MiniGameBase->resize(400, 300);
        verticalLayout = new QVBoxLayout(MiniGameBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MiniGame_1 = new QPushButton(MiniGameBase);
        MiniGame_1->setObjectName(QString::fromUtf8("MiniGame_1"));

        verticalLayout->addWidget(MiniGame_1);

        MiniGame_2 = new QPushButton(MiniGameBase);
        MiniGame_2->setObjectName(QString::fromUtf8("MiniGame_2"));

        verticalLayout->addWidget(MiniGame_2);

        MiniGame_3 = new QPushButton(MiniGameBase);
        MiniGame_3->setObjectName(QString::fromUtf8("MiniGame_3"));

        verticalLayout->addWidget(MiniGame_3);

        Albeit = new QPushButton(MiniGameBase);
        Albeit->setObjectName(QString::fromUtf8("Albeit"));

        verticalLayout->addWidget(Albeit);

        GoBack = new QPushButton(MiniGameBase);
        GoBack->setObjectName(QString::fromUtf8("GoBack"));

        verticalLayout->addWidget(GoBack);


        retranslateUi(MiniGameBase);

        QMetaObject::connectSlotsByName(MiniGameBase);
    } // setupUi

    void retranslateUi(QWidget *MiniGameBase)
    {
        MiniGameBase->setWindowTitle(QApplication::translate("MiniGameBase", "Form", nullptr));
        MiniGame_1->setText(QApplication::translate("MiniGameBase", "\354\212\244\355\224\274\353\223\234 \355\200\264\354\246\210", nullptr));
        MiniGame_2->setText(QApplication::translate("MiniGameBase", "\352\260\200\354\234\204\353\260\224\354\234\204\353\263\264", nullptr));
        MiniGame_3->setText(QApplication::translate("MiniGameBase", "\353\217\214\353\246\274\355\214\220", nullptr));
        Albeit->setText(QApplication::translate("MiniGameBase", "\354\225\204\353\245\264\353\260\224\354\235\264\355\212\270", nullptr));
        GoBack->setText(QApplication::translate("MiniGameBase", "\353\222\244\353\241\234 \352\260\200\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiniGameBase: public Ui_MiniGameBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIGAMEBASE_H
