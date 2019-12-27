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
};

typedef pair<Item, int> ItemPair;
typedef vector<ItemPair> ItemVector;
typedef  vector<ItemPair>::iterator Viter;


#endif // ITEM_H
