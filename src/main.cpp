#include <iostream>
#include <QApplication>
#include "mainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
/*
    RPN rpn{ " 1   1 +"};
    cout<<rpn.evaluate()<<endl;*/
}