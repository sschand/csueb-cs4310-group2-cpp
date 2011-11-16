#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

/*GraphicsItem
/
/ This is a class that was created to demonstrate the us of inheritance. It holds the grid number value whic is inherited by
/ the rest of the objects that will be on the board. The towers and Castle.
/
/
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
*/

class GraphicsItem //"will be inherited by other classes"
{
        protected:

                int Grid_Number; //(e.v. 11/15/11)holds the grid number
                int Tower_type_index; //(e.v. 11/15/11)holds an index number that will be used to differentiate the different types of towers.

        private:

        public:

                GraphicsItem()
                {
                    Grid_Number = 0;
                    Tower_type_index = 0;

                }
                void setTowerTypeindex(int tp)
                {
                    Tower_type_index = tp;
                }

                int getIndex()//(e.v. 11/15/11)used to retrive tower index.
                {
                    return Tower_type_index;
                }
};
#endif
