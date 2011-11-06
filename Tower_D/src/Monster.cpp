#include "include/Monster.h"

Monster::Monster()
{
    damage = 3;
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
