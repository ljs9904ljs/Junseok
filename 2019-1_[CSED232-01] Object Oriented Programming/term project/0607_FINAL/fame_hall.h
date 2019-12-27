#ifndef FAME_HALL_H
#define FAME_HALL_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>

#include "include/model/ability_point.h"

using namespace std;

namespace Ui {
class Fame_hall;
}

struct Fame_info{
    // 명예 전당에 출력할 정보를 가지는 구조체
    int Pet_num;
    Ability_point Stat;
    int play_time;

    Fame_info(int _num, Ability_point _stat, int _time){
        Pet_num = _num; Stat = _stat; play_time = _time;
    }
    Fame_info(const Fame_info& _fame){
        Pet_num = _fame.Pet_num;
        Stat = _fame.Stat; play_time = _fame.play_time;
    }

};

class Fame_hall : public QWidget
{
    Q_OBJECT

public:
    explicit Fame_hall(QWidget *parent = nullptr);
    ~Fame_hall();

    void showFames();

private slots:
    void on_back_button_clicked();
    void loadFames();

signals:
    void goToMainWindow();


private:
    Ui::Fame_hall *ui;
    vector<Fame_info> FameVector;

};

#endif
