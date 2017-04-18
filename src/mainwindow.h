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

private:
    Ui::MainWindow *ui;
    QString myQString;
};


#endif // MAINWINDOW_H
