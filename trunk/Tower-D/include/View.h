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
    QPixmap *monsterImage, *tower1Image, *tower2Image, *tower3Image, *tower4Image, *loadedImage;
    QPushButton *start_quit;
    QGraphicsPixmapItem *background, *selection1, *selection2, *selection3, *selection4;
    QGraphicsScene *scene;
    QGraphicsTextItem *score, *money, *health, *messageBoard;
    QGraphicsView *window;
    int TwrType; //This tower tyoe index has the same function that the tower type has in the model. It serves as a reference to know what tower the users has clicked. It will be reset every time the user makes a tower choice.
                 //(e.v.,j.h. 11/16/11)
public:
    explicit View( QWidget * parent = 0 );

    ClickableArea * getGameGrid();
    ClickableArea * getTowerGrid();
    QPushButton * getStart_Quit();
    QGraphicsView * getWindow();

    void addMonster(int grdNmbr);
    void addTower(int x, int y, int grdNmbr);
    bool isLoaded();
    void updateStats(int hlth, int mny, int scr);
    void printMonsters();
    void incrementMonsters(int *pth, int pthSz);
    void kill(QVector<int>);
    void printMsg(QString);
    void drawAroundPath(int *pth, int pthSz);
    int getTower_type_from_view();
public slots:
    void loadTower(int twrChc);
    void clearMessage();
    void drawGrid();
    //void drawTopRight(int twrChc);

};

#endif // VIEW_H
