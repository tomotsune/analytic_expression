//
// Created by tomot on 2020/10/25.
//

#ifndef ANALYTIC_EXPRESSION_MAINWINDOW_H
#define ANALYTIC_EXPRESSION_MAINWINDOW_H
//#include "QtWidgets"
#include <QMainWindow>
#include "Ui_mainWindow.h"

class MainWindow :public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget* parent=nullptr);

    virtual ~MainWindow();

private:
    Ui::MainWindow*ui;
};


#endif //ANALYTIC_EXPRESSION_MAINWINDOW_H
