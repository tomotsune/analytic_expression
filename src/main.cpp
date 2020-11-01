#include <iostream>
#include <QApplication>
#include "mainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/

    DAL dal{"11 +  1"};
    cout<<dal<<endl;
    cout<<dal.parseRPN().evaluate()<<endl;
}