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

    upgrade = new QPushButton("Upgrade");
    upgrade->move(625, 155);
    upgrade->resize(75, 25);

    sell = new QPushButton("Sell");
    sell->move(625, 180);
    sell->resize(75, 25);

    scene->addWidget(gameGrid);
    scene->addWidget(towerGrid);

    monsterImage = new QPixmap("resources/greenMonster.png");//monster.pngdemon.pngblueMonster.png
    *monsterImage = monsterImage->scaled(34,34);

    tower1Image = new QPixmap("resources/tower.png");//rook.png
    *tower1Image = tower1Image->scaled(34,34);

    tower2Image = new QPixmap("resources/logo1.png");
    *tower2Image = tower2Image->scaled(34,34);

    tower3Image = new QPixmap("resources/logo2.png");
    *tower3Image = tower3Image->scaled(34,34);

    tower4Image = new QPixmap("resources/tower4.png");
    *tower4Image = tower4Image->scaled(34,34);

    t1 = new QPixmap("resources/tower.png");
    t2 = new QPixmap("resources/logo1.png");
    t3 = new QPixmap("resources/logo2.png");
    t4 = new QPixmap("resources/tower4.png");
    *t1 = t1->scaled(65,65);
    *t2 = t2->scaled(65,65);
    *t3 = t3->scaled(65,65);
    *t4 = t4->scaled(65,65);

    QPixmap *back = new QPixmap("resources/TowerDBase.png");//resources/PositionTestBase.png
    *back = back->scaledToWidth(801);

    // Draws the background grid
    QGraphicsRectItem *rect; // makes a rectangle item pointer
    QGradient *gradient = new QLinearGradient(QPoint(50,100),QPoint(200,400));
    gradient->setColorAt(0,Qt::green);
    gradient->setColorAt(.55,Qt::darkGreen);
    gradient->setColorAt(1,Qt::green);
    gradient->setSpread(gradient->ReflectSpread);
    QPen blackPen(Qt::black); // sets the pen black
    blackPen.setWidth(6); // sets the width to 6 pixels
    rect= scene->addRect(0,0,801,587,blackPen,QBrush(*gradient)); // draws the overall rectangle 801 pixels by 587 with black borders white fill
    gradient->stops();
    rect= scene->addRect(0,425,801,76,blackPen,QBrush(*gradient)); // draws the tower rectangle box
    gradient->stops();
    rect= scene->addRect(620,0,181,225,blackPen,QBrush(*gradient)); // draws the top right box
    gradient->stops();
    rect= scene->addRect(620,225,181,66,blackPen,QBrush(*gradient)); // draws the score box
    gradient->stops();
    rect= scene->addRect(620,291,181,67,blackPen,QBrush(*gradient)); // draws the money box
    gradient->stops();
    rect= scene->addRect(620,358,181,67,blackPen,QBrush(*gradient)); // draws the health box
    gradient->stops();


//   background    = scene->addPixmap(*back);
    s1    = scene->addPixmap(*t1);
    s1->moveBy(625, 35);
    s1->hide();
    s2    = scene->addPixmap(*t2);
    s2->moveBy(625, 35);
    s2->hide();
    s3    = scene->addPixmap(*t3);
    s3->moveBy(625, 35);
    s3->hide();
    s4    = scene->addPixmap(*t4);
    s4->moveBy(625, 35);
    s4->hide();
    selection1    = scene->addPixmap(*tower1Image);
    selection2    = scene->addPixmap(*tower2Image);
    selection3    = scene->addPixmap(*tower3Image);
    selection4    = scene->addPixmap(*tower4Image);
    score         = scene->addText(QString::number(0), QFont("Times", 14, 2));
    money         = scene->addText(QString::number(0), QFont("Times", 14, 2));
    health        = scene->addText(QString::number(0), QFont("Times", 14, 2));
    level         = scene->addText(QString::number(0), QFont("Times", 14, 2));
    damage        = scene->addText(QString::number(0), QFont("Times", 14, 2));
    ShotSpee      = scene->addText(QString::number(0), QFont("Times", 14, 2));
    damshow       = scene->addText(QString::number(0), QFont("Times", 14, 2));
    Shotshow      = scene->addText(QString::number(0), QFont("Times", 14, 2));
    cost          = scene->addText(QString::number(0), QFont("Times", 10, 2));
    cost1         = scene->addText(QString::number(0), QFont("Times", 10, 2));
    messageBoard  = scene->addText("Click start to begin your game.", QFont("Times", 16, 2));
                    scene->addWidget(start_quit);
                    scene->addWidget(upgrade);
                    scene->addWidget(sell);
                    upgrade->hide();
                    sell->hide();
                    damage->setPlainText("Damage");
                    ShotSpee->setPlainText("Shot Speed");
                    damshow->moveBy(700,100);
                    Shotshow->moveBy(750,125);
                    damage->moveBy(625,100);
                    ShotSpee->moveBy(625,125);
                    cost->moveBy(700,155);
                    cost1->moveBy(700,180);
                    cost1->hide();
                    cost->hide();
                    damage->hide();
                    ShotSpee->hide();
                    damshow->hide();
                    Shotshow->hide();


    QGraphicsTextItem * item = scene->addText("$100", QFont("Times", 12, 10));
    QGraphicsTextItem * item2 = scene->addText("$200", QFont("Times", 12, 10));//This adds the text for the cost value of the towers.(e.v. 11/16/11)
    QGraphicsTextItem * item3 = scene->addText("$300", QFont("Times", 12, 10));//This adds the text for the cost value of the towers.(e.v. 11/16/11)
    QGraphicsTextItem * item4 = scene->addText("$400", QFont("Times", 12, 10));

    QGraphicsTextItem * item5 = scene->addText("Score",QFont("Times",12,10)); // adds the score text
    QGraphicsTextItem * item6 = scene->addText("Money",QFont("Times",12,10)); // adds the money text
    QGraphicsTextItem * item7 = scene->addText("Health",QFont("Times",12,10)); // adds the health text
    QGraphicsTextItem * item8 = scene->addText("Towers",QFont("Times",12,10)); // adds the tower text
    QGraphicsTextItem * item9 = scene->addText("Level",QFont("Times",12,10)); // addes the message text
    QGraphicsTextItem * item10 = scene->addText("Tower-D",QFont("Times",18,10)); // addes the Tower-D text


    item->moveBy(136, 475);
    item->setDefaultTextColor(QColor(0,0,0));

    item2->moveBy(189, 475);//This adds the text for the cost value of the towers.(e.v. 11/16/11)
    item2->setDefaultTextColor(QColor(0,0,0));

    item3->moveBy(240, 475);//This adds the text for the cost value of the towers.(e.v. 11/16/11)
    item3->setDefaultTextColor(QColor(0,0,0));

    item4->moveBy(291, 475);
    item4->setDefaultTextColor(QColor(0,0,0));

    item5->moveBy(625,230); // adds score text
    item5->setDefaultTextColor(QColor(0,0,0));

    item6->moveBy(625,296); // adds money text
    item6->setDefaultTextColor(QColor(0,0,0));

    item7->moveBy(625,363); // adds health text
    item7->setDefaultTextColor(QColor(0,0,0));

    item8->moveBy(5,430); // adds tower text
    item8->setDefaultTextColor(QColor(0,0,0));

    item9->moveBy(5,506); // adds message text
    item9->setDefaultTextColor(QColor(0,0,0));

    item10->moveBy(625,5); // adds message text
    item10->setDefaultTextColor(QColor(0,0,0));

    selection1->moveBy(140,444);
    selection1->scale(1.1176,1.1176);
    selection2->moveBy(191,444);
    selection2->scale(1.1176,1.1176);
    selection3->moveBy(242,444);
    selection3->scale(1.1176,1.1176);
    selection4->moveBy(292,444);
    selection4->scale(1.1176,1.1176);
    score->moveBy(715, 250);
    money->moveBy(715, 315);
    health->moveBy(715, 380);
    level->moveBy(50,506);
    messageBoard->moveBy(120, 530);

    window->setScene(scene);
    window->resize(810, 600);
    window->show();
    window->setMaximumSize(810,600);
    window->setMinimumSize(809,599);
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
QPushButton * View::getUpgrade()
{
    return upgrade;
}
QPushButton * View::getSell()
{
    return sell;
}

QGraphicsView * View::getWindow()
{
    return window;
}

void View::addMonster(int grdNmbr)
{
    Enemy * temp = new Enemy;
    temp->monsterItem = scene->addPixmap(*monsterImage);
    temp->gridNumber = grdNmbr;

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
    TwrType = twrChc; //(e.v.,j.h)At this point the user has made a tower selection on the view, and has clicked it. This TwrType int will be set with the index(tower choice made by user) so that the addtower() in the model can receive the index and create the right tower type in the model.

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
    case 4:
        loaded = true;
        loadedImage = tower4Image;
        break;
    default:
        loaded = false;
        break;
    }
}

void View::updateStats(int hlth, int mny, int scr, int lvl)
{
    health->setPlainText(QString::number(hlth));

    money->setPlainText(QString::number(mny));

    score->setPlainText(QString::number(scr));

    level->setPlainText(QString::number(lvl));


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
    QGraphicsRectItem *rect;
    QPen redPen(Qt::red);
    redPen.setWidth(1);
    QGradient *gradient1 = new QLinearGradient(QPoint(0,0),QPoint(34,34));
    gradient1->setColorAt(0,Qt::black);
    gradient1->setColorAt(.55,Qt::darkGray);
    gradient1->setColorAt(1,Qt::black);
    gradient1->setSpread(gradient1->ReflectSpread);
  //  QPixmap *path = new QPixmap("resources/softPath.png");//redTile.pngbrownPath.pngladyPath.pngpuzzlePath.pngmarble.png
  //  *path = path->scaled(34, 34);

    //QPixmap *back = new QPixmap("resources/dirt.png");//grass.pngblackMarble.png
    //*back = back->scaled(578,408);

    QGraphicsItem *r;
   // QGraphicsPixmapItem *p;//,
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
            rect =scene->addRect(0,0,34,34,redPen,QBrush(*gradient1));
            gradient1->stops();
            r = rect;
            r->moveBy(x,y);
          //  p = scene->addPixmap(*path);
          //  p->moveBy(x,y);
        }
    }
}
void View::drawBox(int grdNmbr)
{
    QGraphicsRectItem *rect;
    QPen GreenPen(Qt::green);
    GreenPen.setWidth(1);
    QGradient *gradient2 = new QLinearGradient(QPoint(0,0),QPoint(34,34));
    gradient2->setColorAt(0,Qt::blue);
    gradient2->setColorAt(.55,Qt::darkBlue);
    gradient2->setColorAt(1,Qt::blue);
    gradient2->setSpread(gradient2->ReflectSpread);
     QGraphicsItem *r;
    int x, y;

        if (grdNmbr%17 == 0)
        {
            x = 566;
        }
        else
        {
            x = (((grdNmbr%17)-1)*34)+22;
        }
        y = (((grdNmbr-1)/17)*34)+ 10;
{
        rect =scene->addRect(0,0,34,34,GreenPen,QBrush(*gradient2));
        gradient2->stops();
        r = rect;
        r->moveBy(x,y);

    }
}

void View::drawGrid()
{
    QGraphicsRectItem *rect;
    QPen GreenPen(Qt::green);
    GreenPen.setWidth(1);
    QGradient *gradient2 = new QLinearGradient(QPoint(0,0),QPoint(34,34));
    gradient2->setColorAt(0,Qt::blue);
    gradient2->setColorAt(.55,Qt::darkBlue);
    gradient2->setColorAt(1,Qt::blue);
    gradient2->setSpread(gradient2->ReflectSpread);

    QGraphicsItem *r;

    int x, y;
    for (int grdNmbr = 1; grdNmbr < 205; grdNmbr++)
    {
        if (grdNmbr%17 == 0)
        {
            x = 566;
        }
        else
        {
            x = (((grdNmbr%17)-1)*34)+22;
        }
        y = (((grdNmbr-1)/17)*34)+ 10;



        {
            rect =scene->addRect(0,0,34,34,GreenPen,QBrush(*gradient2));
            gradient2->stops();
            r = rect;
            r->moveBy(x,y);

        }
    }

}
          // My attempt to have the top right corner actually display something
void View::drawTopRight(int spot, int dam , int shot, int cos, int cos1) //620,0,181,225, where it starts and how long it is
{
    switch(spot)
    {
    case 1:
        s1->show();
        break;
    case 2:
        s2->show();
        break;
    case 3:
        s3->show();
        break;
    case 4:
        s4->show();
        break;
    }

    damshow->setPlainText(QString::number(dam));
    Shotshow->setPlainText(QString::number(shot));
    cost->setPlainText(QString::number(cos));
    cost1->setPlainText(QString("Get " )+QString::number(cos1));
    upgrade->show();
    sell->show();
    damage->show();
    ShotSpee->show();
    damshow->show();
    Shotshow->show();
    cost->show();
    cost1->show();
}

void View::hideTopRight()
{
    upgrade->hide();
    sell->hide();
    damage->hide();
    ShotSpee->hide();
    damshow->hide();
    Shotshow->hide();
    cost1->hide();
    cost->hide();
    s1->hide();
    s2->hide();
    s3->hide();
    s4->hide();

}

int View::getTower_type_from_view() //(e.v. 11/16/11)This fucntion is used to return the tower type index from the view. Mainly used in the crontroller to send retrieve the index from the selected tower and send it to the addtower() function in the model. Used in the controller.cpp line 65.
{
    return TwrType;
}
