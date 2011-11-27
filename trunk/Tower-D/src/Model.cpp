#include "include/Model.h"
#include "include/Castle.h"
#include "include/Tower1.h"
#include "include/Monster.h"
#include "include/View.h"
#include <iostream>
#include <cstring>
#include <QTCore/qmath.h>

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

    type1.setTower1(1,false,0,0,2);//(e.v. 11/15/11)Here the towers that were initialized using aggregation in the Model.h, are set with new
    type2.setTower1(2,false,0,0,3);//(e.v. 11/15/11)independent values because each tower will be stronger than its previous one.
    type3.setTower1(4,false,0,0,4);//(e.v. 11/15/11)Values for tower are set to these integers for testing purposes.
    type4.setTower1(6,false,0,0,5);


    setTowerTypes(type1,type2,type3,type4);//(s.c. 11/10/11)

    atwr->choices[0].setTowerTypeindex(1);//(e.v. 11/15/11)this is tower 1 set to have an index of 1
    atwr->choices[1].setTowerTypeindex(2);//(e.v. 11/15/11)this is tower 1 set to have an index of 2
    atwr->choices[2].setTowerTypeindex(3);//(e.v. 11/15/11)this is tower 1 set to have an index of 3
    atwr->choices[3].setTowerTypeindex(4);
}

bool Model::addTower(int grid_number_space, int h)//(e.v. 11/15/11)
                                                  //(p.m. 11/11/11)
{
    bool exists = false;
        setFlag(false);
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
            if(h == 1 && castle->getMoney()>= 100)
            {
              castle->spendMoney(100);//cost of tower
              towers.push_back(new Tower1(atwr->choices[0]));
              towers[towers.size() - 1]->setGrid_Number(grid_number_space);
              setFlag(true);
            }

            if(h == atwr->choices[1].getIndex_tower_type() && castle->getMoney()>= 200)
            {
                castle->spendMoney(200);//cost of tower
                towers.push_back(new Tower1(atwr->choices[1]));
                towers[towers.size() - 1]->setGrid_Number(grid_number_space);
                setFlag(true);
            }

            if(h == atwr->choices[2].getIndex_tower_type()&& castle->getMoney()>= 300)
            {
                castle->spendMoney(300);//cost of tower
                towers.push_back(new Tower1(atwr->choices[2]));
                towers[towers.size() - 1]->setGrid_Number(grid_number_space);
                setFlag(true);
            }
            if(h == atwr->choices[3].getIndex_tower_type()&& castle->getMoney()>= 400)
            {
                castle->spendMoney(400);//cost of tower
                towers.push_back(new Tower1(atwr->choices[3]));
                towers[towers.size() - 1]->setGrid_Number(grid_number_space);
                setFlag(true);
            }
            return true;
        }
        else
            return false;

}

void Model::addMonster()
{
    monsters.push_back(new Monster(level, getArray_path()->getPathStart(), 0));
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
        if (monsters[index]->getGrid_Number() == getArray_path()->getPathEnd())
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
        castle->addScore(qCeil(castle->getHealth()/10)); //Get the health of your castle, divides it by 10 and rounds it up then adds it to your score.
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
            else if (towers[twrIndex]->getShotCounter() == towers[twrIndex]->getShotSpeed())
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

bool Model::getFlag()
{
    return flag;
}
void Model::setFlag(bool s)
{
    flag = s;
}
