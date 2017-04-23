/**
 * @file mainwindow.cpp
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "muParser.h"
#include "math_lib.h"
#include "binaryParser.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(510, 340); //set window size

    ui->binaryWindow->hide(); //start with normal calc
    ui->mainWindow->show();

    ui->frameSecond->hide(); // show basic option
    ui->frameMain->show();

    ui->textEdit->setText(""); //set textEdit
    QString myQString = ui->textEdit->toPlainText();

    connect(ui->button0, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button0->setShortcut(Qt::Key_0);
    connect(ui->button1, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button1->setShortcut(Qt::Key_1);
    connect(ui->button2, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button2->setShortcut(Qt::Key_2);
    connect(ui->button3, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button3->setShortcut(Qt::Key_3);
    connect(ui->button4, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button4->setShortcut(Qt::Key_4);
    connect(ui->button5, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button5->setShortcut(Qt::Key_5);
    connect(ui->button6, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button6->setShortcut(Qt::Key_6);
    connect(ui->button7, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button7->setShortcut(Qt::Key_7);
    connect(ui->button8, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button8->setShortcut(Qt::Key_8);
    connect(ui->button9, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button9->setShortcut(Qt::Key_9);
    connect(ui->buttonPI, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->buttonPI->setShortcut(Qt::Key_P);
    connect(ui->button0_b, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button0_b->setShortcut(Qt::Key_0);
    connect(ui->button1_b, SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    ui->button1_b->setShortcut(Qt::Key_1);
    connect(ui->buttonPlus, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonPlus->setShortcut(Qt::Key_Plus);
    connect(ui->buttonMinus, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonMinus->setShortcut(Qt::Key_Minus);
    connect(ui->buttonKrat, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonKrat->setShortcut(Qt::Key_Asterisk);
    connect(ui->buttonDivision, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonDivision->setShortcut(Qt::Key_Slash);
    connect(ui->buttonFactorial, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonFactorial->setShortcut(Qt::Key_Exclam);
    connect(ui->buttonSquare, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    connect(ui->buttonIndex, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonIndex->setShortcut(Qt::Key_AsciiCircum);
    connect(ui->buttonLeftBar, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonLeftBar->setShortcut(Qt::Key_ParenLeft);
    ui->buttonRightBar->setShortcut(Qt::Key_ParenRight);
    connect(ui->buttonQDot, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonQDot->setShortcut(Qt::Key_Period);
    connect(ui->buttonWReset, SIGNAL(clicked(bool)), this, SLOT(operatorClicked()));
    ui->buttonWReset->setShortcut(Qt::Key_C);
    connect(ui->buttonWReset_b, SIGNAL(clicked(bool)), this, SLOT(operatorClicked_b()));
    ui->buttonWReset_b->setShortcut(Qt::Key_C);
    connect(ui->buttonOR_b, SIGNAL(clicked(bool)), this, SLOT(operatorClicked_b()));
    connect(ui->buttonNOR_b, SIGNAL(clicked(bool)), this, SLOT(operatorClicked_b()));
    connect(ui->buttonAND_b, SIGNAL(clicked(bool)), this, SLOT(operatorClicked_b()));
    connect(ui->buttonNAND_b, SIGNAL(clicked(bool)), this, SLOT(operatorClicked_b()));
    connect(ui->buttonXOR_b, SIGNAL(clicked(bool)), this, SLOT(operatorClicked_b()));
    connect(ui->buttonXNOR_b, SIGNAL(clicked(bool)), this, SLOT(operatorClicked_b()));
    connect(ui->buttonUndo, SIGNAL(clicked(bool)), this, SLOT(undoClicked()));
    connect(ui->buttonUndo_b, SIGNAL(clicked(bool)), this, SLOT(undoClicked()));

    ui->buttonUndo->setShortcut(Qt::Key_Backspace);
    ui->buttonUndo_b->setShortcut(Qt::Key_Backspace);
    ui->buttonEnter->setShortcut(Qt::Key_Return);
    ui->buttonEnter_b->setShortcut(Qt::Key_Return);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::numberClicked() {
    restoreContent();
    QString sender = QObject::sender()->objectName();
    QChar tmp = sender[6];
    piMultiply();

    if (tmp == 'P') {
        if (getChar(-1).isDigit()) {
            myQString = (myQString + "*pi");
        } else {
            myQString = (myQString + "pi");
        }
    } else {
        myQString = (myQString + tmp);
    }

    ui->textEdit->setText(myQString);
}

void MainWindow::operatorClicked() {
    restoreContent();
    QString sender = QObject::sender()->objectName();
    sender = sender[6];

    if (!ui->binaryWindow->isHidden()) {
        myQString = (myQString + " ");
    }

    if (sender == "P") {
        myQString = (myQString + "+");
    } else if (sender == "M") {
        myQString = (myQString + "-");
    } else if (sender == "K") {
        myQString = (myQString + "*");
    } else if (sender == "D") {
        myQString = (myQString + "/");
    } else if (sender == "F") {
        myQString = (myQString + "factorial(x)");
    } else if (sender == "S") {
        myQString = (myQString + "sqrt(x,y)");
    } else if (sender == "I") {
        myQString = (myQString + "pow(x,y)");
    } else if (sender == "Q") {
        myQString = (myQString + ".");
    } else if (sender == "W") {
        myQString = ("");
    } else if (sender == "L") {
        myQString = (myQString + "(");
    }

    if (!ui->binaryWindow->isHidden()) {
        myQString = (myQString + " ");
    }

    ui->textEdit->setText(myQString);
}

QChar MainWindow::getChar(int position) {
    QChar foundChar;
    if (myQString.length() < position * -1) {
        return foundChar;
    }
    int help = myQString.length();
    return myQString.at(help + position);
}

bool MainWindow::counter() {
    int left = 0;
    int right = 0;
    for (int i = 0; i < myQString.size(); i++) {
        if (myQString[i] == '(') {
            left++;
        } else if (myQString[i] == ')') {
            right++;
        }
    }
    if (left > right) {
        return true;
    }
    return false;
}

void MainWindow::piMultiply() {
    QChar last = getChar(-1);
    if (last == 'i') {
        myQString = (myQString + "*");
    }
}

void MainWindow::undoClicked() {
    restoreContent();
    if (myQString.size() > 0) {
        myQString.resize(myQString.size() - 1);
    }

    ui->textEdit->setText(myQString);
}

void MainWindow::on_buttonRightBar_clicked() {
    restoreContent();
    myQString = (myQString + ")");
    ui->textEdit->setText(myQString);
}

void MainWindow::on_buttonSettings_clicked() {
    if (ui->mainWindow->isVisible()) {
        ui->buttonSettings->setIcon(QIcon(":/project/Images/b.png"));
        ui->mainWindow->hide();
        ui->binaryWindow->show();
        myQString = ("");
        ui->textEdit->setText(myQString);
    } else {
        ui->buttonSettings->setIcon(QIcon(":/project/Images/d.png"));
        ui->mainWindow->show();
        ui->binaryWindow->hide();
        myQString = ("");
        ui->textEdit->setText(myQString);
    }
}

void MainWindow::operatorClicked_b() {
    restoreContent();
    QString sender = QObject::sender()->objectName();
    sender = sender.mid(6);
    sender.chop(2);

    QString sender2 = QObject::sender()->objectName();
    sender2 = sender2[6];

    if (sender2 != "W") {
        myQString = (myQString + " " + sender + " ");
    } else {
        myQString = "";
    }
    ui->textEdit->setText(myQString);
}

void MainWindow::restoreContent() {
    myQString = ui->textEdit->toPlainText();
}

void MainWindow::on_buttonEnter_clicked() {
    restoreContent();
    try {
        mu::Parser p;
        p.SetExpr(ui->textEdit->toPlainText().toUtf8().constData());
        p.DefineConst("pi", 3.14159265358);
        double result = p.Eval();

        myQString = QString::number(result);
    }
    catch (mu::Parser::exception_type &e) {
        myQString = QString::fromStdString(e.GetMsg());
    }
    catch (std::overflow_error &e) {
        myQString = "ERROR: Overflow!";
    }

    ui->textEdit->setText(myQString);
}

void MainWindow::on_buttonEnter_b_clicked() {
    restoreContent();
    binaryParser p(ui->textEdit->toPlainText().toUtf8().constData());
    ui->textEdit->setText(QString::fromStdString(p.getResult()));
}
