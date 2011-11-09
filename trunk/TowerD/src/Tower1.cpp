#include "include/Tower1.h"

/*Tower1
/.cpp file for Tower1 class
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
/
/     10/31/11
*/

/*int Tower1::getFirePower()
{
    return FirePower;
}

int Tower1::getCost_Value()
{
    return Cost_Value;
}

int Tower1::getShot_Speed()
{
    return Shot_Speed;
}*/

int Tower1::getGrid_Number()
{
    return Grid_Number;
}
/*
void Tower1::setGrid_Number(int Gn)
{
    Grid_Number = Gn;
}

void Tower1::setTower1(int fp, int cv, int sp, int gn)
{
    FirePower = fp;
    Cost_Value = cv;
    Shot_Speed = sp;
    Grid_Number = gn;
}*/

Tower1::Tower1(int grdNmbr)
{
    damage = 1;
    Grid_Number = grdNmbr; //Grid number inherited from graphics item.
    shotCounter = 0;
    enemyInSight = false;
}

int Tower1::getDamage()
{
    return damage;
}

int Tower1::getShotCounter()
{
    return shotCounter;
}

void Tower1::takeShot()
{
    shotCounter++;
}

void Tower1::resetShotCounter()
{
    shotCounter = 0;
}

bool Tower1::enemyIsInSight()
{
    return enemyInSight;
}

void Tower1::setSight(bool enemyInSght)
{
    enemyInSight = enemyInSght;
}
