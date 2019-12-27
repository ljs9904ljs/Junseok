#ifndef PET_H
#define PET_H

// 아래는 내가 추가한 것들

#include <random>
#include <ctime>
#include <QMessageBox>

//단계별 스탯 행동에서, 스탯을 얼마만큼 올릴지

#define First 20
#define Second 30
#define Third 40
#define Fourth 50

// 위는 내가 추가한 것들


#include <string>
#include <QString>

#include "include/model/ability_point.h"

using namespace std;

class Pet{
public:
    Pet();
    virtual ~Pet();

    Ability_point getStat() const;
    void setStat(const Ability_point &value);

    string getName() const;
    void setName(const string &value);

    QString getImage_file_name() const;
    void setImage_file_name(const QString &value);

    //parameter로 입력한 값만큼 해당하는 능력치를 증가시켜주는 함수
    void setPetSTR(int v);
    void setPetDEX(int v);
    void setPetINT(int v);
    void setPetLUX(int v);
    void setPetALL(int v1, int v2, int v3, int v4);
    void setPetALL(Ability_point &_stat);
    // sick이 1,2,3,4이면 각각 힘,덱,인트,럭스 행동 불가능
    // sick 상태일 때, 원래 증가량에서 sick의 2배로 나누어진 값만 증가된다.
    // 행동할 때 랜덤한 확률로 랜덤한 sick 상태가 된다.
    void changeSTR(int value);
    void changeDEX(int value);
    void changeINT(int value);
    void changeLUX(int value);
    //질병 상태인가?
    bool isSick();

    //난수 생성 함수
    int getRandomNumber(int min, int max);

    //행동을 하면 10퍼센트의 확률로 4가지 질병들 중에서 하나에 걸리게 된다.
    void randomSick();

    //피로도가 0이 되었는지 확인한다. 0이면 true 아니면 false
    bool isFatigue();

    //메뉴에 들어갈 행동들
    virtual void STR_action();
    virtual void DEX_action();
    virtual void INT_action();
    virtual void LUX_action();


    int getPet_kind() const;
    void setPet_kind(int value);

    int getMAX_fatigue() const;
    void setMAX_fatigue(int value);

    int getSick() const;
    void setSick(int value);


protected:
    string name;
    int pet_kind;
    Ability_point stat;
    QString image_file_name;
    int MAX_fatigue; //알 3, 유년기 5, 성장기 10, 궁극체 15
    int sick; // 1 감기, 2 과로, 3 배탈, 4 불면증

};

class Pet_level_2: public Pet{
public:
    Pet_level_2();
    Pet_level_2(Ability_point preStat, int preSick);

    virtual ~Pet_level_2();
    virtual void STR_action();
    virtual void DEX_action();
    virtual void INT_action();
    virtual void LUX_action();
private:
};

class Pet_level_3: public Pet_level_2{
public:
    Pet_level_3();
    Pet_level_3(Ability_point preStat, int preSick);
    virtual ~Pet_level_3();
    virtual void STR_action();
    virtual void DEX_action();
    virtual void INT_action();
    virtual void LUX_action();
private:
};

class Pet_level_4: public Pet_level_3{
public:
    Pet_level_4();
    Pet_level_4(Ability_point preStat, int preSick);
    virtual ~Pet_level_4();
    virtual void STR_action();
    virtual void DEX_action();
    virtual void INT_action();
    virtual void LUX_action();
private:
};

#endif // PET_H

