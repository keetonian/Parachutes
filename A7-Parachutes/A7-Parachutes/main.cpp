#include "mainwindow.h"
#include "windowcontroller.h"
#include <QApplication>

// 3rd party libraries
#include "Box2D/helloworld.h"   // runBox2DHelloWorld

// Application internals
#include "networking.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString configFile = ":/A7-Parachutes.ini";
    Networking *client = new Networking(configFile, &app);
    // If the connection closes:
    QObject::connect(client, &Networking::socketClosed, &app, &QCoreApplication::quit);
    qDebug() << "About to request";
    client->requestWordList("yoda", 1);
    WindowController controller(client);

    // For testing Box2D purposes:
//    runBox2DHelloWorld();


    // Turns out putting this in a method was deleting the client object when the method returned,
    // therefore creating a pointer for it is better.
//    Networking* client = new Networking(configFile, &app);
//    // If the connection closes:
//    QObject::connect(client, &Networking::socketClosed, &app, &QCoreApplication::quit);
//    client->requestWordList("yoda", 1);

    return app.exec();
}
