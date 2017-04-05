#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->frameSecond->hide();
    ui->frameMain->show();

    connect(ui->horizontalScrollBar,SIGNAL(valueChanged(int)),this ,SLOT(func()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::func(){
    if (ui->horizontalScrollBar->value() == 0){
        ui->frameSecond->hide();
        ui->frameMain->show();
    }else{
        ui->frameSecond->show();
        ui->frameMain->hide();
    }
}
