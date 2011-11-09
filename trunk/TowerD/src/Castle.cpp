#include "include/Castle.h"

/*Castle
/.cpp file for Castle class
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
/
/     10/31/11
*/

int Castle::getHealth()
{
    return health;
}

int Castle::getGridNum()
{
    return Grid_Number;
}

void Castle::set_GridNum(int grdnm)
{
    Grid_Number = grdnm;
}

void Castle::setCastle(int h, int m, int s, int g)
{
    health = h;
    money = m;
    score = s;
    Grid_Number = g;
}

void Castle::subtractHealth(int hlth)
{
    health -= hlth;
    if (health < 0)
    {
        health = 0;
    }
}

int Castle::getMoney()
{
    return money;
}

int Castle::getScore()
{
    return score;
}

void Castle::spendMoney(int mny)
{
    money -= mny;
}

