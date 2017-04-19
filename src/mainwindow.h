#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    QChar getChar(int);
    bool counter();
    void afterRightBar();
    void countBar(bool=false);
    void piMultiply();
    void slide();
    void disableButton();
    void enableButton();
    void on_buttonZero_clicked();
    void on_buttonOne_clicked();
    void on_buttonTwo_clicked();
    void on_buttonThree_clicked();
    void on_buttonFour_clicked();
    void on_buttonFive_clicked();
    void on_buttonSix_clicked();
    void on_buttonSeven_clicked();
    void on_buttonEight_clicked();
    void on_buttonNine_clicked();
    void on_buttonDot_clicked();
    void on_buttonPercentage_clicked();
    void on_buttonReset_clicked();
    void on_buttonUndo_clicked();
    void on_buttonLeftBar_clicked();
    void on_buttonRightBar_clicked();
    void on_buttonIndex_clicked();
    void on_buttonSquare_clicked();
    void on_buttonPI_clicked();
    void on_buttonFactorial_clicked();
    void on_buttonDivision_clicked();
    void on_buttonMinus_clicked();
    void on_buttonMultiply_clicked();
    void on_buttonPlus_clicked();
    void on_buttonSettings_clicked();

    void slide_2();
    void enableButton_2();
    void on_buttonReset_2_clicked();
    void disableButton_2();
    void countBar_2(bool=false);

    void on_buttonUndo_2_clicked();

    void on_buttonZero_2_clicked();

    void on_buttonOne_2_clicked();

    void on_buttonDot_2_clicked();

    void on_buttonDivision_2_clicked();

    void on_buttonMinus_2_clicked();

    void on_buttonMultiply_2_clicked();

    void on_buttonNOT_2_clicked();

    void on_buttonPlus_2_clicked();

    void on_buttonAND_2_clicked();

    void on_buttonNAND_2_clicked();

    void on_buttonNOR_2_clicked();

    void on_buttonOR_2_clicked();

    void on_buttonXNOR_2_clicked();

    void on_buttonXOR_2_clicked();

    void on_buttonLeftBar_2_clicked();

    void on_buttonRightBar_2_clicked();

private:
    Ui::MainWindow *ui;
    QString myQString;
};


#endif // MAINWINDOW_H
