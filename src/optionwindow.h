#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QDialog>

namespace Ui {
class OptionWindow;
}

class OptionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OptionWindow(QWidget *parent = 0);
    ~OptionWindow();

private:
    Ui::OptionWindow *ui;
};

#endif // OPTIONWINDOW_H
