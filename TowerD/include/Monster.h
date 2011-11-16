#ifndef MONSTER_H
#define MONSTER_H
#include "..\include\GraphicsItem.h"


class Monster : public GraphicsItem	//monster class declaration "Inherited from graphics item"
{
        private:

                int Attack_Value_and_Health;

        public:
                Monster()//default constructor
                {
                    setMonster(10,0); //the zero is the default grid number.

                }

                Monster(int av_hlth,int grdn) //constructor
                {
                    setMonster(av_hlth,grdn);
                }

                Monster(const Monster &obj) //copy constructor
                {
                    setMonster(obj.Attack_Value_and_Health,obj.Grid_Number);
                }

                Monster(int dmg);

                int getAttact_Value_and_Health();
                int getGrid_Number();
                void setAttack_Value_and_Health(int);
                void setGrid_Number(int);
                void setMonster(int,int);//extra int is to set grid number.
                int getupdated_Damage();
                void hit(int dmg);


};

#endif
