#include "include/Monster.h"

Monster::Monster()
{
    damage = 4;
    gridNumber = 86;
}

Monster::Monster(int lvl)
{
    if (lvl < 10)
        lvl = 1;
    else if (lvl < 12)
        lvl = 10;
    else if (lvl < 16)
        lvl = 12;
    else
        lvl = 16;

    switch(lvl)
    {
    case 1:
        damage = 4;
        break;
    case 10:
        damage = 8;
        break;
    case 12:
        damage = 15;
        break;
    case 16:
        damage = 127;
        break;
    default:
        break;
    }
    gridNumber = 86;
}

int Monster::getGridNumber()
{
    return gridNumber;
}

void Monster::setGridNumber(int grdNmbr)
{
    gridNumber = grdNmbr;
}

int Monster::getDamage()
{
    if (damage < 0)
        damage = 0;
    return damage;
}

void Monster::hit(int dmg)
{
    damage -= dmg;
}
