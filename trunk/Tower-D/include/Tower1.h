#ifndef TOWER1_H
#define TOWER1_H
#include "..\include\GraphicsItem.h"

/*Model
/
/ This is a class that creates an object and is part of the model. It holds the information for one of the 4 towers that will be part of the game.
/ Later on as we progress we will be defining other function as friends to be able to send them what ever disired
/ information. Weather it be the controller and or view.
/
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
*/

class Tower1 : public GraphicsItem //tower class declaration inherits from graphics item
{
	private:
                int damage;
                int enemyInSight;
                int shotCounter;
                int Shot_Speed;


	public:
		Tower1() //constructor
		{
                   setTower1(10,false,3,0,2);//remember to change the grid number and attributes using the default constructor to give each tower
                                             //a diferent grid number
                }

                Tower1(int dm, bool enm, int shc, int gn, int ss) //this constructor will be used once we figure out what tower tha gamer will buy or purchase.
		{
                        setTower1(dm,shc,enm,gn,ss);
		}

                Tower1(const Tower1 &obj)//copy constructor that accepts a Tower objects and makes a copy.
                {
                    setTower1(obj.damage,obj.enemyInSight,obj.shotCounter,obj.Grid_Number,obj.Shot_Speed);

                }

                Tower1(int grdNumber)
                {
                    setTower1(1,false,0,grdNumber,2);
                }

                int getDamage();
                bool getEnemyinSight();
                int getShotCounter();
                int getGrid_Number();
                int getIndex_tower_type();
                void setTower1(int,bool,int,int,int);
                void setDamage(int);
                void setshotCounter(int);
                void setSight(bool enemyInSght);
                void setGrid_Number(int);
                void takeShot();
                void resetShotCounter();
                bool enemyIsInSight();
                int getShotSpeed();
                void setShotSpeed(int);
};
#endif
