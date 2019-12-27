#include "include/model/ability_point.h"

Ability_point::Ability_point()
{
    STR = 0;
    DEX = 0;
    INT = 0;
    LUX = 0;
}

Ability_point::Ability_point(int _str, int _dex, int _int, int _lux)
{
    STR = _str;
    DEX = _dex;
    INT = _int;
    LUX = _lux;
}

int Ability_point::getSTR() const
{
return STR;
}

void Ability_point::setSTR(int value)
{
STR = value;
}

int Ability_point::getDEX() const
{
return DEX;
}

void Ability_point::setDEX(int value)
{
DEX = value;
}

int Ability_point::getINT() const
{
    return INT;
}

void Ability_point::setINT(int value)
{
    INT = value;
}

int Ability_point::getLUX() const
{
    return LUX;
}

void Ability_point::setLUX(int value)
{
    LUX = value;
}
