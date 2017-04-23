/**
 * @file mainwindow.h
 * @author Jan Bartosek (xbarto92)
 * @author Petr Sopf (xsopfp00)
 * @brief Class for GUI Main Window
 */
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
    /**
     *   @brief Call on number or PI button clicked
     *   @brief Saves the value of button to myQString and display
     *
     *   @return void
     */
    void numberClicked();

    /**
     *   @brief Call on operator button clicked
     *   @brief Saves the value of button to myQString and display
     *
     *   @return void
     */
    void operatorClicked();

    /**
     *   @brief Get char on given position of string
     *   @param position position of char
     *   @return QChar that is on position of myQString
     */
    QChar getChar(int);

    /**
     *   @brief Compares how many left anf right bars are in myQString
     *   @return true if there are more left bars, false if there are equal or more right bars
     */
    bool counter();

    /**
     *   @brief Adds '*' symbol to myQString if need
     *   @return void
     */
    void piMultiply();

    /**
     *   @brief Adds ')' symbol to myQString and display
     *   @return void
     */
    void on_buttonRightBar_clicked();

    /**
     *   @brief Cuts the last char in myQString (few last chars if pi, exp or sqrt was last)
     *   @brief Disable or enable buttons if need
     *   @return void
     */
    void undoClicked();

    /**
     *   @brief Changes between normal and binary mode
     *   @return void
     */
    void on_buttonSettings_clicked();

    /**
     *   @brief Restores content of EntryBox
     *   @return void
     */
    void restoreContent();

    /**
     *   @brief Call on operator button clicked
     *   @brief Saves the value of button to myQString and display
     *   @return void
     */
    void operatorClicked_b();

    /**
     *   @brief Even on Enter button clicked
     *   @return void
     */
    void on_buttonEnter_b_clicked();

    /**
     *   @brief Even on Enter button clicked in binary mode
     *   @return void
     */
    void on_buttonEnter_clicked();

private:
    Ui::MainWindow *ui;
    QString myQString;
};


#endif // MAINWINDOW_H
