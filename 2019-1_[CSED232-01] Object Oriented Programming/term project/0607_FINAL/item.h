#ifndef ITEM_H
#define ITEM_H


#include <QString>

#include <string>
#include <vector>
#include <utility>

#include "include/model/ability_point.h"

using namespace std;

struct Item{

    Item() = default;
    Item(int, string, Ability_point, int);

    int itemNum;
    string item_name;
    Ability_point stat;
    int price;

    int cure; // 0: ?곹깭蹂???놁쓬. 1: ~~ 移섎즺, 2: ~~ 移섎즺, 3: ~~ 移섎즺

    QString image_file_name;
};

typedef pair<Item, int> ItemPair;
typedef vector<ItemPair> ItemVector;
typedef  vector<ItemPair>::iterator Viter;


#endif // ITEM_H

/*public:


    string getItem_name() const;
    void setItem_name(const string &value);

    Ability_point getStat() const;
    void setStat(const Ability_point &value);*/
