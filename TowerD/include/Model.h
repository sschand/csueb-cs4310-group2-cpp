#ifndef MODEL_H
#define MODEL_H
//#include "controller.h" //should the controller be in the model or in the view?
#include "include/Castle.h"
#include "include/Monster.h"
#include "include/Tower1.h"
#include "include/GraphicsItem.h"
#include "include/ArrayPath.h"
#include "include/TowerArray.h"
#include <QVector>
#include <QWidget>


/*Model
/
/ This is a class that creates a model interface. It holds the functions for one of the 4 towers that will be part of the game and the castle.
/ Later on as we progress we will be defining other function as friends to be able to send them what ever disired
/ information. Weather it be the controller and or view.
/
/
/ Created by : Emilio E. Venegas
/              Sharol Chand
/              Paola Medina
*/

class Model : QWidget //inherited from QWidget
{
        private:
            QVector <Tower1*> towers; //Creates a vector of Towers.
            QVector <Monster*> monsters;//Creates a vector of Monsters.
            ArrayPath * mns_path;// Creates a pointer that will point to the arry path that monsters will travel.
            Castle * castle;//Creates a pointer to the castle.
            char * gameTitle;
            int level;
            QVector<int> deadMonsters;
            Tower1 type1;
            Tower1 type2;
            Tower1 type3;
            ArrayTowers * atwr;
            void setTowerTypes()
            {
                atwr = new ArrayTowers(type1, type2, type3);

            }


        public:
                explicit Model( QWidget * parent = 0 ); //Constructor

                bool addTower(int/*,int*/);//we are going to match up the grid number being clicked,
                                   //to the grid number in one of the three towers that will be in the TowerArray object. Thus allowing us
                                   //to create a tower, by copying the tower object, of the correct Tower that is being selected by the user.
                void addMonster(); //adds a Monster.
                Castle * getCastle();
                ArrayPath * getArray_path();
                int getTowersSize();
                void incrementMonsters();
                void kill(int twrIndex, int mnstIndex);
                QVector<int> towersTakeShot();
                int getLevel();
                void nextLevel();
                int getMonsterSize();


};
#endif
