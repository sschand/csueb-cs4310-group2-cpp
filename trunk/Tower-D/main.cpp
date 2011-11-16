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
 *       Chand, Sharol S
 *       Venegas, Emilio E..
 *       Henninger, Joshua M.
 *       Holland,Richard C.
 *       Medina, Martha Paola
 *       Vierra, Adam R.
 */

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
