#include "include/View.h"

View::View(QWidget *parent) :
    QWidget(parent)
{
    loaded = false;

    scene = new QGraphicsScene;
    window = new QGraphicsView;

    gameGrid = new ClickableArea;
    gameGrid->resize(578, 408);
    gameGrid->move(23, 9);

    towerGrid = new ClickableArea;
    towerGrid->resize(599, 38);
    towerGrid->move(140, 444);

    start_quit = new QPushButton("Start");
    start_quit->move(628, 516);
    start_quit->resize(141, 55);

    monsterImage = new QPixmap("resources/monster.png");
    *monsterImage = monsterImage->scaled(34,34);

    towerImage = new QPixmap("resources/tower.png");
    *towerImage = towerImage->scaled(34,34);

    QPixmap *back = new QPixmap("resources/TowerDBase.png");//PositionTestBase.png
    *back = back->scaledToWidth(801);

                    scene->addWidget(gameGrid);
                    scene->addWidget(towerGrid);
    background    = scene->addPixmap(*back);
    selection1    = scene->addPixmap(*towerImage);
    score         = scene->addText(QString::number(0), QFont("Times", 14, 2));
    money         = scene->addText(QString::number(0), QFont("Times", 14, 2));
    health        = scene->addText(QString::number(0), QFont("Times", 14, 2));
    messageBoard  = scene->addText("Purchase towers or\nPress Start to send enemies!", QFont("Times", 16, 2));
                    scene->addWidget(start_quit);

    selection1->moveBy(140,444);
    selection1->scale(1.1176,1.1176);
    score->moveBy(715, 250);
    money->moveBy(715, 315);
    health->moveBy(715, 380);
    messageBoard->moveBy(120, 520);

    window->setScene(scene);
    window->resize(803, 590);
    window->show();
}

ClickableArea * View::getGameGrid()
{
    return gameGrid;
}

ClickableArea * View::getTowerGrid()
{
    return towerGrid;
}

QPushButton * View::getStart_Quit()
{
    return start_quit;
}

QGraphicsView * View::getWindow()
{
    return window;
}

void View::addMonster()
{
    Enemy * temp = new Enemy;
    temp->monsterItem = scene->addPixmap(*monsterImage);
    temp->gridNumber = 86;

    monsters.push_back(temp);
    printMonsters();
}

void View::addTower(int x, int y, int grdNmbr)
{
    Tower * temp;
    temp = new Tower;
    temp->towerItem = scene->addPixmap(*towerImage);
    temp->gridNumber = grdNmbr;

    x = x/34;
    x = (x*34) + 22;
    y = y/34;
    y = (y*34) + 10;

    temp->towerItem->moveBy(x, y);
    towers.push_back(temp);

    loaded = false;
}

bool View::isLoaded()
{
    return loaded;
}

void View::loadTower(int twrChc)
{
    switch(twrChc)
    {
    case 1:
        loaded = true;
        break;
    default:
        break;
    }
}

void View::updateStats(int hlth, int mny, int scr)
{
    health->setPlainText(QString::number(hlth));

    money->setPlainText(QString::number(mny));

    score->setPlainText(QString::number(scr));
}

void View::printMonsters()
{
    int grdNmbr, x, y;

    for (int index = 0; index < monsters.size(); index++)
    {
        grdNmbr = monsters[index]->gridNumber;
        if (grdNmbr%17 == 0)
        {
            x = 566;
        }
        else
        {
            x = (((grdNmbr%17)-1)*34)+22;
        }
        y = (((grdNmbr-1)/17)*34)+ 10;
        monsters[index]->monsterItem->setPos(x, y);
    }
}

void View::incrementMonsters(int *pth, int pthSz)
{
    for (int index = 0; index < monsters.size(); index++)
    {
        for (int pathIndex = 0; pathIndex < pthSz; pathIndex++)
        {
            if (monsters[index]->gridNumber == pth[pathIndex])
            {
                monsters[index]->gridNumber = pth[pathIndex+1];
                break;
            }
        }
        if (monsters[index]->gridNumber == pth[pthSz-1])
        {
            monsters[index]->monsterItem->hide();
            scene->removeItem(monsters[index]->monsterItem);
            monsters.remove(index);
            monsters.squeeze();
        }
    }
    printMonsters();
}

void View::kill(QVector<int> deadMonsters)
{
    for (int index = 0; index < deadMonsters.size(); index++)
    {
        monsters[deadMonsters[index]]->monsterItem->hide();
        scene->removeItem(monsters[deadMonsters[index]]->monsterItem);
        monsters.remove(deadMonsters[index]);
        monsters.squeeze();
    }
}
