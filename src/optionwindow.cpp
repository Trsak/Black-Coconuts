#include "optionwindow.h"
#include "ui_optionwindow.h"

OptionWindow::OptionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionWindow)
{
    ui->setupUi(this);
}

OptionWindow::~OptionWindow()
{
    delete ui;
}
