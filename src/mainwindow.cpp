#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(500,380);
    ui->frameSecond->hide();
    ui->frameMain->show();

    QString myQString = ui->textBrowser->toPlainText();

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

void MainWindow::on_buttonZero_clicked()
{
    myQString = (myQString+"0");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonOne_clicked()
{
    myQString = (myQString+"1");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonTwo_clicked()
{
    myQString = (myQString+"2");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonThree_clicked()
{
    myQString = (myQString+"3");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonFour_clicked()
{
    myQString = (myQString+"4");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonFive_clicked()
{
    myQString = (myQString+"5");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonSix_clicked()
{
    myQString = (myQString+"6");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonSeven_clicked()
{
    myQString = (myQString+"7");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonEight_clicked()
{
    myQString = (myQString+"8");
    ui->textBrowser->setText(myQString);
}
void MainWindow::on_buttonNine_clicked()
{
    myQString = (myQString+"9");
    ui->textBrowser->setText(myQString);
}
