#ifndef ARRAYPATH_H
#define ARRAYPATH_H

/*ArrayPath
/
/ This is a class that creates an arraypath interface. It holds the array for one of the path that will be part of the game.
/
/ Created by : Sharol Chand
/              Paola Medina
/              Emilio E. Venegas
/
*/

class ArrayPath //This object holds the array "path" monsters will be travelling on.
{
        private:

            int * path;
            int pathSize;

        public:
            ArrayPath()//constructor sets array size an initializes the array with the grid numbers of the game board.
            {
                pathSize = 58;
                path = new int[pathSize];

                int x = 0;
                    path[x++] = 86;
                    path[x++] = 87;
                    path[x++] = 104;
                    path[x++] = 105;
                    path[x++] = 106;
                    path[x++] = 123;
                    path[x++] = 140;
                    path[x++] = 157;
                    path[x++] = 158;
                    path[x++] = 159;
                    path[x++] = 160;
                    path[x++] = 143;
                    path[x++] = 126;
                    path[x++] = 109;
                    path[x++] = 92;
                    path[x++] = 75;
                    path[x++] = 74;
                    path[x++] = 57;
                    path[x++] = 40;
                    path[x++] = 23;
                    path[x++] = 24;
                    path[x++] = 25;
                    path[x++] = 26;
                    path[x++] = 27;
                    path[x++] = 28;
                    path[x++] = 45;
                    path[x++] = 62;
                    path[x++] = 79;
                    path[x++] = 96;
                    path[x++] = 95;
                    path[x++] = 112;
                    path[x++] = 129;
                    path[x++] = 146;
                    path[x++] = 163;
                    path[x++] = 180;
                    path[x++] = 181;
                    path[x++] = 182;
                    path[x++] = 165;
                    path[x++] = 166;
                    path[x++] = 167;
                    path[x++] = 184;
                    path[x++] = 185;
                    path[x++] = 186;
                    path[x++] = 169;
                    path[x++] = 152;
                    path[x++] = 135;
                    path[x++] = 118;
                    path[x++] = 117;
                    path[x++] = 116;
                    path[x++] = 99;
                    path[x++] = 82;
                    path[x++] = 65;
                    path[x++] = 48;
                    path[x++] = 49;
                    path[x++] = 50;
                    path[x++] = 67;
                    path[x++] = 68;
                    path[x++] = 0;
            }

            int * getPath() //this function is used to access the path array through a pointer, and therefore returns the array.
            {
                return path;
            }

            int getPathSize()//this returns the size of the path array, which is used in some of the algorythms in the controller.
            {
                return pathSize;
            }

};

#endif
