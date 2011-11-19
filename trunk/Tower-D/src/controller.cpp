#include "include/Controller.h"

Controller::Controller(QWidget *parent) :
    QWidget(parent)
{
}

void Controller::addViewModel(View *v, Model *m)
{
    timeInterval = 200;
    view = v;

    QObject::connect(view->getStart_Quit(), SIGNAL(clicked()), this, SLOT(connectQuit()));

    model = m;

    view->updateStats(model->getCastle()->getHealth(),model->getCastle()->getMoney(),model->getCastle()->getScore());

    QObject::connect(view->getGameGrid(), SIGNAL(clicked()), this, SLOT(addTower()));

    QObject::connect(view->getTowerGrid(), SIGNAL(clicked()), this, SLOT(towerChoice()));
    QObject::connect(this, SIGNAL(validTower(int)), view, SLOT(loadTower(int)));

    waveTimer = new QTimer;
    waveTimer->setInterval(timeInterval*2);

    //the createMonster interval value must be less than
    //the gameTimer interval value
    createMonster = new QTimer;
    createMonster->setInterval(timeInterval);

    gameTimer = new QTimer;
    gameTimer->setInterval(58*timeInterval);

    QObject::connect(waveTimer, SIGNAL(timeout()), this, SLOT(stopClocks()));

    QObject::connect(createMonster, SIGNAL(timeout()), this, SLOT(addMonster()));
    QObject::connect(createMonster, SIGNAL(timeout()), this, SLOT(incrementMonsters()));

    QObject::connect(gameTimer, SIGNAL(timeout()), this, SLOT(nextLevel()));

    view->drawAroundPath(model->getArray_path()->getPath(), model->getArray_path()->getPathSize());

}

void Controller::addTower()
{
    if (view->isLoaded())
    {
        int x = QCursor::pos().x() - view->getWindow()->window()->pos().x() - view->getGameGrid()->pos().x() - 9;
        int y = QCursor::pos().y() - view->getWindow()->window()->pos().y() - view->getGameGrid()->pos().y() - 29;

        int gridNumber = ((x/34)+1)+(y/34*17);

        bool grdNmbrInPth = false;
        for (int index = 0; index < model->getArray_path()->getPathSize(); index++)
        {
            if (gridNumber == model->getArray_path()->getPath()[index])
            {
                grdNmbrInPth = true;
                break;
            }
        }
        if(gridNumber < 205)
        {
            if (!grdNmbrInPth && (model->getCastle()->getMoney() >= 100) && model->addTower(gridNumber, view->getTower_type_from_view()))
            {
                view->addTower(x, y, gridNumber);
                view->updateStats(model->getCastle()->getHealth(),model->getCastle()->getMoney(),model->getCastle()->getScore());
            }
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
    else if (x > 51 && x < 90)
    {
        emit validTower(2);
    }
    else if (x > 102 && x < 141)
    {
        emit validTower(3);
    }
    else if (x > 144 && x < 183)
    {
        emit validTower(4);
    }
}

void Controller::addMonster()
{
    model->addMonster();
    view->addMonster();
}

void Controller::incrementMonsters()
{
    view->incrementMonsters(model->getArray_path()->getPath(), model->getArray_path()->getPathSize());
    model->incrementMonsters();

    if (model->getCastle()->getHealth() < 1)
    {
        createMonster->stop();
        gameTimer->stop();
        waveTimer->stop();
        endGame(false);
    }
    else
    {
        view->kill(model->towersTakeShot());
    }

    view->updateStats(model->getCastle()->getHealth(),model->getCastle()->getMoney(),model->getCastle()->getScore());
}

void Controller::connectQuit()
{
    QObject::disconnect(view->getStart_Quit(), SIGNAL(clicked()), this, SLOT(connectQuit()));
    QObject::connect(view->getStart_Quit(), SIGNAL(clicked()), view->getWindow(), SLOT(close()));
    view->getStart_Quit()->setText("quit");

    model->nextLevel();

    waveTimer->start();
    createMonster->start();

    view->clearMessage();
}

void Controller::stopClocks()
{
    QObject::disconnect(createMonster, SIGNAL(timeout()), this, SLOT(addMonster()));

    waveTimer->stop();
    gameTimer->setInterval(waveTimer->interval()+(58*timeInterval));
    gameTimer->start();
}

void Controller::nextLevel()
{
    model->nextLevel();

    if (model->getLevel() < 16)
    {
        QObject::connect(createMonster, SIGNAL(timeout()), this, SLOT(addMonster()));

        gameTimer->stop();
        waveTimer->setInterval(model->getLevel()*timeInterval*2);
        waveTimer->start();
    }
    else if (model->getLevel() == 16)
    {
        model->getCastle()->subtractHealth(model->getCastle()->getHealth()-1);
        addMonster();
    }
    else
    {
        gameTimer->stop();
        endGame(true);
    }
}

void Controller::endGame(bool win)
{
    if (win)
    {
        QObject::disconnect(waveTimer, SIGNAL(timeout()), this, SLOT(stopClocks()));
        QObject::disconnect(createMonster, SIGNAL(timeout()), this, SLOT(incrementMonsters()));
        QObject::disconnect(view->getGameGrid(), SIGNAL(clicked()), this, SLOT(addTower()));
        QObject::disconnect(view->getTowerGrid(), SIGNAL(clicked()), this, SLOT(towerChoice()));
        QObject::disconnect(this, SIGNAL(validTower(int)), view, SLOT(loadTower(int)));
        QObject::disconnect(gameTimer, SIGNAL(timeout()), this, SLOT(nextLevel()));
        view->printMsg("You win!");
    }
    else
    {
        QObject::disconnect(createMonster, SIGNAL(timeout()), this, SLOT(addMonster()));
        QObject::disconnect(waveTimer, SIGNAL(timeout()), this, SLOT(stopClocks()));
        QObject::disconnect(createMonster, SIGNAL(timeout()), this, SLOT(incrementMonsters()));
        QObject::disconnect(view->getGameGrid(), SIGNAL(clicked()), this, SLOT(addTower()));
        QObject::disconnect(view->getTowerGrid(), SIGNAL(clicked()), this, SLOT(towerChoice()));
        QObject::disconnect(this, SIGNAL(validTower(int)), view, SLOT(loadTower(int)));
        view->printMsg("You lose!");
    }
}

