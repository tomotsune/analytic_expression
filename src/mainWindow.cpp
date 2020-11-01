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

void MainWindow::on_okButton_clicked() {

    auto exp{ui->lineEdit->text().toStdString()};
    std::cout<<exp;
    std::cout<<ui->comboBox->currentIndex();
    switch (ui->comboBox->currentIndex()) {
        case 0:
            ui->lineEdit->setText(QString::fromStdString(DAL{exp}.parseRPN().getExpression()));
            break;
        case 1:
            ui->lineEdit->setText(QString::number(RPN{exp}.evaluate(), 10, 4));
            break;
        case 2:
            ui->lineEdit->setText(QString::number(DAL{exp}.evaluate(), 10, 4));
            break;
    }
}
