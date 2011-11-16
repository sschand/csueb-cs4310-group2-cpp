#ifndef ARRAYTOWERS_H
#define ARRAYTOWERS_H
#include "..\include\Model.h"
#include "..\include\Tower1.h"
#include "..\include\GraphicsItem.h"
#include "..\include\Castle.h"

class	ArrayTowers : public GraphicsItem	// ArrayTowers class declaration "Inherited from graphics item"
{
        private:

        public:
                Tower1 * choices;

                ArrayTowers ( const Tower1 &t1 , const Tower1 &t2 , const Tower1 &t3 )
                {
                    choices = new Tower1[3];
                        choices[0] = t1;
                        choices[1] = t2;
                        choices[2] = t3;
                }
                const Tower1 get_tower1()
                {
                    return choices[0];
                }

                const Tower1 get_tower2()
                {
                    return choices[1];
                }

                const Tower1 get_tower3()
                {
                    return choices[3];
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
