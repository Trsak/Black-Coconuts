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
    void func();

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

private:
    Ui::MainWindow *ui;
    QString myQString;
};


#endif // MAINWINDOW_H
