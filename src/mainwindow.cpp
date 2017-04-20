#include "mainwindow.h"
#include "ui_mainwindow.h"
bool dot = true;
bool dot_b = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(510,340); //set window size

    ui->binaryWindow->hide(); //start with normal calc
    ui->mainWindow->show();

    ui->frameSecond->hide(); // show basic option
    ui->frameMain->show();
    ui->frameSecond_b->hide();
    ui->frameMain_b->show();

    ui->textEdit->setText(""); //set textEdit
    QString myQString = ui->textEdit->toPlainText();

    disableButton();
    disableButton_b();
    countBar();

    ui->buttonRound->setEnabled(false);
    ui->buttonANS->setEnabled(false);
    ui->buttonRound_b->setEnabled(false);
    ui->buttonANS_b->setEnabled(false);

    connect(ui->horizontalScrollBar,SIGNAL(valueChanged(int)),this ,SLOT(slide())); //connect signals
    connect(ui->horizontalScrollBar_b,SIGNAL(valueChanged(int)),this ,SLOT(slide()));
    connect(ui->button0,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button1,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button2,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button3,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button4,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button5,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button6,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button7,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button8,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button9,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->buttonPI,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button0_b,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->button1_b,SIGNAL(clicked(bool)),this ,SLOT(numberClicked()));
    connect(ui->buttonPlus,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonMinus,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonKrat,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonDivision,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonFactorial,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonSquare,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonIndex,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonLeftBar,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonQDot,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonWReset,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonKrat_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonPlus_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonMinus_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonDivision_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonLeftBar_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonWReset_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonQDot_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked()));
    connect(ui->buttonNOT_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked_b()));
    connect(ui->buttonOR_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked_b()));
    connect(ui->buttonNOR_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked_b()));
    connect(ui->buttonAND_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked_b()));
    connect(ui->buttonNAND_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked_b()));
    connect(ui->buttonXOR_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked_b()));
    connect(ui->buttonXNOR_b,SIGNAL(clicked(bool)),this ,SLOT(operatorClicked_b()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 *   @brief Automatically moves the scrollbar at the end
 *
 *   @return void
 */
void MainWindow::moveScrollBar()
{
    ui->textEdit->horizontalScrollBar()->setValue(ui->textEdit->horizontalScrollBar()->maximum());
}

/**
 *   @brief Calls on ScrollBar move
 *   @brief Swaps hidden and shown frames
 *
 *   @return void
 */
void MainWindow::slide(){
    if (QObject::sender() == ui->horizontalScrollBar){
        if (ui->horizontalScrollBar->value() == 0){
            ui->frameSecond->hide();
            ui->frameMain->show();
        }else{
            ui->frameSecond->show();
            ui->frameMain->hide();
        }
    }else{
        if (ui->horizontalScrollBar_b->value() == 0){
            ui->frameSecond_b->hide();
            ui->frameMain_b->show();
        }else{
            ui->frameSecond_b->show();
            ui->frameMain_b->hide();
        }
    }
}

/**
 *   @brief Call on number or PI button clicked
 *   @brief Saves the value of button to myQString and display
 *
 *   @return void
 */
void MainWindow::numberClicked()
{
    QString sender = QObject::sender()->objectName();
    QChar tmp = sender[6];
    afterRightBar();
    piMultiply();
    if (tmp == "P"){
        if (getChar(-1).isDigit()){
            myQString = (myQString+"*pi");
        }else{
            myQString = (myQString+"pi");
        }
    }else {
        myQString = (myQString+tmp);
    }
    ui->textEdit->setText(myQString);
    if (sender.length()>7 && tmp != "P"){
        enableButton_b();
    }else{
        enableButton();
    }
    moveScrollBar();
}

/**
 *   @brief Call on operator button clicked
 *   @brief Saves the value of button to myQString and display
 *
 *   @return void
 */
void MainWindow::operatorClicked()
{
    disableButton();
    disableButton_b();
    QString sender = QObject::sender()->objectName();
    sender = sender[6];
    if (sender == 'P'){
        myQString = (myQString+"+");
    }else if (sender == 'M'){
        QChar last = getChar(-1);
        if (last.isDigit() || last.isNull() || last == '('){
            myQString = (myQString+"-");
        }else if(last == ')'){
            myQString = (myQString+"*(-");
        }else{
            myQString = (myQString+"(-");
        }
    }else if (sender == 'K'){
        myQString = (myQString+"*");
    }else if (sender == 'D'){
        myQString = (myQString+"/");
    }else if (sender == 'F'){
        myQString = (myQString+"!");
    }else if (sender == 'S'){
        if (!getChar(-1).isDigit()){
            myQString = (myQString+"2sqrt(");
        }else{
            myQString = (myQString+"sqrt(");
        }
    }else if (sender == 'I'){
        myQString = (myQString+"exp(");
    }else if (sender == 'Q'){
        myQString = (myQString+".");
        dot = false;
        dot_b = false;
        ui->buttonMinus->setEnabled(false);
        ui->buttonLeftBar->setEnabled(false);
        ui->buttonSquare->setEnabled(false);
        ui->buttonPI->setEnabled(false);
        ui->buttonRightBar->setEnabled(false);
    }else if (sender == 'W'){
        myQString = ("");
    }else if (sender == 'L'){
        QChar last = getChar(-1);
        if (last.isDigit() || last == 'i' || last == ')'){
            myQString = (myQString+"*(");
        }else{
            myQString = (myQString+"(");
        }
    }
    countBar();
    countBar_b();
    ui->textEdit->setText(myQString);
    moveScrollBar();
}

/**
 *   @param position is an integer
 *   @return QChar that is on position of myQString
 */
QChar MainWindow::getChar(int position)
{
    QChar foundChar;
    if (myQString.length() < position*-1){
        return foundChar;
    }
    int help = myQString.length();
    return myQString.at(help+position);
}

/**
 *   @brief Adds '*' char between bars to myQString if needed
 *
 *   @return void
 */
void MainWindow::afterRightBar()
{
    if (getChar(-1) == ')'){
        myQString = (myQString+"*");
    }
    moveScrollBar();
}

/**
 *   @brief Compares how many left anf right bars are in myQString
 *
 *   @return true if there are more left bars, false if there are equal or more right bars
 */
bool MainWindow::counter(){
    int left = 0;
    int right = 0;
    for (int i = 0; i < myQString.size(); i++){
        if (myQString[i] == '('){
            left++;
        }else if (myQString[i] == ')'){
            right++;
        }
    }
    if (left > right){
        return true;
    }
    return false;
}

/**
 *   @brief Allows or denies to use right bar and enter buttons
 *
 *   @param gets true if function was called by buttonRightBar, else gets false (optional parameter)
 *   @return void
 */
void MainWindow::countBar(bool rightBar)
{
    QChar last = getChar(-1);
    if (counter()){
        if (last.isDigit() || last == ')' || last == 'i'){
            ui->buttonRightBar->setEnabled(true);
            ui->buttonEnter->setEnabled(false);
            return;
        }
    }
    ui->buttonRightBar->setEnabled(false);
    if (rightBar){
        ui->buttonEnter->setEnabled(true);
    }
}

/**
 *   @brief Allows or denies to use right bar and enter buttons
 *
 *   @param gets true if function was called by buttonRightBar_b, else gets false (optional parameter)
 *   @return void
 */
void MainWindow::countBar_b(bool rightBar)
{
    QChar last = getChar(-1);
    if (counter()){
        if (last.isDigit() || last == ')'){
            ui->buttonRightBar_b->setEnabled(true);
            ui->buttonEnter_b->setEnabled(false);
            return;
        }
    }
    ui->buttonRightBar_b->setEnabled(false);
    if (rightBar){
        ui->buttonEnter_b->setEnabled(true);
    }
}

/**
 *   @brief Disables some buttons if they can't be used
 *
 *   @return void
 */
void MainWindow::disableButton()
{
    ui->buttonEnter->setEnabled(false);
    ui->buttonKrat->setEnabled(false);
    ui->buttonDivision->setEnabled(false);
    ui->buttonQDot->setEnabled(false);
    ui->buttonPlus->setEnabled(false);
    ui->buttonIndex->setEnabled(false);
    ui->buttonFactorial->setEnabled(false);
    dot = true;
}

/**
 *   @brief Adds '*' symbol to myQString if need
 *
 *   @return void
 */
void MainWindow::piMultiply()
{
    QChar last = getChar(-1);
    if (last == 'i'){
        myQString = (myQString+"*");
    }
    moveScrollBar();
}

/**
 *   @brief Enables some buttons if they can be used again
 *
 *   @return void
 */
void MainWindow::enableButton()
{
    ui->buttonKrat->setEnabled(true);
    ui->buttonDivision->setEnabled(true);
    ui->buttonPlus->setEnabled(true);
    ui->buttonMinus->setEnabled(true);
    ui->buttonLeftBar->setEnabled(true);
    ui->buttonEnter->setEnabled(true);
    ui->buttonSquare->setEnabled(true);
    ui->buttonIndex->setEnabled(true);
    ui->buttonFactorial->setEnabled(true);
    ui->buttonPI->setEnabled(true);
    if (dot){
        ui->buttonQDot->setEnabled(true);
    }
    dot = false;
    countBar();
}


/**
 *   @brief Cuts the last char in myQString (few last chars if pi, exp or sqrt was last)
 *   @brief Disable or enable buttons if need
 *
 *   @return void
 */
void MainWindow::on_buttonUndo_clicked()
{
    QChar preLast = getChar(-2);
    QChar last = getChar(-1);
    if (myQString.size() > 1){
        if (last == 'i'){
            myQString.resize (myQString.size() - 2);
        }else if (preLast == 'p'){
            myQString.resize (myQString.size() - 4);
        }else if (preLast == 't'){
            myQString.resize (myQString.size() - 5);
        }else{
            myQString.resize (myQString.size() - 1);
        }
        if (preLast.isDigit() || preLast == 'i'){
            enableButton();
        }else{
            disableButton();
            dot = false;
        }
    }
    else if (myQString.size() == 1){
        myQString.resize (myQString.size() - 1);
        enableButton();
        disableButton();
        dot = false;
    }else{
        disableButton();
        dot = false;
    }
    if (last == '.'){
        ui->buttonQDot->setEnabled(true);
    }
    countBar();
    ui->textEdit->setText(myQString);
    moveScrollBar();
}

/**
 *   @brief Adds ')' symbol to myQString and display
 *
 *   @return void
 */
void MainWindow::on_buttonRightBar_clicked()
{
    dot = true;
    ui->buttonQDot->setEnabled(false);
    myQString = (myQString+")");
    ui->textEdit->setText(myQString);
    countBar(true);
    moveScrollBar();
}

/**
 *   @brief Changes between normal and binary mode
 *
 *   @return void
 */
void MainWindow::on_buttonSettings_clicked()
{
    if (ui->mainWindow->isVisible()){
        ui->buttonSettings->setIcon(QIcon(":/project/Images/b.png"));
        ui->mainWindow->hide();
        ui->binaryWindow->show();
        disableButton_b();
        myQString = ("");
        countBar_b();
        ui->textEdit->setText(myQString);
        dot_b=true;
    }else{
        ui->buttonSettings->setIcon(QIcon(":/project/Images/d.png"));
        ui->mainWindow->show();
        ui->binaryWindow->hide();
        disableButton();
        myQString = ("");
        countBar();
        ui->textEdit->setText(myQString);
        dot=true;
    }
}

/**
 *   @brief Disables some buttons if they can't be used
 *
 *   @return void
 */
void MainWindow::disableButton_b()
{
    ui->buttonEnter_b->setEnabled(false);
    ui->buttonKrat_b->setEnabled(false);
    ui->buttonDivision_b->setEnabled(false);
    ui->buttonQDot_b->setEnabled(false);
    ui->buttonPlus_b->setEnabled(false);
    ui->buttonNOT_b->setEnabled(false);
    ui->buttonOR_b->setEnabled(false);
    ui->buttonNOR_b->setEnabled(false);
    ui->buttonAND_b->setEnabled(false);
    ui->buttonNAND_b->setEnabled(false);
    ui->buttonXOR_b->setEnabled(false);
    ui->buttonXNOR_b->setEnabled(false);
    dot_b = true;
}

/**
 *   @brief Enables some buttons if they can be used again
 *
 *   @return void
 */
void MainWindow::enableButton_b()
{
    ui->buttonEnter_b->setEnabled(true);
    ui->buttonKrat_b->setEnabled(true);
    ui->buttonDivision_b->setEnabled(true);
    ui->buttonPlus_b->setEnabled(true);
    ui->buttonMinus_b->setEnabled(true);
    ui->buttonLeftBar_b->setEnabled(true);
    ui->buttonNOT_b->setEnabled(true);
    ui->buttonOR_b->setEnabled(true);
    ui->buttonNOR_b->setEnabled(true);
    ui->buttonAND_b->setEnabled(true);
    ui->buttonNAND_b->setEnabled(true);
    ui->buttonXOR_b->setEnabled(true);
    ui->buttonXNOR_b->setEnabled(true);
    if (dot_b){
        ui->buttonQDot_b->setEnabled(true);
    }
    dot_b = false;
    countBar_b();
}

/**
 *   @brief Cuts the last char in myQString (few last chars if OR, XOR, XNOR, etc.. was last)
 *   @brief Disable or enable buttons if need
 *
 *   @return void
 */
void MainWindow::on_buttonUndo_b_clicked()
{
    QChar preLast_3 = getChar(-4);
    QChar preLast_b = getChar(-3);
    QChar last = getChar(-1);
    if (myQString.size() > 1){
        if (last == 'T'){
            myQString.resize (myQString.size() - 4);
        }else if (last == 'D'){
            if (preLast_3 == 'N'){
                myQString.resize (myQString.size() - 5);
            }else{
                myQString.resize (myQString.size() - 4);
            }
        }else if (last == ' '){
            myQString.resize (myQString.size() - 1);
            on_buttonUndo_b_clicked();
        }else if (last == 'R'){
            if (preLast_b == 'X'){
                myQString.resize (myQString.size() - 4);
            }else if (preLast_b == 'N'){
                if (preLast_3 == 'X'){
                    myQString.resize (myQString.size() - 5);
                }else{
                    myQString.resize (myQString.size() - 4);
                }
            }else{
                myQString.resize (myQString.size() - 3);
            }
        }else{
            myQString.resize (myQString.size() - 1);
        }
        QChar last = getChar(-1);
        if (last.isDigit()){
            enableButton_b();
        }else{
            disableButton_b();
            dot_b = false;
        }
    }else if (myQString.size() == 1){
        myQString.resize (myQString.size() - 1);
        enableButton_b();
        disableButton_b();
        dot_b = false;
        ui->buttonEnter_b->setEnabled(false);
    }else{
        disableButton_b();
        dot_b = false;
    }
    if (last == '.'){
        ui->buttonQDot_b->setEnabled(true);
    }
    countBar_b();
    ui->textEdit->setText(myQString);
    moveScrollBar();
}

/**
 *   @brief Call on operator button clicked
 *   @brief Saves the value of button to myQString and display
 *
 *   @return void
 */
void MainWindow::operatorClicked_b()
{
    QString sender = QObject::sender()->objectName();
    sender = sender.mid(6);
    sender.chop(2);
    myQString = (myQString+" "+sender+" ");
    disableButton_b();
    ui->textEdit->setText(myQString);
    moveScrollBar();
}

/**
 *   @brief Adds ')' symbol to myQString and display
 *
 *   @return void
 */
void MainWindow::on_buttonRightBar_b_clicked()
{
    ui->buttonQDot_b->setEnabled(false);
    dot_b = true;
    myQString = (myQString+")");
    ui->textEdit->setText(myQString);
    countBar_b(true);
    moveScrollBar();
}

//Po zmáčknutí = v binárním módu
void MainWindow::on_buttonEnter_b_clicked()
{
    ui->buttonRound_b->setEnabled(true);
    ui->buttonANS_b->setEnabled(true);

    myQString = "VYSLEDEK";
    ui->textEdit->setText(myQString);
}

//Po zmáčknutí = v normální módu
void MainWindow::on_buttonEnter_clicked()
{
    ui->buttonRound->setEnabled(true);
    ui->buttonANS->setEnabled(true);

    myQString = "VYSLEDEK";
    ui->textEdit->setText(myQString);
}
