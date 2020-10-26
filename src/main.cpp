
#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlComponent>
#include <QWindow>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlComponent component(new QQmlApplicationEngine(), "qrc:/main.qml");
    QWindow *window = (QWindow *) component.create();
    window->show();

    return app.exec();
}