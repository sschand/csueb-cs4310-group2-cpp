#include "include/Model.h"

Model::Model(QWidget *parent) :
    QWidget(parent)
{
    pathSize = 58;
    gameTitle = "Tower Defense 1.1";
    castle = new Castle;


    int x = 0;
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
    path[x++] = 0;
}

void Model::addMonster()
{
    monsters.push_back(new Monster);
}

bool Model::addTower(int grdNmbr)
{
    bool exists = false;

    for (int index = 0; index < towers.size(); index++)
    {
        if (grdNmbr == towers[index]->getGridNumber())
        {
            exists = true;
            break;
        }
    }
    if (!exists && castle->getMoney() >= 100)
    {
        castle->spendMoney(100);
        towers.push_back(new Tower(grdNmbr));
        return true;
    }
    else
        return false;
}

Castle * Model::getCastle()
{
    return castle;
}

int * Model::getPath()
{
    return path;
}

int Model::getPathSize()
{
    return pathSize;
}

int Model::getTowersSize()
{
    return towers.size();
}

void Model::incrementMonsters()
{
    for (int index = 0; index < monsters.size(); index++)
    {
        for (int pathIndex = 0; pathIndex < pathSize-1; pathIndex++)
        {
            if (monsters[index]->getGridNumber() == path[pathIndex])
            {
                monsters[index]->setGridNumber(path[pathIndex+1]);
                break;
            }
        }
        if (monsters[index]->getGridNumber() == 0)
        {
            castle->subtractHealth(monsters[index]->getDamage());
            monsters.remove(index);
            monsters.squeeze();
        }
    }
}

void Model::kill(int twrIndex, int mnstIndex)
{
    monsters[mnstIndex]->hit(towers[twrIndex]->getDamage());
    if (monsters[mnstIndex]->getDamage() < 1)
    {
        deadMonsters.push_back(mnstIndex);
        monsters.remove(mnstIndex);
        monsters.squeeze();
    }
}

QVector<int> Model::towersTakeShot()
{
    deadMonsters.clear();
    int twrGN, mnstGN;

    for (int twrIndex = 0; twrIndex < towers.size(); twrIndex++)
    {
        towers[twrIndex]->setSight(false);
        twrGN = towers[twrIndex]->getGridNumber();
        for (int mnstIndex = 0; mnstIndex < monsters.size(); mnstIndex++)
        {
            mnstGN = monsters[mnstIndex]->getGridNumber();
            if (mnstGN == twrGN-18 ||mnstGN == twrGN-17 ||mnstGN == twrGN-16 ||mnstGN == twrGN-1 ||
                mnstGN == twrGN+1 ||mnstGN == twrGN+16 ||mnstGN == twrGN+17 ||mnstGN == twrGN+18)
            {
                mnstGN = mnstIndex;
                towers[twrIndex]->setSight(true);
                break;
            }
        }

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
