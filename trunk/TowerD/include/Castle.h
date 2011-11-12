#ifndef CASTLE_H
#define CASTLE_H
#include "..\include\GraphicsItem.h"

/*Castle
/
/ This is a class that creates an object that is part of the model. It holds the information for the castle of the game.
/ Later on as we progress we will be defining other functions as friends to have be able to send them what ever disired
/ information they need. Weather it be the controller and or view.
/
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
*/

class Castle : public GraphicsItem //Castle is a child of Graphics Item.
{
	private:
                int health; //holds the health of the castle
                int money;
                int score;
	public:
                Castle() //default constructor
                {
                    setCastle(100,500,0,68);
		}

                Castle(int hlth, int mny, int scr, int gdn) //constuctor
                {
                    setCastle(hlth, mny, scr, gdn);
                }

                Castle(const Castle &obj) //copy constructor
                {
                    setCastle(obj.health,obj.money,obj.score,obj.Grid_Number);
                }

                int getHealth(); //gets current health of the castle
                int getGridNum();//returns grid number of castle
                void set_GridNum(int);//sets grid number of castle
                void setCastle(int,int,int,int);//a fucntion that resets the castles private members to any values desired.
                void subtractHealth(int hlth);//used to subtract the health variable. Used when monsters reach castle and cause damage.

                int getMoney();
                int getScore();
                void spendMoney(int mny);
                void addScore(int scr);
};
#endif


