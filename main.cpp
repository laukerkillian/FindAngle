//
// Created by kerla on 26/02/2021.
//

#include <QApplication>
#include <QTimer>
#include "mainwindow.h"
#include <QObject>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();
}