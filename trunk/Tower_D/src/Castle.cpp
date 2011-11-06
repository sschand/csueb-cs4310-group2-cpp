#include "include/Castle.h"

Castle::Castle()
{
    health = 100;
    money = 300;
    score = 0;
}

int Castle::getHealth()
{
    return health;
}

int Castle::getMoney()
{
    return money;
}

int Castle::getScore()
{
    return score;
}

void Castle::subtractHealth(int hlth)
{
    health -= hlth;
    if (health < 0)
    {
        health = 0;
    }
}

void Castle::spendMoney(int mny)
{
    money -= mny;
}
