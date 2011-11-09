#ifndef VIEW_H
#define VIEW_H

#include "include/ClickableArea.h"
#include <QWidget>
#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QVector>

class View : public QWidget
{
    Q_OBJECT

private:
    struct Enemy
    {
        QGraphicsPixmapItem* monsterItem;
        int gridNumber;
    };
    struct Tower
    {
        QGraphicsPixmapItem* towerItem;
        int gridNumber;
    };

    bool loaded;

    QVector<Enemy*> monsters;
    QVector<Tower*> towers;

    ClickableArea *gameGrid, *towerGrid;
    QPixmap *towerImage, *monsterImage;
    QPushButton *start_quit;
    QGraphicsPixmapItem *background, *selection1;
    QGraphicsScene *scene;
    QGraphicsTextItem *score, *money, *health, *messageBoard;
    QGraphicsView *window;

public:
    explicit View( QWidget * parent = 0 );

    ClickableArea * getGameGrid();
    ClickableArea * getTowerGrid();
    QPushButton * getStart_Quit();
    QGraphicsView * getWindow();

    void addMonster();
    void addTower(int x, int y, int grdNmbr);
    bool isLoaded();
    void updateStats(int hlth, int mny, int scr);
    void printMonsters();
    void incrementMonsters(int *pth, int pthSz);
    void kill(QVector<int>);
    void printMsg(QString);
    void drawAroundPath(int *pth, int pthSz);

public slots:
    void loadTower(int twrChc);
    void clearMessage();

};

#endif // VIEW_H
