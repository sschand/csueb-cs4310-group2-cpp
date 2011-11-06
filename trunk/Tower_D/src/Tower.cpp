#include "include/Tower.h"

Tower::Tower(int grdNmbr)
{
    damage = 1;
    gridNumber = grdNmbr;
    shotCounter = 0;
    enemyInSight = false;
}

int Tower::getGridNumber()
{
    return gridNumber;
}

int Tower::getDamage()
{
    return damage;
}

int Tower::getShotCounter()
{
    return shotCounter;
}

void Tower::takeShot()
{
    shotCounter++;
}

void Tower::resetShotCounter()
{
    shotCounter = 0;
}

bool Tower::enemyIsInSight()
{
    return enemyInSight;
}

void Tower::setSight(bool enemyInSght)
{
    enemyInSight = enemyInSght;
}
