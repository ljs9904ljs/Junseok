#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "include/model/pet.h"
#include "include/model/item.h"

class player{
public:
    player();
    ~player();

    int STR_action();
    int DEX_action();
    int INT_action();
    int LUX_action();

    void setPetImageFile();
    bool isFatigue();
    void player_sleep();
    int canEvolve();
    void saveMode();
    void loadMode();

    void pet_evolution_to_level2();
    void pet_evolution_to_level3();
    void pet_evolution_to_level4();

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
    ItemVector ItemList;
    Pet* pet;
    int money = 1000;
    int fatigue;
    int action_limit[4];
    int play_time;
    int pet_level;

};

#endif // PLAYER_H

