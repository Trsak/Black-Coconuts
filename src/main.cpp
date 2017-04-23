/**
 * @file main.cpp
 * @brief Main function for Qt
 */
#include "mainwindow.h"
#include "qfile.h"
#include "qtextstream.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE (resource);

    QApplication program(argc, argv);

    QFile styleFile(":/project/Stylesheet/darkorange.stylesheet.qss");
        if(styleFile.open(QIODevice::ReadOnly))
        {
            QTextStream textStream(&styleFile);
            QString styleSheet = textStream.readAll();
            styleFile.close();
            program.setStyleSheet(styleSheet);
        }

    MainWindow mw;
    mw.setWindowIcon(QIcon(":/project/Images/favicon.png"));
    mw.show();

    return program.exec();
}


