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
