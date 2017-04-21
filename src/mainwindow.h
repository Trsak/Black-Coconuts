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

    void slide();
    void numberClicked();
    void operatorClicked();
    QChar getChar(int);
    bool counter();
    void afterRightBar();
    void piMultiply();
    void on_buttonRightBar_clicked();
    void on_buttonUndo_clicked();
    void on_buttonSettings_clicked();

    void operatorClicked_b();
    void on_buttonUndo_b_clicked();
    void on_buttonRightBar_b_clicked();

    void on_buttonEnter_b_clicked();

    void on_buttonEnter_clicked();

private:
    Ui::MainWindow *ui;
    QString myQString;
};


#endif // MAINWINDOW_H
