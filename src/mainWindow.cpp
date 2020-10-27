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
