//
// Created by tomot on 2020/10/25.
//

#ifndef ANALYTIC_EXPRESSION_MAINWINDOW_H
#define ANALYTIC_EXPRESSION_MAINWINDOW_H
//#include "QtWidgets"
#include <QMainWindow>
#include "Ui_mainWindow.h"
#include "DAL.h"
#include "RPN.h"

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    virtual ~MainWindow();


public slots:

    void conversion();

    void evaluateRPN();

    void evaluateDAL();

    void getHelp();

private:
    Ui::MainWindow *ui;
};


#endif //ANALYTIC_EXPRESSION_MAINWINDOW_H
