//
// Created by tomot on 2020/10/25.
//

#include "mainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::conversion() {
    DAL dal{ui->expressionTxt->toPlainText().toStdString()};
    ui->expressionTxt->setText( QString::fromStdString(dal.parseRPN().getExpression()));
}

void MainWindow::evaluateRPN() {
    RPN rpn{ui->expressionTxt->toPlainText().toStdString()};
    ui->expressionTxt->setText( QString::number(rpn.evaluate(),10,4));
}

void MainWindow::evaluateDAL() {
    DAL dal{ui->expressionTxt->toPlainText().toStdString()};
    ui->expressionTxt->setText( QString::number(dal.evaluate(),10,4));
}

void MainWindow::getHelp() {
    ui->expressionTxt->setText(" 1.When you use function 1,the input must consist of letters "
                               "and operators,and cannot contain spaces "
                               "2.When using function 2, the input can be multiple floating-point numbers "
                               "and separated by spaces"
                               "3.When you use function 3, the input must consist of 0-9 integer numbers "
                               "and operators,and cannot contain spaces");
}
