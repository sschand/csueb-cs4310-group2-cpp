#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "include/Model.h"
#include "include/View.h"
#include <QTimer>
#include <QWidget>

class Controller : public QWidget
{
    Q_OBJECT

private:
    Model * model;
    View * view;

    int timeInterval;
    QTimer *waveTimer;
    QTimer *createMonster;
    QTimer *gameTimer;

public:
    explicit Controller( QWidget * parent = 0 );

    void addViewModel(View*, Model*);

signals:
    void validTower(int twrChc);

public slots:
    void addMonster();
    void towerChoice();
    void addTower();
    void incrementMonsters();
    void connectQuit();
    void stopClocks();
    void nextLevel();
    void endGame(bool win);

};

#endif // CONTROLLER_H
