#include "include/model/item.h"

#include "include/model/ability_point.h"


Item::Item(int ItemNum, string ItemName, Ability_point Stat, int Price)
{
    itemNum = ItemNum;
    item_name = ItemName;
    stat = Stat;
    price = Price;
}
