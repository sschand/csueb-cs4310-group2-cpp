#ifndef TOWER_H
#define TOWER_H

class Tower
{

private:
    int damage;
    int gridNumber;
    int shotCounter;
    bool enemyInSight;

public:
    Tower(int grdNmbr);

    int getGridNumber();
    int getDamage();
    int getShotCounter();
    void takeShot();
    void resetShotCounter();
    bool enemyIsInSight();
    void setSight(bool enemyInSght);

};

#endif // TOWER_H
