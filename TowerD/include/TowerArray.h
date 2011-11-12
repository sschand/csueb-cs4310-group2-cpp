#ifndef ARRAYTOWERS_H
#define ARRAYTOWERS_H
#include "..\include\Model.h"
#include "..\include\Tower1.h"
#include "..\include\GraphicsItem.h"
#include "..\include\Castle.h"

class	ArrayTowers : public GraphicsItem	// ArrayTowers class declaration "Inherited from graphics item"
{
        private:
                Tower1 towers[3];
        public:
                ArrayTowers ( const Tower1 &t1 , const Tower1 &t2 , const Tower1 &t3 )
                {
                        towers[0] = t1;
                        towers[1] = t2;
                        towers[2] = t3;
                }
                Tower1 get_tower1()
                {
                    return towers[0];
                }

                Tower1 get_tower2()
                {
                    return towers[1];
                }

                Tower1 get_tower3()
                {
                    return towers[2];
                }
               /* void putTowerT(int tower_type)
                {
                    if(tower_type = 1)
                    {
                        towers[0].
                    }

                }*/


};

#endif
