#ifndef ARRAYPATH_H
#define ARRAYPATH_H
#include <time.h>
#include <stdlib.h>
#include <iostream>

/*ArrayPath
/
/ This is a class that creates an arraypath interface. It holds the array for one of the path that will be part of the game.
/
/ Created by : Sharol Chand
/              Paola Medina
/              Emilio E. Venegas
/              Adam Vierra
*/

class ArrayPath //This object holds the array "path" monsters will be travelling on.
{
        private:

            int * path;
            int pathSize;
            int start;
            int end;

        public:
            ArrayPath()//constructor sets array size an initializes the array with the grid numbers of the game board.
            {
                pathSize = 100;
                path = new int[pathSize];
                int x = 0;
                srand(time(0));
                bool redo = false;
                int direction = 0;
                for (x = 0; x < 100; x++) {
                    if (x==0) {
                        path[0] = (rand() % 12) * 17 + 1;
                        start = path[0];
                    } else {
                        redo = false;
                        direction = rand() % 3;
                        switch (direction) {
                        case 0:
                            if (path[x - 1] <= 17) redo = true;
                            if (!redo) {
                                path[x] = path[x - 1] - 17;
                                for (int y = 0; y < x - 1; y++) {
                                    if (path[y]==path[x]||
                                        path[y]==path[x] - 17||
                                        path[y]==path[x] - 1||
                                        path[y]==path[x] + 1) redo = true;
                                }
                            }
                            break;
                        case 1:
                            if (path[x - 1] >= 188) redo = true;
                            if (!redo) {
                                path[x] = path[x - 1] + 17;
                                for (int y = 0; y < x - 1; y++) {
                                    if (path[y]==path[x]||
                                        path[y]==path[x] + 17||
                                        path[y]==path[x] - 1||
                                        path[y]==path[x] + 1) redo = true;
                                }
                            }
                            break;
                        case 2:
                            if (!redo) {
                                path[x] = path[x - 1] + 1;
                                for (int y = 0; y < x - 1; y++) {
                                    if (path[y]==path[x]||
                                        path[y]==path[x] - 17||
                                        path[y]==path[x] + 17) redo = true;
                                }
                            }
                            break;
                        }
                        if (path[x - 1] % 17 == 0) {
                            end = path[x - 1];
                            path[x] = 0;
                            pathSize = x;
                            x = 100;
                        } else if (redo) x--;
                    }
                }
            }

            int * getPath() //this function is used to access the path array through a pointer, and therefore returns the array.
            {
                return path;
            }

            int getPathSize()//this returns the size of the path array, which is used in some of the algorythms in the controller.
            {
                return pathSize;
            }

            int getPathStart() //Returns the first spot of the path
            {
                return start;
            }

            int getPathEnd() //Returns the last spot of the path
            {
                return end;
            }

};

#endif
