#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "biguint.h"

namespace Ui {
class calculator;
}

class calculator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();
    
private slots:
    void on_lineEdit_op1_textChanged(const QString &arg1);

    void on_lineEdit_op2_textChanged(const QString &arg1);

    void on_pb_add_clicked();

    void on_pb_multiply_clicked();

    void on_pb_subtract_clicked();

    void on_actionAbout_triggered();

    void on_actionAbout_2_triggered();

    void on_pb_divide_clicked();

    void on_pb_mod_clicked();

    void on_pushButton_clicked();

private:
    Ui::calculator *ui;
    biguint op1, op2, result;
};

#endif // CALCULATOR_H
