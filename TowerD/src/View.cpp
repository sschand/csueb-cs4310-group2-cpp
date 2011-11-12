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

    monsterImage = new QPixmap("resources/greenMonster.png");//monster.pngdemon.pngblueMonster.png
    *monsterImage = monsterImage->scaled(34,34);

    tower1Image = new QPixmap("resources/tower.png");//rook.png
    *tower1Image = tower1Image->scaled(34,34);

    tower2Image = new QPixmap("resources/logo1.png");
    *tower2Image = tower2Image->scaled(34,34);

    tower3Image = new QPixmap("resources/logo2.png");
    *tower3Image = tower3Image->scaled(34,34);

    QPixmap *back = new QPixmap("resources/TowerDBase.png");//resources/PositionTestBase.png
    *back = back->scaledToWidth(801);




                    scene->addWidget(gameGrid);
                    scene->addWidget(towerGrid);
    background    = scene->addPixmap(*back);
    selection1    = scene->addPixmap(*tower1Image);
    selection2    = scene->addPixmap(*tower2Image);
    selection3    = scene->addPixmap(*tower3Image);
    score         = scene->addText(QString::number(0), QFont("Times", 14, 2));
    money         = scene->addText(QString::number(0), QFont("Times", 14, 2));
    health        = scene->addText(QString::number(0), QFont("Times", 14, 2));
    messageBoard  = scene->addText("This is the message board!", QFont("Times", 16, 2));
                    scene->addWidget(start_quit);

    QGraphicsTextItem* item = scene->addText("$100", QFont("Times", 12, 10));

    item->moveBy(136, 475);
    item->setDefaultTextColor(QColor(0,255,0));
    selection1->moveBy(140,444);
    selection1->scale(1.1176,1.1176);
    selection2->moveBy(191,444);
    selection2->scale(1.1176,1.1176);
    selection3->moveBy(242,444);
    selection3->scale(1.1176,1.1176);
    score->moveBy(715, 250);
    money->moveBy(715, 315);
    health->moveBy(715, 380);
    messageBoard->moveBy(120, 530);

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
    temp->towerItem = scene->addPixmap(*loadedImage);
    temp->gridNumber = grdNmbr;

    x = x/34;
    x = (x*34) + 22;
    y = y/34;
    y = (y*34) + 10;

    temp->towerItem->moveBy(x, y);
    towers.push_back(temp);
    //loaded = false;
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
        loadedImage = tower1Image;
        break;
    case 2:
        loaded = true;
        loadedImage = tower2Image;
        break;
    case 3:
        loaded = true;
        loadedImage = tower3Image;
        break;
    default:
        loaded = false;
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
            //printMsg("Castle hit!");
            //QTimer::singleShot(500, this, SLOT(clearMessage()));
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
        //printMsg("Monster killed!");
        //QTimer::singleShot(500, this, SLOT(clearMessage()));
    }
}

void View::clearMessage()
{
    messageBoard->setPlainText("");
}

void View::printMsg(QString msg)
{
    messageBoard->setPlainText(msg);
    window->setScene(scene);
}

void View::drawAroundPath(int *pth, int pthSz)
{
    QPixmap *path = new QPixmap("resources/softPath.png");//redTile.pngbrownPath.pngladyPath.pngpuzzlePath.pngmarble.png
    *path = path->scaled(34, 34);

    //QPixmap *back = new QPixmap("resources/dirt.png");//grass.pngblackMarble.png
    //*back = back->scaled(578,408);

    QGraphicsPixmapItem *p;//,
                        //*g = scene->addPixmap(*back);
    //g->moveBy(22,10);

    bool found;
    int x, y;
    for (int grdNmbr = 1; grdNmbr < 205; grdNmbr++)
    {
        found = false;
        if (grdNmbr%17 == 0)
        {
            x = 566;
        }
        else
        {
            x = (((grdNmbr%17)-1)*34)+22;
        }
        y = (((grdNmbr-1)/17)*34)+ 10;

        for (int pathIndex = 0; pathIndex < pthSz; pathIndex++)
        {
            if (grdNmbr == pth[pathIndex])
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            p = scene->addPixmap(*path);
            p->moveBy(x,y);
        }
    }
}
