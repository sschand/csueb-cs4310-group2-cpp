#include "include/Monster.h"
#include <QWidget>

/*Monster
/.cpp file for Monster class
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
/
/     10/31/11
*/

Monster::Monster(int lvl, int space, int dummy)
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
    case 1:    //all attack values ar set to 1 to test how towers function. 11/15/11
        Attack_Value_and_Health = 1;//how much damage Monster inflicts at level 1
        break;
    case 10:
        Attack_Value_and_Health = 1;//how much damage Monster inflicts at level 10
        break;
    case 12:
        Attack_Value_and_Health = 1;//how much damage Monster inflicts at level 12
        break;
    case 16:
        Attack_Value_and_Health = 1;//how much damage Monster inflicts at level 16
        break;
    default:
        break;
    }
    Grid_Number = space;
}

int Monster::getAttact_Value_and_Health()//Used to get attack/health of monsters individually at any moment if needed.
{
    return Attack_Value_and_Health;
}

int Monster::getGrid_Number()
{
    return Grid_Number;
}

void Monster::setAttack_Value_and_Health(int a)
{
     Attack_Value_and_Health = a;
}

void Monster::setGrid_Number(int g)
{
    Grid_Number = g;
}

void Monster::setMonster(int attv_hl,int grdnm)
{
    Attack_Value_and_Health = attv_hl;
    Grid_Number = grdnm;
}

int Monster::getupdated_Damage()
{
    if (Attack_Value_and_Health < 0)
        Attack_Value_and_Health = 0;
    return Attack_Value_and_Health;
}

void Monster::hit(int dmg)
{
    Attack_Value_and_Health -= dmg;
}
