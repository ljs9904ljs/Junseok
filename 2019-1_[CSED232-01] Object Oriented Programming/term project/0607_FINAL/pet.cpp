#include "include/model/pet.h"
#include<iostream>



Pet::Pet()
{
    MAX_fatigue = 3;
    pet_kind = 10;
    image_file_name = "./image/animal/10.png";
}

Pet::~Pet()
{
    ;
}

Ability_point Pet::getStat() const
{
    return stat;
}

void Pet::setStat(const Ability_point &value)
{
    stat = value;
}

string Pet::getName() const
{
    return name;
}

void Pet::setName(const string &value)
{
    name = value;
}

QString Pet::getImage_file_name() const
{
    return image_file_name;
}

void Pet::setImage_file_name(const QString &value)
{
    image_file_name = value;
}

void Pet::setPetSTR(int v)
{
    int cur = stat.getSTR();
    cur = cur + v;
    stat.setSTR(cur);
}

void Pet::setPetDEX(int v)
{
    int cur = stat.getDEX();
    cur = cur + v;
    stat.setDEX(cur);
}

void Pet::setPetINT(int v)
{
    int cur = stat.getINT();
    cur = cur + v;
    stat.setINT(cur);
}

void Pet::setPetLUX(int v)
{
    int cur = stat.getLUX();
    cur = cur + v;
    stat.setLUX(cur);
}

void Pet::setPetALL(int v1, int v2, int v3, int v4)
{
    setPetSTR(v1);
    setPetDEX(v2);
    setPetINT(v3);
    setPetLUX(v4);
}

void Pet::setPetALL(Ability_point &_stat)
{
    std::cout<<_stat.getLUX()<<std::endl;
    setPetSTR(_stat.getSTR());
    setPetDEX(_stat.getDEX());
    setPetINT(_stat.getINT());
    setPetLUX(_stat.getLUX());
}

void Pet::changeSTR(int value)
{
    //1번 질병이면 이 행동 못한다.
    if(sick == 1){
        QMessageBox msg;
        msg.setText("펫이 아파서 이 행동을 할 수가 없어요! 펫에게 약을 주세요!");
        msg.exec();
        return;
    }
    //스탯 증가
    int cur = stat.getSTR();
    int setter;
    if(isSick()){
        setter = cur + value - (sick*2);
        stat.setSTR(setter);
    }
    else{
        setter = cur + value;
        stat.setSTR(setter);
        //병에 걸릴 수도 있고 안 걸릴 수도 있다.
        randomSick();
    }

    return;
}

void Pet::changeDEX(int value)
{
    //2번 질병이면 이 행동 못한다.
    if(sick == 2){
        QMessageBox msg;
        msg.setText("펫이 아파서 이 행동을 할 수가 없어요! 펫에게 약을 주세요!");
        msg.exec();
        return;
    }


    //스탯 증가
    int cur = stat.getDEX();
    int setter;
    if(isSick()){
        setter = cur + value - (sick*2);
        stat.setDEX(setter);
    }
    else{
        setter = cur + value;
        stat.setDEX(setter);
        //병에 걸릴 수도 있고 안 걸릴 수도 있다.
        randomSick();
    }

    return;
}

void Pet::changeINT(int value)
{
    //3번 질병이면 이 행동 못한다.
    if(sick == 3){
        QMessageBox msg;
        msg.setText("펫이 아파서 이 행동을 할 수가 없어요! 펫에게 약을 주세요!");
        msg.exec();
        return;
    }


    //스탯 증가
    int cur = stat.getINT();
    int setter;
    if(isSick()){
        setter = cur + value - (sick*2);
        stat.setINT(setter);
    }
    else{
        setter = cur + value;
        stat.setINT(setter);
        //병에 걸릴 수도 있고 안 걸릴 수도 있다.
        randomSick();
    }

    return;
}

void Pet::changeLUX(int value)
{
    //4번 질병이면 이 행동 못한다.
    if(sick == 4){
        QMessageBox msg;
        msg.setText("펫이 아파서 이 행동을 할 수가 없어요! 펫에게 약을 주세요!");
        msg.exec();
        return;
    }


    //스탯 증가
    int cur = stat.getLUX();
    int setter;
    if(isSick()){
        setter = cur + value - (sick*2);
        stat.setLUX(setter);
    }
    else{
        setter = cur + value;
        stat.setLUX(setter);
        //병에 걸릴 수도 있고 안 걸릴 수도 있다.
        randomSick();
    }

    return;
}

bool Pet::isSick()
{
    if(sick >=1 && sick <= 4){
        return true;
    }
    else{
        return false;
    }
}

int Pet::getRandomNumber(int min, int max)
{
    srand(static_cast<unsigned int>(time(0)));
    int rnNum;
    while(1){
        int temp = (rand() % (max-min+1) + min);
        if(temp>=min && temp<=max){
            rnNum = temp;
            break;
        }
    }

    return rnNum;
}

void Pet::randomSick()
{
    if(getRandomNumber(1, 3) == 1){ // 10퍼센트의 확률로
        sick = getRandomNumber(1, 4); // 4가지 질병들 중에서 하나에 걸리게 된다. 감기 배탈 몸살 불면증
        QMessageBox msg;
        msg.setText("펫이 병에 걸렸어요!");
        msg.exec();
    }
    return;
}

bool Pet::isFatigue()
{
    if(MAX_fatigue == 0)
        return true;
    else
        return false;
}

void Pet::STR_action()
{
    changeSTR(First);
}

void Pet::DEX_action()
{
    changeDEX(First);
}

void Pet::INT_action()
{
    changeINT(First);
}

void Pet::LUX_action()
{
    changeLUX(First);
}

int Pet::getPet_kind() const
{
    return pet_kind;
}

void Pet::setPet_kind(int value)
{
    pet_kind = value;
}

int Pet::getMAX_fatigue() const
{
    return MAX_fatigue;
}

void Pet::setMAX_fatigue(int value)
{
    MAX_fatigue = value;
}

int Pet::getSick() const
{
    return sick;
}

void Pet::setSick(int value)
{
    sick = value;
}

Pet_level_2::Pet_level_2(): Pet()
{
    MAX_fatigue = 5;
}

Pet_level_2::Pet_level_2(Ability_point preStat, int preSick)
{
    MAX_fatigue = 5;

    stat = preStat;
    sick = preSick;
}

Pet_level_2::~Pet_level_2()
{
    ;
}

void Pet_level_2::STR_action()
{
    changeSTR(Second);
}

void Pet_level_2::DEX_action()
{
    changeDEX(Second);
}

void Pet_level_2::INT_action()
{
    changeINT(Second);
}

void Pet_level_2::LUX_action()
{
    changeLUX(Second);
}

Pet_level_3::Pet_level_3(): Pet_level_2 ()
{
    MAX_fatigue = 10;
}

Pet_level_3::Pet_level_3(Ability_point preStat, int preSick)
{
    MAX_fatigue = 10;

    stat = preStat;
    sick = preSick;
}

Pet_level_3::~Pet_level_3()
{
    ;
}

void Pet_level_3::STR_action()
{
    changeSTR(Third);
}

void Pet_level_3::DEX_action()
{
    changeDEX(Third);
}

void Pet_level_3::INT_action()
{
    changeINT(Third);
}

void Pet_level_3::LUX_action()
{
    changeLUX(Third);
}

Pet_level_4::Pet_level_4(): Pet_level_3 ()
{
    MAX_fatigue = 15;
}

Pet_level_4::Pet_level_4(Ability_point preStat, int preSick)
{
    MAX_fatigue = 15;

    stat = preStat;
    sick = preSick;
}

Pet_level_4::~Pet_level_4()
{
    ;
}

void Pet_level_4::STR_action()
{
    changeSTR(Fourth);
}

void Pet_level_4::DEX_action()
{
    changeDEX(Fourth);
}

void Pet_level_4::INT_action()
{
    changeINT(Fourth);
}

void Pet_level_4::LUX_action()
{
    changeLUX(Fourth);
}

