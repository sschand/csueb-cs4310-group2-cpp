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
                Tower1 putTowerT(int gn)
                {
                    int grdno = 0;
                    grdno = gn;
                    if (grdno == 205)
                    {
                        return towers[0];
                    }
                    else if (grdno == 206)
                    {
                        return towers[1];
                    }
                    else if (grdno == 207)
                    {
                        return towers[2];
                    }
                }

};

#endif
