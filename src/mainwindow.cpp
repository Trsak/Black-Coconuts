#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "optionwindow.h"
bool dot = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(500,380);
    ui->frameSecond->hide();
    ui->frameMain->show();
    disableButton();
    ui->buttonRound->setEnabled(false);
    ui->buttonANS->setEnabled(false);
    ui->buttonEnter->setEnabled(false);

    QString myQString = ui->textBrowser->toPlainText();

    countBar();

    connect(ui->horizontalScrollBar,SIGNAL(valueChanged(int)),this ,SLOT(slide()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QChar MainWindow::getChar(int position)
{
    QChar foundChar;

    if (myQString.length() < position*-1)
    {
        return foundChar;
    }

    int help = myQString.length();
    help = help+position;
    foundChar = myQString.at(help);
    return foundChar;
}

void MainWindow::afterRightBar()
{
    QChar last = getChar(-1);
    if (last == ')'){
        myQString = (myQString+"*");
    }
}

void MainWindow::countBar(bool rightBar)
{
    int left = 0;
    int right = 0;

    for (int i = 0; i < myQString.size(); i++){
        if (myQString[i] == '(') left++;
        else if (myQString[i] == ')') right++;
    }


    QChar last = getChar(-1);
    if (left > right){
        if (last.isDigit() || last == ')' || last == 'i'){
            ui->buttonRightBar->setEnabled(true);
            ui->buttonEnter->setEnabled(false);
            return;
        }
    }
    ui->buttonRightBar->setEnabled(false);
    if (rightBar)
        ui->buttonEnter->setEnabled(true);
}

void MainWindow::disableButton()
{
    ui->buttonMultiply->setEnabled(false);
    ui->buttonDivision->setEnabled(false);
    ui->buttonPercentage->setEnabled(false);
    ui->buttonDot->setEnabled(false);
    ui->buttonPlus->setEnabled(false);
    ui->buttonIndex->setEnabled(false);
    ui->buttonFactorial->setEnabled(false);
    dot = true;
}

void MainWindow::piMultiply()
{
    QChar last = getChar(-1);
    if (last == 'i'){
        myQString = (myQString+"*");
    }
}

void MainWindow::enableButton()
{
    ui->buttonEnter->setEnabled(true);
    ui->buttonMultiply->setEnabled(true);
    ui->buttonDivision->setEnabled(true);
    ui->buttonPercentage->setEnabled(true);
    ui->buttonPlus->setEnabled(true);
    ui->buttonMinus->setEnabled(true);
    ui->buttonLeftBar->setEnabled(true);
    ui->buttonEnter->setEnabled(true);
    ui->buttonSquare->setEnabled(true);
    ui->buttonIndex->setEnabled(true);
    ui->buttonFactorial->setEnabled(true);
    if (dot){
        ui->buttonDot->setEnabled(true);
    }
    dot = false;
    countBar();
}
void MainWindow::slide(){
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
    afterRightBar();
    piMultiply();
    myQString = (myQString+"0");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonOne_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"1");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonTwo_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"2");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonThree_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"3");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonFour_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"4");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonFive_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"5");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonSix_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"6");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonSeven_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"7");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonEight_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"8");
    ui->textBrowser->setText(myQString);
    enableButton();
}
void MainWindow::on_buttonNine_clicked()
{
    afterRightBar();
    piMultiply();
    myQString = (myQString+"9");
    ui->textBrowser->setText(myQString);
    enableButton();
}

void MainWindow::on_buttonDot_clicked()
{
    myQString = (myQString+".");
    ui->textBrowser->setText(myQString);
    disableButton();
    dot = false;
    ui->buttonMinus->setEnabled(false);
    ui->buttonLeftBar->setEnabled(false);
    ui->buttonEnter->setEnabled(false);
    ui->buttonSquare->setEnabled(false);
    ui->buttonIndex->setEnabled(false);
    ui->buttonFactorial->setEnabled(false);
    ui->buttonPI->setEnabled(false);
    ui->buttonRightBar->setEnabled(false);
}

void MainWindow::on_buttonPercentage_clicked()
{
    myQString = (myQString+"%");
    ui->textBrowser->setText(myQString);
}

void MainWindow::on_buttonReset_clicked()
{
    myQString = ("");
    ui->textBrowser->setText(myQString);
    ui->buttonEnter->setEnabled(false);
    disableButton();
    countBar();
}

void MainWindow::on_buttonUndo_clicked()
{
    QChar preLast = getChar(-2);
    QChar last = getChar(-1);
    if (myQString.size() > 1){
        if (last == 'i'){
            myQString.resize (myQString.size() - 2);
        }

        else if (preLast == 'p'){
            myQString.resize (myQString.size() - 4);
        }
        else if (preLast == 't'){
            myQString.resize (myQString.size() - 5);
        }
        else{
            myQString.resize (myQString.size() - 1);
        }
        if (preLast.isDigit() || preLast == 'i'){
            enableButton();
        }
        else{
            disableButton();
            dot = false;
        }
    }
    else if (myQString.size() == 1){
        myQString.resize (myQString.size() - 1);
        enableButton();
        disableButton();
        dot = false;
        ui->buttonEnter->setEnabled(false);
    }
    else{
        disableButton();
        dot = false;
    }

    if (last == '.'){
        ui->buttonDot->setEnabled(true);
    }
    countBar();
    ui->textBrowser->setText(myQString);
}

void MainWindow::on_buttonLeftBar_clicked()
{
    QChar last = getChar(-1);
    if (last.isDigit() || last == 'i' || last == ')'){
        myQString = (myQString+"*(");
    }
    else{
        myQString = (myQString+"(");
    }
    ui->textBrowser->setText(myQString);
    ui->buttonEnter->setEnabled(false);
    countBar();
    disableButton();
}

void MainWindow::on_buttonRightBar_clicked()
{
    myQString = (myQString+")");
    ui->textBrowser->setText(myQString);
    countBar(true);
}

void MainWindow::on_buttonIndex_clicked()
{
    myQString = (myQString+"exp(");
    ui->textBrowser->setText(myQString);
    disableButton();
    countBar();
}

void MainWindow::on_buttonSquare_clicked()
{
    QChar last = getChar(-1);
    if (!last.isDigit()){
        myQString = (myQString+"2sqrt(");
    }
    else{
        myQString = (myQString+"sqrt(");
    }
    ui->textBrowser->setText(myQString);
    disableButton();
    countBar();
}

void MainWindow::on_buttonPI_clicked()
{
    afterRightBar();
    piMultiply();
    QChar last = getChar(-1);
    if (last.isDigit()){
        myQString = (myQString+"*pi");
    }
    else{
        myQString = (myQString+"pi");
    }
    ui->textBrowser->setText(myQString);
    enableButton();
}

void MainWindow::on_buttonFactorial_clicked()
{
    myQString = (myQString+"!");
    ui->textBrowser->setText(myQString);
    disableButton();
}

void MainWindow::on_buttonDivision_clicked()
{
    myQString = (myQString+"/");
    ui->textBrowser->setText(myQString);
    disableButton();
}

void MainWindow::on_buttonMinus_clicked()
{
    QChar last = getChar(-1);
    if (last.isDigit() || last.isNull() || last == '('){
        myQString = (myQString+"-");
    }
    else{
        myQString = (myQString+"(-");
    }
    ui->textBrowser->setText(myQString);
    countBar();
    disableButton();
}

void MainWindow::on_buttonMultiply_clicked()
{
    myQString = (myQString+"*");
    ui->textBrowser->setText(myQString);
    disableButton();
}

void MainWindow::on_buttonPlus_clicked()
{
    myQString = (myQString+"+");
    ui->textBrowser->setText(myQString);
    disableButton();
}

void MainWindow::on_buttonSettings_clicked()
{
    OptionWindow optionwindow;
    optionwindow.setModal(true);
    optionwindow.exec();
}
