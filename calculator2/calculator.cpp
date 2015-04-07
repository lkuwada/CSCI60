#include "calculator.h"
#include "ui_calculator.h"
#include "dialog.h"

calculator::calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
}

calculator::~calculator()
{
    delete ui;
}

void calculator::on_lineEdit_op1_textChanged(const QString &arg1)
{
    op1 = biguint(arg1.toStdString());
    std::cout << op1 << std::endl;
}

void calculator::on_lineEdit_op2_textChanged(const QString &arg1)
{
    op2 = biguint(arg1.toStdString());
    std::cout << op2 << std::endl;
}

void calculator::on_pb_add_clicked()
{
    result = op1 + op2;
    ui->lineEdit_result->setText(QString(result.toStdString().c_str()));

    std::cout << result.toStdString() << std::endl;
}

void calculator::on_pb_multiply_clicked()
{
    result = op1 * op2;
    std::string s = result.toStdString();
    ui->lineEdit_result->setText(QString(s.c_str()));

    std::cout << s << std::endl;
}

void calculator::on_pb_subtract_clicked()
{
    result = op1 - op2;
    std::string s = result.toStdString();
    ui->lineEdit_result->setText(QString(s.c_str()));

    std::cout << s << std::endl;
}

void calculator::on_actionAbout_triggered()
{
    exit(0);
}

void calculator::on_actionAbout_2_triggered()
{
    Dialog *about = new Dialog();
    about->show();
}

void calculator::on_pb_divide_clicked()
{
    result = op1 / op2;
    std::string s = result.toStdString();
    ui->lineEdit_result->setText(QString(s.c_str()));

    std::cout << s << std::endl;
}

void calculator::on_pb_mod_clicked()
{
    result = op1 % op2;
    std::string s = result.toStdString();
    ui->lineEdit_result->setText(QString(s.c_str()));

    std::cout << s << std::endl;
}

void calculator::on_pushButton_clicked()
{
    result = 1;
    for (biguint i = 1; i <= op1; i += 1)
        result *= i;

    std::string s = result.toStdString();
    ui->lineEdit_result->setText(QString(s.c_str()));

    std::cout << s << std::endl;
}
