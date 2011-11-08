#ifndef MODEL_H
#define MODEL_H

#include "include/Castle.h"
#include "include/Monster.h"
#include "include/Tower.h"
#include <QWidget>
#include <QVector>

class Model : public QWidget
{
    Q_OBJECT

private:
    Castle *castle;

    int level;
    int *path;
    int pathSize;
    char *gameTitle;
    QVector<Monster*> monsters;
    QVector<Tower*> towers;
    QVector<int> deadMonsters;

public:
    explicit Model( QWidget * parent = 0 );

    void addMonster();
    bool addTower(int grdNmbr);
    int * getPath();
    int getPathSize();
    int getTowersSize();
    void incrementMonsters();
    void kill(int twrIndex, int mnstIndex);
    QVector<int> towersTakeShot();
    int getLevel();
    void nextLevel();
    int getMonsterSize();

    Castle * getCastle();

};

#endif // MODEL_H
