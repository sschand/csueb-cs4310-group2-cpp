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

void Tower1::setTower1(int fp, bool cv, int sp, int gn,int ss)
{
    damage = fp;
    enemyInSight = cv;
    shotCounter = sp;
    Grid_Number = gn;
    Shot_Speed= ss;
}

int Tower1::getGrid_Number()
{
    return Grid_Number;
}

void Tower1::setGrid_Number(int Gn)
{
    Grid_Number = Gn;
}

int Tower1::getDamage()
{
    return damage;
}

int Tower1::getShotCounter()
{
    return shotCounter;
}

void Tower1::setDamage(int d)
{
    damage = d;
}

void Tower1::setshotCounter(int s_counter)
{
    shotCounter = s_counter;
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

int Tower1::getIndex_tower_type()
{
    return getIndex();//inherited from Graphics Item.
}

bool Tower1::getEnemyinSight()
{
    return enemyInSight;
}
int Tower1::getShotSpeed()
{
    return Shot_Speed;
}
void Tower1::setShotSpeed(int ss)
{
    Shot_Speed= ss;
}

