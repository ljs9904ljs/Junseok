#include "mainwindow.h"
#include <QApplication>
#include<QFontDatabase>

#include <QFontDatabase>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int id = QFontDatabase::addApplicationFont("./Maplestory.ttf");
    QString font = QFontDatabase::applicationFontFamilies(id).at(0);

    QApplication::setFont(font);

    MainWindow w;
    w.show();

    return a.exec();
}
