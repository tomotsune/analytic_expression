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
    qDebug()<<"被点击";
    auto exp{ui->lineEdit->text().toStdString()};
    QString text{};
    switch (ui->comboBox->currentIndex()) {
        case 0:
            text=QString::fromStdString(DAL{exp}.parseRPN().getExpression());
            break;
        case 1:
            text=QString::number(RPN{exp}.evaluate(), 10, 4);
            break;
        case 2:
            text=QString::number(DAL{exp}.evaluate(), 10, 4);
            break;
        default:
            break;
    }
    qDebug()<<text;
    ui->lineEdit->setText(text);
}
