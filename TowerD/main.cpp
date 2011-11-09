//#include "include/Castle.h"
//#include "include/controller.h"
#include "include/Model.h"
#include "include/View.h"
#include "include/TowerArray.h"
#include <QApplication>
#include <iostream>

/*
 * Main for TowerD  ( Tower Defense ), a version created as a class project in CS4310 Fall 2011
 *   CSU Eastbay, Hayward, CA
 *
 *   The project will implement a GUI game similar to the classic Tower Defense game, but with
 *  variances based upon the preferences of our team members.
 *
 *   Tools for this project include CodeBlocks IDE and QtNokia (Qt4) to implement the GUI View and Controller interface for the game.
 *
 *   Team Members:
 *       Chand, Sharol S.
 *       Donat, Brian L.
 *       Henninger, Joshua M.
 *       Holland,Richard C.
 *       Medina, Martha Paola
 *       Shair, Vasiq
 *       Venegas, Emilio E.
 *       Vierra, Adam R.
 */
/*using namespace std;

int main(int argc, char* argv[])
{
    //Necessary for all qt applications
    QApplication app(argc, argv);

    //View is initialized in its own construtor
    View TDView;

    //Create a controller object
    Controller TDController;

    //addView adds a pointer to the TDView object in TDController
    //this function also does the appropriate QObject::connect()'s
    TDController.addView(&TDView);

    Model TD;
    Tower1 hj(100,100,78,23);
    TD.initialize_add_Tower(hj,99);

    TD.print();

    return app.exec();

}*/

#include "include/Controller.h"
#include "include/Model.h"
#include "include/View.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Controller controller;
    View view;
    Model model;

    controller.addViewModel(&view, &model);

    return app.exec();
}
