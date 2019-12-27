#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "include/model/pet.h"
#include "include/model/item.h"
#include <QLabel>

class player{
public:
    player();
    ~player();

    //각각의 능력치를 올려주는 행동들
    int STR_action();
    int DEX_action();
    int INT_action();
    int LUX_action();

    void setPetImageFile(); // 펫의 이미지 파일(폴더에 있는 png파일을 불러온다.)을 설정한다.
    bool isFatigue(); // 피로도가 0인지 체크한다
    void player_sleep(); // 플레이어 잠자기 행동을 수행한다. 피로도 초기화, 진화 조건 체크, 졸업 조건 체크
    int canEvolve(); //진화할 수 있는지 확인하는 함수
    void saveMode(); //저장하기, 텍스트 파일에 플레이어의 모든 정보를 저장한다.
    void loadMode(); //이어하기를 위해 저장된 텍스트 파일을 불러온다.

    //펫의 진화
    void pet_evolution_to_level2();
    void pet_evolution_to_level3();
    void pet_evolution_to_level4();

    //get 함수와 set 함수들
    int getMoney() const;
    void setMoney(int value);

    ItemVector* getItemList();

    Pet *getPet() const;
    void setPet(Pet *value);

    int getFatigue() const;
    void setFatigue(int value);

    int getPlay_time() const;
    void setPlay_time(int value);

private:
    string player_name;
    ItemVector ItemList; //보유 아이템 목록
    Pet* pet; // 펫
    int money = 1000;
    int fatigue; // 피로도
    int play_time; // 플레이한 시간
    int pet_level; // 펫의 레벨(진화 단계)
};

#endif // PLAYER_H
