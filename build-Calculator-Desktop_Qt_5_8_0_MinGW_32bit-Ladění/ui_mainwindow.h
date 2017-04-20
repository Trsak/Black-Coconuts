/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *buttonSettings;
    QTextEdit *textEdit;
    QFrame *mainWindow;
    QPushButton *buttonEnter;
    QPushButton *button1;
    QPushButton *button3;
    QScrollBar *horizontalScrollBar;
    QPushButton *button5;
    QFrame *line;
    QPushButton *buttonLeftBar;
    QPushButton *buttonQDot;
    QPushButton *button2;
    QPushButton *buttonUndo;
    QPushButton *buttonANS;
    QPushButton *button4;
    QPushButton *buttonWReset;
    QFrame *frameMain;
    QPushButton *buttonDivision;
    QPushButton *buttonKrat;
    QPushButton *buttonMinus;
    QPushButton *buttonPlus;
    QPushButton *button0;
    QPushButton *button8;
    QFrame *frameSecond;
    QPushButton *buttonIndex;
    QPushButton *buttonPI;
    QPushButton *buttonRound;
    QPushButton *buttonFactorial;
    QPushButton *buttonSquare;
    QPushButton *button7;
    QPushButton *button9;
    QPushButton *buttonRightBar;
    QPushButton *button6;
    QFrame *binaryWindow;
    QPushButton *buttonEnter_b;
    QPushButton *button1_b;
    QScrollBar *horizontalScrollBar_b;
    QFrame *line_b;
    QPushButton *buttonLeftBar_b;
    QPushButton *buttonQDot_b;
    QPushButton *buttonUndo_b;
    QPushButton *buttonANS_b;
    QPushButton *buttonWReset_b;
    QPushButton *button0_b;
    QPushButton *buttonRightBar_b;
    QFrame *frameMain_b;
    QPushButton *buttonDivision_b;
    QPushButton *buttonKrat_b;
    QPushButton *buttonNOT_b;
    QPushButton *buttonMinus_b;
    QPushButton *buttonPlus_b;
    QPushButton *buttonRound_b;
    QFrame *frameSecond_b;
    QPushButton *buttonOR_b;
    QPushButton *buttonAND_b;
    QPushButton *buttonNAND_b;
    QPushButton *buttonNOR_b;
    QPushButton *buttonXNOR_b;
    QPushButton *buttonXOR_b;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 700);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        buttonSettings = new QPushButton(centralWidget);
        buttonSettings->setObjectName(QStringLiteral("buttonSettings"));
        buttonSettings->setGeometry(QRect(460, 20, 20, 20));
        buttonSettings->setStyleSheet(QStringLiteral("text-align: center;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/project/Images/d.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonSettings->setIcon(icon);
        buttonSettings->setIconSize(QSize(14, 14));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 50, 471, 61));
        textEdit->setFocusPolicy(Qt::StrongFocus);
        textEdit->setLayoutDirection(Qt::LeftToRight);
        textEdit->setAutoFillBackground(false);
        textEdit->setInputMethodHints(Qt::ImhMultiLine);
        textEdit->setFrameShape(QFrame::StyledPanel);
        textEdit->setFrameShadow(QFrame::Sunken);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        textEdit->setReadOnly(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        mainWindow = new QFrame(centralWidget);
        mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->setGeometry(QRect(20, 120, 471, 161));
        mainWindow->setFrameShape(QFrame::StyledPanel);
        mainWindow->setFrameShadow(QFrame::Raised);
        buttonEnter = new QPushButton(mainWindow);
        buttonEnter->setObjectName(QStringLiteral("buttonEnter"));
        buttonEnter->setGeometry(QRect(180, 130, 90, 30));
        button1 = new QPushButton(mainWindow);
        button1->setObjectName(QStringLiteral("button1"));
        button1->setGeometry(QRect(0, 100, 90, 30));
        button3 = new QPushButton(mainWindow);
        button3->setObjectName(QStringLiteral("button3"));
        button3->setGeometry(QRect(180, 100, 90, 30));
        horizontalScrollBar = new QScrollBar(mainWindow);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(300, 138, 160, 15));
        horizontalScrollBar->setMaximum(1);
        horizontalScrollBar->setPageStep(1);
        horizontalScrollBar->setValue(0);
        horizontalScrollBar->setSliderPosition(0);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        horizontalScrollBar->setInvertedAppearance(false);
        button5 = new QPushButton(mainWindow);
        button5->setObjectName(QStringLiteral("button5"));
        button5->setGeometry(QRect(90, 70, 90, 30));
        line = new QFrame(mainWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(280, 0, 3, 160));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        buttonLeftBar = new QPushButton(mainWindow);
        buttonLeftBar->setObjectName(QStringLiteral("buttonLeftBar"));
        buttonLeftBar->setGeometry(QRect(290, 0, 90, 30));
        buttonQDot = new QPushButton(mainWindow);
        buttonQDot->setObjectName(QStringLiteral("buttonQDot"));
        buttonQDot->setGeometry(QRect(90, 130, 90, 30));
        button2 = new QPushButton(mainWindow);
        button2->setObjectName(QStringLiteral("button2"));
        button2->setGeometry(QRect(90, 100, 90, 30));
        buttonUndo = new QPushButton(mainWindow);
        buttonUndo->setObjectName(QStringLiteral("buttonUndo"));
        buttonUndo->setGeometry(QRect(180, 0, 90, 30));
        buttonANS = new QPushButton(mainWindow);
        buttonANS->setObjectName(QStringLiteral("buttonANS"));
        buttonANS->setGeometry(QRect(0, 0, 90, 30));
        button4 = new QPushButton(mainWindow);
        button4->setObjectName(QStringLiteral("button4"));
        button4->setGeometry(QRect(0, 70, 90, 30));
        buttonWReset = new QPushButton(mainWindow);
        buttonWReset->setObjectName(QStringLiteral("buttonWReset"));
        buttonWReset->setGeometry(QRect(90, 0, 90, 30));
        frameMain = new QFrame(mainWindow);
        frameMain->setObjectName(QStringLiteral("frameMain"));
        frameMain->setGeometry(QRect(290, 40, 180, 90));
        frameMain->setFrameShape(QFrame::StyledPanel);
        frameMain->setFrameShadow(QFrame::Raised);
        buttonDivision = new QPushButton(frameMain);
        buttonDivision->setObjectName(QStringLiteral("buttonDivision"));
        buttonDivision->setGeometry(QRect(90, 60, 90, 30));
        buttonKrat = new QPushButton(frameMain);
        buttonKrat->setObjectName(QStringLiteral("buttonKrat"));
        buttonKrat->setGeometry(QRect(90, 30, 90, 30));
        buttonMinus = new QPushButton(frameMain);
        buttonMinus->setObjectName(QStringLiteral("buttonMinus"));
        buttonMinus->setGeometry(QRect(0, 60, 90, 30));
        buttonPlus = new QPushButton(frameMain);
        buttonPlus->setObjectName(QStringLiteral("buttonPlus"));
        buttonPlus->setGeometry(QRect(0, 30, 90, 30));
        button0 = new QPushButton(mainWindow);
        button0->setObjectName(QStringLiteral("button0"));
        button0->setGeometry(QRect(0, 130, 90, 30));
        button8 = new QPushButton(mainWindow);
        button8->setObjectName(QStringLiteral("button8"));
        button8->setGeometry(QRect(90, 40, 90, 30));
        frameSecond = new QFrame(mainWindow);
        frameSecond->setObjectName(QStringLiteral("frameSecond"));
        frameSecond->setGeometry(QRect(290, 40, 191, 90));
        frameSecond->setFrameShape(QFrame::StyledPanel);
        frameSecond->setFrameShadow(QFrame::Raised);
        buttonIndex = new QPushButton(frameSecond);
        buttonIndex->setObjectName(QStringLiteral("buttonIndex"));
        buttonIndex->setGeometry(QRect(0, 0, 90, 30));
        buttonPI = new QPushButton(frameSecond);
        buttonPI->setObjectName(QStringLiteral("buttonPI"));
        buttonPI->setGeometry(QRect(0, 30, 90, 30));
        buttonRound = new QPushButton(frameSecond);
        buttonRound->setObjectName(QStringLiteral("buttonRound"));
        buttonRound->setGeometry(QRect(0, 60, 90, 30));
        buttonFactorial = new QPushButton(frameSecond);
        buttonFactorial->setObjectName(QStringLiteral("buttonFactorial"));
        buttonFactorial->setGeometry(QRect(90, 30, 90, 30));
        buttonSquare = new QPushButton(frameSecond);
        buttonSquare->setObjectName(QStringLiteral("buttonSquare"));
        buttonSquare->setGeometry(QRect(90, 0, 90, 30));
        button7 = new QPushButton(mainWindow);
        button7->setObjectName(QStringLiteral("button7"));
        button7->setGeometry(QRect(0, 40, 90, 30));
        button9 = new QPushButton(mainWindow);
        button9->setObjectName(QStringLiteral("button9"));
        button9->setGeometry(QRect(180, 40, 90, 30));
        buttonRightBar = new QPushButton(mainWindow);
        buttonRightBar->setObjectName(QStringLiteral("buttonRightBar"));
        buttonRightBar->setGeometry(QRect(380, 0, 90, 30));
        button6 = new QPushButton(mainWindow);
        button6->setObjectName(QStringLiteral("button6"));
        button6->setGeometry(QRect(180, 70, 90, 30));
        binaryWindow = new QFrame(centralWidget);
        binaryWindow->setObjectName(QStringLiteral("binaryWindow"));
        binaryWindow->setGeometry(QRect(70, 120, 381, 161));
        binaryWindow->setFrameShape(QFrame::StyledPanel);
        binaryWindow->setFrameShadow(QFrame::Raised);
        buttonEnter_b = new QPushButton(binaryWindow);
        buttonEnter_b->setObjectName(QStringLiteral("buttonEnter_b"));
        buttonEnter_b->setGeometry(QRect(90, 115, 90, 30));
        button1_b = new QPushButton(binaryWindow);
        button1_b->setObjectName(QStringLiteral("button1_b"));
        button1_b->setGeometry(QRect(90, 85, 90, 30));
        horizontalScrollBar_b = new QScrollBar(binaryWindow);
        horizontalScrollBar_b->setObjectName(QStringLiteral("horizontalScrollBar_b"));
        horizontalScrollBar_b->setGeometry(QRect(210, 138, 160, 15));
        horizontalScrollBar_b->setMaximum(1);
        horizontalScrollBar_b->setPageStep(1);
        horizontalScrollBar_b->setValue(0);
        horizontalScrollBar_b->setSliderPosition(0);
        horizontalScrollBar_b->setOrientation(Qt::Horizontal);
        horizontalScrollBar_b->setInvertedAppearance(false);
        line_b = new QFrame(binaryWindow);
        line_b->setObjectName(QStringLiteral("line_b"));
        line_b->setGeometry(QRect(190, 0, 3, 160));
        line_b->setFrameShape(QFrame::VLine);
        line_b->setFrameShadow(QFrame::Sunken);
        buttonLeftBar_b = new QPushButton(binaryWindow);
        buttonLeftBar_b->setObjectName(QStringLiteral("buttonLeftBar_b"));
        buttonLeftBar_b->setGeometry(QRect(200, 0, 90, 30));
        buttonQDot_b = new QPushButton(binaryWindow);
        buttonQDot_b->setObjectName(QStringLiteral("buttonQDot_b"));
        buttonQDot_b->setGeometry(QRect(0, 115, 90, 30));
        buttonUndo_b = new QPushButton(binaryWindow);
        buttonUndo_b->setObjectName(QStringLiteral("buttonUndo_b"));
        buttonUndo_b->setGeometry(QRect(90, 0, 90, 30));
        buttonANS_b = new QPushButton(binaryWindow);
        buttonANS_b->setObjectName(QStringLiteral("buttonANS_b"));
        buttonANS_b->setGeometry(QRect(45, 30, 90, 30));
        buttonWReset_b = new QPushButton(binaryWindow);
        buttonWReset_b->setObjectName(QStringLiteral("buttonWReset_b"));
        buttonWReset_b->setGeometry(QRect(0, 0, 90, 30));
        button0_b = new QPushButton(binaryWindow);
        button0_b->setObjectName(QStringLiteral("button0_b"));
        button0_b->setGeometry(QRect(0, 85, 90, 30));
        buttonRightBar_b = new QPushButton(binaryWindow);
        buttonRightBar_b->setObjectName(QStringLiteral("buttonRightBar_b"));
        buttonRightBar_b->setGeometry(QRect(290, 0, 90, 30));
        frameMain_b = new QFrame(binaryWindow);
        frameMain_b->setObjectName(QStringLiteral("frameMain_b"));
        frameMain_b->setGeometry(QRect(200, 40, 180, 90));
        frameMain_b->setFrameShape(QFrame::StyledPanel);
        frameMain_b->setFrameShadow(QFrame::Raised);
        buttonDivision_b = new QPushButton(frameMain_b);
        buttonDivision_b->setObjectName(QStringLiteral("buttonDivision_b"));
        buttonDivision_b->setGeometry(QRect(0, 0, 90, 30));
        buttonKrat_b = new QPushButton(frameMain_b);
        buttonKrat_b->setObjectName(QStringLiteral("buttonKrat_b"));
        buttonKrat_b->setGeometry(QRect(0, 30, 90, 30));
        buttonNOT_b = new QPushButton(frameMain_b);
        buttonNOT_b->setObjectName(QStringLiteral("buttonNOT_b"));
        buttonNOT_b->setGeometry(QRect(0, 60, 90, 30));
        buttonMinus_b = new QPushButton(frameMain_b);
        buttonMinus_b->setObjectName(QStringLiteral("buttonMinus_b"));
        buttonMinus_b->setGeometry(QRect(90, 0, 90, 30));
        buttonPlus_b = new QPushButton(frameMain_b);
        buttonPlus_b->setObjectName(QStringLiteral("buttonPlus_b"));
        buttonPlus_b->setGeometry(QRect(90, 30, 90, 30));
        buttonRound_b = new QPushButton(frameMain_b);
        buttonRound_b->setObjectName(QStringLiteral("buttonRound_b"));
        buttonRound_b->setGeometry(QRect(90, 60, 90, 30));
        frameSecond_b = new QFrame(binaryWindow);
        frameSecond_b->setObjectName(QStringLiteral("frameSecond_b"));
        frameSecond_b->setGeometry(QRect(200, 40, 181, 90));
        frameSecond_b->setFrameShape(QFrame::StyledPanel);
        frameSecond_b->setFrameShadow(QFrame::Raised);
        buttonOR_b = new QPushButton(frameSecond_b);
        buttonOR_b->setObjectName(QStringLiteral("buttonOR_b"));
        buttonOR_b->setGeometry(QRect(0, 0, 90, 30));
        buttonAND_b = new QPushButton(frameSecond_b);
        buttonAND_b->setObjectName(QStringLiteral("buttonAND_b"));
        buttonAND_b->setGeometry(QRect(0, 30, 90, 30));
        buttonNAND_b = new QPushButton(frameSecond_b);
        buttonNAND_b->setObjectName(QStringLiteral("buttonNAND_b"));
        buttonNAND_b->setGeometry(QRect(90, 30, 90, 30));
        buttonNOR_b = new QPushButton(frameSecond_b);
        buttonNOR_b->setObjectName(QStringLiteral("buttonNOR_b"));
        buttonNOR_b->setGeometry(QRect(90, 0, 90, 30));
        buttonXNOR_b = new QPushButton(frameSecond_b);
        buttonXNOR_b->setObjectName(QStringLiteral("buttonXNOR_b"));
        buttonXNOR_b->setGeometry(QRect(90, 60, 90, 30));
        buttonXOR_b = new QPushButton(frameSecond_b);
        buttonXOR_b->setObjectName(QStringLiteral("buttonXOR_b"));
        buttonXOR_b->setGeometry(QRect(0, 60, 90, 30));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", Q_NULLPTR));
        buttonSettings->setText(QString());
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\" bgcolor=\"#ffffff\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Verdana'; font-size:14pt;\"><br /></p></body></html>", Q_NULLPTR));
        buttonEnter->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        button1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        button3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        button5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        buttonLeftBar->setText(QApplication::translate("MainWindow", "(", Q_NULLPTR));
        buttonQDot->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        button2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        buttonUndo->setText(QApplication::translate("MainWindow", "<-", Q_NULLPTR));
        buttonANS->setText(QApplication::translate("MainWindow", "ANS", Q_NULLPTR));
        button4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        buttonWReset->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        buttonDivision->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        buttonKrat->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        buttonMinus->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        buttonPlus->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        button0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        button8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        buttonIndex->setText(QApplication::translate("MainWindow", "^", Q_NULLPTR));
        buttonPI->setText(QApplication::translate("MainWindow", "\317\200", Q_NULLPTR));
        buttonRound->setText(QApplication::translate("MainWindow", "RND", Q_NULLPTR));
        buttonFactorial->setText(QApplication::translate("MainWindow", "!", Q_NULLPTR));
        buttonSquare->setText(QApplication::translate("MainWindow", "\342\210\232", Q_NULLPTR));
        button7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        button9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        buttonRightBar->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        button6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        buttonEnter_b->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        button1_b->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        buttonLeftBar_b->setText(QApplication::translate("MainWindow", "(", Q_NULLPTR));
        buttonQDot_b->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        buttonUndo_b->setText(QApplication::translate("MainWindow", "<-", Q_NULLPTR));
        buttonANS_b->setText(QApplication::translate("MainWindow", "ANS", Q_NULLPTR));
        buttonWReset_b->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        button0_b->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        buttonRightBar_b->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        buttonDivision_b->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        buttonKrat_b->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        buttonNOT_b->setText(QApplication::translate("MainWindow", "NOT", Q_NULLPTR));
        buttonMinus_b->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        buttonPlus_b->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        buttonRound_b->setText(QApplication::translate("MainWindow", "RND", Q_NULLPTR));
        buttonOR_b->setText(QApplication::translate("MainWindow", "OR", Q_NULLPTR));
        buttonAND_b->setText(QApplication::translate("MainWindow", "AND", Q_NULLPTR));
        buttonNAND_b->setText(QApplication::translate("MainWindow", "NAND", Q_NULLPTR));
        buttonNOR_b->setText(QApplication::translate("MainWindow", "NOR", Q_NULLPTR));
        buttonXNOR_b->setText(QApplication::translate("MainWindow", "XNOR", Q_NULLPTR));
        buttonXOR_b->setText(QApplication::translate("MainWindow", "XOR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
