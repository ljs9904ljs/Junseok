#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

#include "fame_hall.h"
#include "ui_fame_hall.h"

#include <QFontDatabase>
#include <QString>
#include <QFont>


using namespace std;

Fame_hall::Fame_hall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fame_hall)
{
    int id = QFontDatabase::addApplicationFont("./Maplestory.ttf");
    QString font = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont _font(font, 8);

    ui->setupUi(this);
    loadFames(); // fame_hall.txt에서 명예의 전당 정보 입력받음.
    showFames(); //
    Fame_hall::setFont(_font);
}

Fame_hall::~Fame_hall()
{
    delete ui;
}

void Fame_hall::showFames()
{

    for(size_t i=0; i<FameVector.size() + FameVector.size()%4; i++){


        QWidget* fame = new QWidget;

        QVBoxLayout* VBOX = new QVBoxLayout(fame);
        VBOX->setAlignment(Qt::AlignCenter);

        QLabel* Pet_image = new QLabel;
        QLabel* Pet_name = new QLabel;
        Pet_name->setAutoFillBackground(true);
        Pet_name->setFixedSize(100, 50);
        Pet_name->setAlignment(Qt::AlignCenter); // 가운데 정렬
        //Pet_name->setStyleSheet("QLabel {background-color: white");

        QLabel* Pet_stat = new QLabel[4];
        for(int i=0; i<4; i++){
            Pet_stat[i].setAutoFillBackground(true);
            Pet_stat[i].setFixedSize(50, 50);
            Pet_stat[i].setAlignment(Qt::AlignCenter);
        }

        if(i >= FameVector.size()){
            ui->fames_view->addWidget(fame, int(i/4), int(i%4));
            continue;
        }

        Pet_stat[0].setText(QString::fromStdString(to_string(FameVector[i].Stat.getSTR())));
        Pet_stat[1].setText(QString::fromStdString(to_string(FameVector[i].Stat.getDEX())));
        Pet_stat[2].setText(QString::fromStdString(to_string(FameVector[i].Stat.getINT())));
        Pet_stat[3].setText(QString::fromStdString(to_string(FameVector[i].Stat.getLUX())));


        QHBoxLayout* stat = new QHBoxLayout();

        stat->addWidget(&Pet_stat[0], 0);
        stat->addWidget(&Pet_stat[1], 1);
        stat->addWidget(&Pet_stat[2], 2);
        stat->addWidget(&Pet_stat[3], 3);

        VBOX->addWidget(Pet_name);
        VBOX->setAlignment(Pet_name, Qt::AlignCenter);
        VBOX->addWidget(Pet_image);
        VBOX->addLayout(stat);

        QPixmap image;

        switch(FameVector[i].Pet_num){ // text, image 연결
        case 40: // 포닉스
            Pet_name->setText("포닉스");
            image.load("./image/pet/40.png");
            break;
        case 41: // 넙죽이
            Pet_name->setText("넙죽이");
            image.load("./image/pet/41.png");

            break;
        case 42: // prof.lee
            Pet_name->setText("Prof.Lee");
            image.load("./image/pet/42.png");

            break;
        case 43: // 손흥민
            Pet_name->setText("손흥민");
            image.load("./image/pet/43.png");

            break;
        default:
            cout<<"error!!"<<endl;
            break;
        }

        // Pet 이미지 균일하게
        image = image.scaled(150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation);

        Pet_image->setPixmap(image);
        Pet_image->setAlignment(Qt::AlignCenter); // 가운데 정렬

        ui->fames_view->addWidget(fame, int(i/4), int(i%4));
    }
}

void Fame_hall::on_back_button_clicked()
{
    this->hide();
    emit goToMainWindow();
}

void Fame_hall::loadFames()
{

    ifstream loadFile("./data/fame_hall_info.txt");

    //loadFile.open();
    if(!loadFile){
        std::cerr << "ERROR: Cannot Open File!" << std::endl;
        exit(1);
    }

    string dummy;
    getline(loadFile, dummy);

    while(loadFile.peek() != EOF){

        string temp;

        int _num;
        int _str, _dex, _int, _lux;
        int _time;

        //string token[7];
        getline(loadFile, temp);


        stringstream s(temp);

        cout<<temp<<endl;
        s>>_num>>_str>>_dex>>_int>>_lux>>_time;

        Fame_info Fame(_num, {_str, _dex, _int, _lux}, _time);

        FameVector.push_back(Fame);
    }

}
