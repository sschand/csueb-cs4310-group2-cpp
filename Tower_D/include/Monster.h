#ifndef MONSTER_H
#define MONSTER_H

class Monster
{

private:
    int damage;
    int gridNumber;

public:
    Monster();
    Monster(int dmg);
    int getGridNumber();
    void setGridNumber(int grdNmbr);
    int getDamage();
    void hit(int dmg);

};

#endif // MONSTER_H