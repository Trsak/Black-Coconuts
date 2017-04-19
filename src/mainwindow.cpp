#include "mainwindow.h"
#include "ui_mainwindow.h"
bool dot = true;
bool dot_2 = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,380);
    ui->binaryWindow->hide();
    ui->mainWindow->show();
    ui->frameSecond->hide();
    ui->frameMain->show();
    ui->frameSecond_2->hide();
    ui->frameMain_2->show();
    disableButton();
    disableButton_2();
    ui->buttonRound->setEnabled(false);
    ui->buttonANS->setEnabled(false);
    ui->buttonRound_2->setEnabled(false);
    ui->buttonANS_2->setEnabled(false);

    QString myQString = ui->textBrowser->toPlainText();

    countBar();

    connect(ui->horizontalScrollBar,SIGNAL(valueChanged(int)),this ,SLOT(slide()));
    connect(ui->horizontalScrollBar_2,SIGNAL(valueChanged(int)),this ,SLOT(slide_2()));
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

bool MainWindow::counter(){
    int left = 0;
    int right = 0;

    for (int i = 0; i < myQString.size(); i++){
        if (myQString[i] == '(') left++;
        else if (myQString[i] == ')') right++;
    }

    if (left > right){
        return true;
    }
    return false;
}

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
    if (rightBar)
        ui->buttonEnter->setEnabled(true);
}

void MainWindow::countBar_2(bool rightBar)
{
    QChar last = getChar(-1);
    if (counter()){
        if (last.isDigit() || last == ')'){
            ui->buttonRightBar_2->setEnabled(true);
            ui->buttonEnter_2->setEnabled(false);
            return;
        }
    }
    ui->buttonRightBar_2->setEnabled(false);
    if (rightBar)
        ui->buttonEnter_2->setEnabled(true);
}

void MainWindow::disableButton()
{
    ui->buttonEnter->setEnabled(false);
    ui->buttonMultiply->setEnabled(false);
    ui->buttonDivision->setEnabled(false);
    ui->buttonPercentage->setEnabled(false);
    ui->buttonDot->setEnabled(false);
    ui->buttonPlus->setEnabled(false);
    ui->buttonIndex->setEnabled(false);
    ui->buttonFactorial->setEnabled(false);
    dot = true;
}

void MainWindow::disableButton_2()
{
    ui->buttonEnter_2->setEnabled(false);
    ui->buttonMultiply_2->setEnabled(false);
    ui->buttonDivision_2->setEnabled(false);
    ui->buttonDot_2->setEnabled(false);
    ui->buttonPlus_2->setEnabled(false);
    ui->buttonNOT_2->setEnabled(false);
    ui->buttonOR_2->setEnabled(false);
    ui->buttonNOR_2->setEnabled(false);
    ui->buttonAND_2->setEnabled(false);
    ui->buttonNAND_2->setEnabled(false);
    ui->buttonXOR_2->setEnabled(false);
    ui->buttonXNOR_2->setEnabled(false);
    dot_2 = true;
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

void MainWindow::enableButton_2()
{
    ui->buttonEnter_2->setEnabled(true);
    ui->buttonMultiply_2->setEnabled(true);
    ui->buttonDivision_2->setEnabled(true);
    ui->buttonPlus_2->setEnabled(true);
    ui->buttonMinus_2->setEnabled(true);
    ui->buttonLeftBar_2->setEnabled(true);
    ui->buttonNOT_2->setEnabled(true);
    ui->buttonOR_2->setEnabled(true);
    ui->buttonNOR_2->setEnabled(true);
    ui->buttonAND_2->setEnabled(true);
    ui->buttonNAND_2->setEnabled(true);
    ui->buttonXOR_2->setEnabled(true);
    ui->buttonXNOR_2->setEnabled(true);
    if (dot_2){
        ui->buttonDot->setEnabled(true);
    }
    dot_2 = false;
    countBar_2();
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

void MainWindow::slide_2(){
    if (ui->horizontalScrollBar_2->value() == 0){
        ui->frameSecond_2->hide();
        ui->frameMain_2->show();
    }else{
        ui->frameSecond_2->show();
        ui->frameMain_2->hide();
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
        myQString = (myQString+"*"+0x03A0);
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
    myQString = ("");
    ui->textBrowser->setText(myQString);
    if (ui->mainWindow->isVisible()){
        ui->buttonSettings->setIcon(QIcon(":/project/Images/b.png"));
        ui->buttonEnter_2->setEnabled(false);
        disableButton_2();
        dot_2=true;
        ui->mainWindow->hide();
        ui->binaryWindow->show();
    }else{
        ui->buttonSettings->setIcon(QIcon(":/project/Images/d.png"));
        ui->buttonEnter->setEnabled(false);
        disableButton();
        dot=true;
        ui->mainWindow->show();
        ui->binaryWindow->hide();
    }
}

void MainWindow::on_buttonReset_2_clicked()
{
    myQString = ("");
    ui->textBrowser->setText(myQString);
    ui->buttonEnter_2->setEnabled(false);
    disableButton_2();
    countBar_2();
}

void MainWindow::on_buttonUndo_2_clicked()
{
    QChar preLast_3 = getChar(-4);
    QChar preLast_2 = getChar(-3);
    QChar preLast = getChar(-2);
    QChar last = getChar(-1);
    if (myQString.size() > 1){
        if (last == 'T'){
            myQString.resize (myQString.size() - 3);
        }

        else if (last == 'D'){
            if (preLast_3 == 'N'){
                myQString.resize (myQString.size() - 4);
            }else{
                myQString.resize (myQString.size() - 3);
            }
        }

        else if (last == 'R'){
            if (preLast_2 == 'X'){
                myQString.resize (myQString.size() - 3);
            }else if (preLast_2 == 'N'){
                if (preLast_3 == 'X'){
                    myQString.resize (myQString.size() - 4);
                }else{
                    myQString.resize (myQString.size() - 3);
                }
            }else{
                myQString.resize (myQString.size() - 2);
            }
        }
        else{
            myQString.resize (myQString.size() - 1);
        }
        if (preLast.isDigit()){
            enableButton_2();
        }
        else{
            disableButton_2();
            dot_2 = false;
        }
    }
    else if (myQString.size() == 1){
        myQString.resize (myQString.size() - 1);
        enableButton_2();
        disableButton_2();
        dot_2 = false;
        ui->buttonEnter_2->setEnabled(false);
    }
    else{
        disableButton_2();
        dot_2 = false;
    }

    if (last == '.'){
        ui->buttonDot_2->setEnabled(true);
    }
    countBar_2();
    ui->textBrowser->setText(myQString);
}

void MainWindow::on_buttonZero_2_clicked()
{
    afterRightBar();
    myQString = (myQString+"0");
    ui->textBrowser->setText(myQString);
    enableButton_2();
}

void MainWindow::on_buttonOne_2_clicked()
{
    afterRightBar();
    myQString = (myQString+"1");
    ui->textBrowser->setText(myQString);
    enableButton_2();
}

void MainWindow::on_buttonDot_2_clicked()
{
    myQString = (myQString+".");
    ui->textBrowser->setText(myQString);
    disableButton_2();
    dot_2 = false;
    ui->buttonPlus_2->setEnabled(false);
    ui->buttonMinus_2->setEnabled(false);
    ui->buttonLeftBar_2->setEnabled(false);
    ui->buttonMinus_2->setEnabled(false);
    ui->buttonLeftBar_2->setEnabled(false);
    ui->buttonEnter_2->setEnabled(false);
}

void MainWindow::on_buttonDivision_2_clicked()
{
    myQString = (myQString+"/");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonMinus_2_clicked()
{
    QChar last = getChar(-1);
    if (last.isDigit() || last.isNull() || last == '('){
        myQString = (myQString+"-");
    }
    else{
        myQString = (myQString+"(-");
    }
    ui->textBrowser->setText(myQString);
    countBar_2();
    disableButton_2();
}

void MainWindow::on_buttonMultiply_2_clicked()
{
    myQString = (myQString+"*");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonNOT_2_clicked()
{
    myQString = (myQString+" NOT ");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonPlus_2_clicked()
{
    myQString = (myQString+"+");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonAND_2_clicked()
{
    myQString = (myQString+" AND ");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonNAND_2_clicked()
{
    myQString = (myQString+" NAND ");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonNOR_2_clicked()
{
    myQString = (myQString+" NOR ");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonOR_2_clicked()
{
    myQString = (myQString+" OR ");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonXNOR_2_clicked()
{
    myQString = (myQString+" XNOR ");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonXOR_2_clicked()
{
    myQString = (myQString+" XOR ");
    ui->textBrowser->setText(myQString);
    disableButton_2();
}

void MainWindow::on_buttonLeftBar_2_clicked()
{
    QChar last = getChar(-1);
    if (last.isDigit() || last == ')'){
        myQString = (myQString+"*(");
    }
    else{
        myQString = (myQString+"(");
    }
    ui->textBrowser->setText(myQString);
    ui->buttonEnter_2->setEnabled(false);
    countBar_2();
    disableButton_2();
}

void MainWindow::on_buttonRightBar_2_clicked()
{
    myQString = (myQString+")");
    ui->textBrowser->setText(myQString);
    countBar_2(true);
}
