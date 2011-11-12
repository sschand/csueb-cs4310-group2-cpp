#ifndef MONSTERARRAY_H
#define MONSTERARRAY_H
#include "..\include\Model.h"
#include "..\include\Monster.h"
#include "..\include\GraphicsItem.h"
#include "..\include\Castle.h"
#include "..\include\ArrayPath"

class	ArrayTowers : public GraphicsItem	// ArrayTowers class declaration "Inherited from graphics item"
{
        private:
                Monster monsters[3];
        public:
                ArrayMonster ( const Monster &m1 , const Monster &m2 , const Monster &m3 )
                {
                        monsters[0] = m1;
                        monsters[1] = m2;
                        monsters[2] = m3;
                }
                Monster get_monsters()
                {
                    return monsters[0];
                }

                Monster get_monsters()
                {
                    return monsters[1];
                }

                Monster get_monster3()
                {
                    return monsters[2];
                }
                Monster set_monster(const Monster &m1, int Position)
                {
                    if(Position < monsters.size()-1){
                    monsters[Position]= m1;
                }
                }


};

#endif


#endif // MONSTERARRAY_H
