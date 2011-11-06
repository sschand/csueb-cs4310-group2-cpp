#include "include/Controller.h"

Controller::Controller(QWidget *parent) :
    QWidget(parent)
{
}

void Controller::addViewModel(View *v, Model *m)
{
    view = v;

    QObject::connect(view->getStart_Quit(), SIGNAL(clicked()), this, SLOT(connectQuit()));

    model = m;

    view->updateStats(model->getCastle()->getHealth(),model->getCastle()->getMoney(),model->getCastle()->getScore());

    QObject::connect(view->getGameGrid(), SIGNAL(clicked()), this, SLOT(addTower()));

    QObject::connect(view->getTowerGrid(), SIGNAL(clicked()), this, SLOT(towerChoice()));
    QObject::connect(this, SIGNAL(validTower(int)), view, SLOT(loadTower(int)));
}

void Controller::addTower()
{
    if (view->isLoaded())
    {
        int x = QCursor::pos().x() - view->getWindow()->window()->pos().x() - view->getGameGrid()->pos().x() - 9;
        int y = QCursor::pos().y() - view->getWindow()->window()->pos().y() - view->getGameGrid()->pos().y() - 29;

        int gridNumber = ((x/34)+1)+(y/34*17);

        bool grdNmbrInPth = false;
        for (int index = 0; index < model->getPathSize(); index++)
        {
            if (gridNumber == model->getPath()[index])
            {
                grdNmbrInPth = true;
                break;
            }
        }

        if (!grdNmbrInPth && model->addTower(gridNumber))
        {
            view->addTower(x, y, gridNumber);
            view->updateStats(model->getCastle()->getHealth(),model->getCastle()->getMoney(),model->getCastle()->getScore());
        }
    }
}

void Controller::towerChoice()
{
    int x = QCursor::pos().x() - view->getWindow()->window()->pos().x() - view->getTowerGrid()->pos().x() - 9;

    if (x < 39)
    {
        emit validTower(1);
    }
}

void Controller::addMonster()
{
    model->addMonster();
    view->addMonster();
}

void Controller::incrementMonsters()
{

    view->incrementMonsters(model->getPath(), model->getPathSize());
    model->incrementMonsters();

    view->updateStats(model->getCastle()->getHealth(),model->getCastle()->getMoney(),model->getCastle()->getScore());
    if (model->getCastle()->getHealth() == 0)
    {
        gameTimer->stop();
        createMonster->stop();

        QObject::disconnect(view->getGameGrid(), SIGNAL(clicked()), this, SLOT(addTower()));

        QObject::disconnect(view->getTowerGrid(), SIGNAL(clicked()), this, SLOT(towerChoice()));
        QObject::disconnect(this, SIGNAL(validTower(int)), view, SLOT(loadTower(int)));
    }
    else
    {
        view->kill(model->towersTakeShot());
    }
}

void Controller::connectQuit()
{
    QObject::disconnect(view->getStart_Quit(), SIGNAL(clicked()), this, SLOT(connectQuit()));
    QObject::connect(view->getStart_Quit(), SIGNAL(clicked()), view->getWindow(), SLOT(close()));
    view->getStart_Quit()->setText("Quit");
    view->messageBoard->setPlainText("Press Quit to exit game");

    createMonster = new QTimer;
    createMonster->setInterval(1000);
    createMonster->start();

    QObject::connect(createMonster, SIGNAL(timeout()), this, SLOT(addMonster()));

    gameTimer = new QTimer;
    gameTimer->setInterval(100);
    gameTimer->start();

    QObject::connect(gameTimer, SIGNAL(timeout()), this, SLOT(incrementMonsters()));

    view->addMonster();
    model->addMonster();

}
