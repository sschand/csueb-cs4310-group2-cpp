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
                int FirePower; //holds fire power of the tower
		int Cost_Value;//holds the cost it has to buy the tower
                int Shot_Speed;//holds the shot speed of the tower (intervals)

                int damage;

                int shotCounter;
                int enemyInSight;

	public:
		Tower1() //constructor
		{
                        //setTower1(10,10,3,0);//remember to change the grid number and attributes using the default constructor to give each tower
                                             //a diferent grid number

                    damage = 10;
                    shotCounter = 3;
                    enemyInSight = false;
                }

                Tower1(int fp, int cv, int ss, int gn) //this constructor will be used once we figure out what tower tha gamer will buy or purchase.
		{
                        setTower1(fp,cv,ss,gn);
		}

                Tower1(const Tower1 &obj)//copy constructor that accepts a Tower objects and makes a copy.
                {
                    setTower1(obj.FirePower,obj.Cost_Value,obj.Shot_Speed,obj.Grid_Number);

                }

                Tower1(int grdNumber);


                int getFirePower(); //returns the fire power
                int getCost_Value(); //returns the value or amount needed to buy the tower
                int getShot_Speed();  //returns the shot speed of teh tower
                int getGrid_Number();
                void setGrid_Number(int);
                void setTower1(int,int,int,int);

                int getDamage();
                int getShotCounter();
                void takeShot();
                void resetShotCounter();
                bool enemyIsInSight();
                void setSight(bool enemyInSght);

};
#endif
