#ifndef CASTLE_H
#define CASTLE_H

class Castle
{

private:
    int health;
    int money;
    int score;

public:
    Castle();

    int getHealth();
    int getMoney();
    int getScore();

    void subtractHealth(int hlth);
    void spendMoney(int mny);

};

#endif // CASTLE_H
