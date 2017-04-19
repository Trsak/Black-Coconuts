#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE (resource);

    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();

    return a.exec();
}


