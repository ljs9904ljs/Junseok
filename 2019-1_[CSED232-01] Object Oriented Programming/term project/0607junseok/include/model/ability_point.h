#ifndef ABILITY_POINT_H
#define ABILITY_POINT_H

class Ability_point{
public:
    Ability_point();
     Ability_point(int _str, int _dex, int _int, int _lux);
    int getSTR() const;
    void setSTR(int value);

    int getDEX() const;
    void setDEX(int value);

    int getINT() const;
    void setINT(int value);

    int getLUX() const;
    void setLUX(int value);

private:
    int STR;
    int DEX;
    int INT;
    int LUX;

};


#endif // ABILITY_POINT_H
