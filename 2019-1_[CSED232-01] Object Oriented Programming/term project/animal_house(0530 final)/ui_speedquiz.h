/********************************************************************************
** Form generated from reading UI file 'speedquiz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEEDQUIZ_H
#define UI_SPEEDQUIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpeedQuiz
{
public:
    QLabel *label;
    QPushButton *progressButton;
    QLabel *label_2;
    QPushButton *Answer_1;
    QPushButton *Answer_2;
    QPushButton *Answer_3;
    QPushButton *Answer_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Answer_1_text;
    QLabel *Answer_2_text;
    QLabel *Answer_3_text;
    QLabel *Answer_4_text;
    QProgressBar *progressBar;
    QPushButton *GameOver;
    QPushButton *Retry;
    QLabel *image;

    void setupUi(QWidget *SpeedQuiz)
    {
        if (SpeedQuiz->objectName().isEmpty())
            SpeedQuiz->setObjectName(QString::fromUtf8("SpeedQuiz"));
        SpeedQuiz->resize(800, 800);
        label = new QLabel(SpeedQuiz);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 20, 461, 61));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        progressButton = new QPushButton(SpeedQuiz);
        progressButton->setObjectName(QString::fromUtf8("progressButton"));
        progressButton->setGeometry(QRect(330, 700, 151, 61));
        label_2 = new QLabel(SpeedQuiz);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 771, 561));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        Answer_1 = new QPushButton(SpeedQuiz);
        Answer_1->setObjectName(QString::fromUtf8("Answer_1"));
        Answer_1->setGeometry(QRect(80, 640, 121, 31));
        Answer_2 = new QPushButton(SpeedQuiz);
        Answer_2->setObjectName(QString::fromUtf8("Answer_2"));
        Answer_2->setGeometry(QRect(250, 640, 121, 31));
        Answer_3 = new QPushButton(SpeedQuiz);
        Answer_3->setObjectName(QString::fromUtf8("Answer_3"));
        Answer_3->setGeometry(QRect(430, 640, 121, 31));
        Answer_4 = new QPushButton(SpeedQuiz);
        Answer_4->setObjectName(QString::fromUtf8("Answer_4"));
        Answer_4->setGeometry(QRect(610, 640, 121, 31));
        layoutWidget = new QWidget(SpeedQuiz);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 220, 671, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Answer_1_text = new QLabel(layoutWidget);
        Answer_1_text->setObjectName(QString::fromUtf8("Answer_1_text"));

        verticalLayout->addWidget(Answer_1_text);

        Answer_2_text = new QLabel(layoutWidget);
        Answer_2_text->setObjectName(QString::fromUtf8("Answer_2_text"));

        verticalLayout->addWidget(Answer_2_text);

        Answer_3_text = new QLabel(layoutWidget);
        Answer_3_text->setObjectName(QString::fromUtf8("Answer_3_text"));

        verticalLayout->addWidget(Answer_3_text);

        Answer_4_text = new QLabel(layoutWidget);
        Answer_4_text->setObjectName(QString::fromUtf8("Answer_4_text"));

        verticalLayout->addWidget(Answer_4_text);

        progressBar = new QProgressBar(SpeedQuiz);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(710, 220, 31, 361));
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        GameOver = new QPushButton(SpeedQuiz);
        GameOver->setObjectName(QString::fromUtf8("GameOver"));
        GameOver->setGeometry(QRect(500, 700, 151, 61));
        Retry = new QPushButton(SpeedQuiz);
        Retry->setObjectName(QString::fromUtf8("Retry"));
        Retry->setGeometry(QRect(160, 700, 151, 61));
        image = new QLabel(SpeedQuiz);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(150, 170, 491, 361));
        image->setAlignment(Qt::AlignCenter);
        progressBar->raise();
        label->raise();
        progressButton->raise();
        label_2->raise();
        Answer_1->raise();
        Answer_2->raise();
        Answer_3->raise();
        Answer_4->raise();
        layoutWidget->raise();
        GameOver->raise();
        Retry->raise();
        image->raise();

        retranslateUi(SpeedQuiz);

        QMetaObject::connectSlotsByName(SpeedQuiz);
    } // setupUi

    void retranslateUi(QWidget *SpeedQuiz)
    {
        SpeedQuiz->setWindowTitle(QApplication::translate("SpeedQuiz", "Form", nullptr));
        label->setText(QApplication::translate("SpeedQuiz", "TextLabel", nullptr));
        progressButton->setText(QApplication::translate("SpeedQuiz", "NEXT", nullptr));
        label_2->setText(QApplication::translate("SpeedQuiz", "TextLabel", nullptr));
        Answer_1->setText(QApplication::translate("SpeedQuiz", "\353\213\265\354\235\200 1\353\262\210!", nullptr));
        Answer_2->setText(QApplication::translate("SpeedQuiz", "\353\213\265\354\235\200 2\353\262\210!", nullptr));
        Answer_3->setText(QApplication::translate("SpeedQuiz", "\353\213\265\354\235\200 3\353\262\210!", nullptr));
        Answer_4->setText(QApplication::translate("SpeedQuiz", "\353\213\265\354\235\200 4\353\262\210!", nullptr));
        Answer_1_text->setText(QApplication::translate("SpeedQuiz", "TextLabel", nullptr));
        Answer_2_text->setText(QApplication::translate("SpeedQuiz", "TextLabel", nullptr));
        Answer_3_text->setText(QApplication::translate("SpeedQuiz", "TextLabel", nullptr));
        Answer_4_text->setText(QApplication::translate("SpeedQuiz", "TextLabel", nullptr));
        GameOver->setText(QApplication::translate("SpeedQuiz", "\353\202\230\352\260\210\353\236\230", nullptr));
        Retry->setText(QApplication::translate("SpeedQuiz", "\353\213\244\354\213\234 \355\225\240\353\236\230!", nullptr));
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SpeedQuiz: public Ui_SpeedQuiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEEDQUIZ_H
