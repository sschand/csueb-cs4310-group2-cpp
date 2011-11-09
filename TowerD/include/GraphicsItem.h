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

                int Grid_Number;

        private:

        public:

                GraphicsItem()
                {
                    Grid_Number = 0;

                }                
};
#endif
