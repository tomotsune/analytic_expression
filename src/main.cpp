#include <iostream>
#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlComponent>
#include <QWindow>
#include "RPN.h"
#include "DAL.h"
int main(int argc, char *argv[]) {
/*    QGuiApplication app(argc, argv);

    QQmlComponent component(new QQmlApplicationEngine(), "qrc:/main.qml");
    QWindow *window = (QWindow *) component.create();
    window->show();*/

    DAL dal{"a+b*(c-d)-e/f"};
    std::cout<<dal.parseRPN();


  /*  return app.exec();*/
}