#include "include/Model.h"
#include "include/Castle.h"
#include "include/Tower1.h"
#include "include/Monster.h"
#include "include/View.h"
#include <iostream>
#include <cstring>

using namespace std;

/*Model
/.cpp file for model class
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
/
/     10/31/11
*/

Model::Model(QWidget *parent) : QWidget(parent)
{
    level = 0;

    gameTitle = new char [strlen("Tower Defense 1.1") + 1];
    strcpy(gameTitle, "Tower Defense 1.1");

    castle = new Castle;
    mns_path = new ArrayPath;


    /*int x = 0;
    path = new int[pathSize];
    path[x++] = 86;
    path[x++] = 87;
    path[x++] = 104;
    path[x++] = 105;
    path[x++] = 106;
    path[x++] = 123;
    path[x++] = 140;
    path[x++] = 157;
    path[x++] = 158;
    path[x++] = 159;
    path[x++] = 160;
    path[x++] = 143;
    path[x++] = 126;
    path[x++] = 109;
    path[x++] = 92;
    path[x++] = 75;
    path[x++] = 74;
    path[x++] = 57;
    path[x++] = 40;
    path[x++] = 23;
    path[x++] = 24;
    path[x++] = 25;
    path[x++] = 26;
    path[x++] = 27;
    path[x++] = 28;
    path[x++] = 45;
    path[x++] = 62;
    path[x++] = 79;
    path[x++] = 96;
    path[x++] = 95;
    path[x++] = 112;
    path[x++] = 129;
    path[x++] = 146;
    path[x++] = 163;
    path[x++] = 180;
    path[x++] = 181;
    path[x++] = 182;
    path[x++] = 165;
    path[x++] = 166;
    path[x++] = 167;
    path[x++] = 184;
    path[x++] = 185;
    path[x++] = 186;
    path[x++] = 169;
    path[x++] = 152;
    path[x++] = 135;
    path[x++] = 118;
    path[x++] = 117;
    path[x++] = 116;
    path[x++] = 99;
    path[x++] = 82;
    path[x++] = 65;
    path[x++] = 48;
    path[x++] = 49;
    path[x++] = 50;
    path[x++] = 67;
    path[x++] = 68;
    path[x++] = 0; */
}

bool Model::addTower(int grid_number_space)
{

    /*towers.push_back(new Tower1(obj)); THIS WILL BE USED ONCE WE GET THE ARRAY OF MONSTERS GOING
    int vect_space = towers.size() - 1;
    towers[vect_space]->setGrid_Number(grid_number_space);*/
    bool exists = false;

        for (int index = 0; index < towers.size(); index++)
        {
            if (grid_number_space == towers[index]->getGrid_Number())
            {
                exists = true;
                break;
            }
        }
        if (!exists && castle->getMoney() >= 100)
        {
            castle->spendMoney(100);
            towers.push_back(new Tower1(grid_number_space));
            return true;
        }
        else
            return false;
}

/*void Model::initialize_add_Monster(const Monster &obj)//create a mosnter object in the function that will be calling creating
{                                                     //the monsters. then just pass that object into this fucntion everytime
    mnst.push_back(new Monster(obj));                 //you need that same monster type.
}*/

void Model::addMonster()
{
    monsters.push_back(new Monster(level));
}

Castle * Model::getCastle()
{
    return castle;
}

ArrayPath * Model::getArray_path()
{
    return mns_path;
}

int Model::getTowersSize()
{
    return towers.size();
}

void Model::incrementMonsters()
{
    for (int index = 0; index < monsters.size(); index++)
    {
        for (int pathIndex = 0; pathIndex < (getArray_path()->getPathSize()-1); pathIndex++)
        {
            if (monsters[index]->getGrid_Number() == (getArray_path()->getPath()[pathIndex]))
            {
                monsters[index]->setGrid_Number(getArray_path()->getPath()[pathIndex+1]);
                break;
            }
        }
        if (monsters[index]->getGrid_Number() == 0)
        {
            castle->subtractHealth(monsters[index]->getupdated_Damage());
            monsters.remove(index);
            monsters.squeeze();
        }
    }
}

void Model::kill(int twrIndex, int mnstIndex)
{
    monsters[mnstIndex]->hit(towers[twrIndex]->getDamage());
    if (monsters[mnstIndex]->getupdated_Damage() < 1)
    {
        deadMonsters.push_back(mnstIndex);
        monsters.remove(mnstIndex);
        monsters.squeeze();
        castle->spendMoney(-50);
    }
}

QVector<int> Model::towersTakeShot()
{
    deadMonsters.clear();
    int twrGN, mnstGN;
    bool temp;

    for (int twrIndex = 0; twrIndex < towers.size(); twrIndex++)
    {
        temp = false;
        twrGN = towers[twrIndex]->getGrid_Number();
        for (int mnstIndex = 0; mnstIndex < monsters.size(); mnstIndex++)
        {
            mnstGN = monsters[mnstIndex]->getGrid_Number();
            if (mnstGN == twrGN-18 ||mnstGN == twrGN-17 ||mnstGN == twrGN-16 ||mnstGN == twrGN-1 ||
                mnstGN == twrGN+1 ||mnstGN == twrGN+16 ||mnstGN == twrGN+17 ||mnstGN == twrGN+18)
            {
                mnstGN = mnstIndex;
                temp = true;
                break;
            }
        }
        towers[twrIndex]->setSight(temp);

        if (towers[twrIndex]->enemyIsInSight())
        {
            towers[twrIndex]->takeShot();
            if (towers[twrIndex]->getShotCounter() == 1)
            {
                kill(twrIndex, mnstGN);
            }
            else if (towers[twrIndex]->getShotCounter() == 4)
            {
                towers[twrIndex]->resetShotCounter();
            }
        }
        else
        {
            towers[twrIndex]->resetShotCounter();
        }
    }
    return deadMonsters;
}

int Model::getLevel()
{
    return level;
}

void Model::nextLevel()
{
    level++;
}

int Model::getMonsterSize()
{
    return monsters.size();
}

