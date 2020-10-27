/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *readMe;
    QWidget *centralwidget;
    QTextEdit *expressionTxt;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(381, 415);
        readMe = new QAction(MainWindow);
        readMe->setObjectName(QString::fromUtf8("readMe"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        expressionTxt = new QTextEdit(centralwidget);
        expressionTxt->setObjectName(QString::fromUtf8("expressionTxt"));
        expressionTxt->setGeometry(QRect(20, 20, 341, 151));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        expressionTxt->setFont(font);
        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(20, 200, 221, 23));
        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(20, 240, 221, 23));
        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(20, 280, 221, 23));
        btn_4 = new QPushButton(centralwidget);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(20, 320, 221, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 381, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(readMe);

        retranslateUi(MainWindow);
        QObject::connect(btn_1, SIGNAL(clicked()), MainWindow, SLOT(conversion()));
        QObject::connect(btn_2, SIGNAL(clicked()), MainWindow, SLOT(evaluateRPN()));
        QObject::connect(btn_3, SIGNAL(clicked()), MainWindow, SLOT(evaluateDAL()));
        QObject::connect(btn_4, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(readMe, SIGNAL(triggered()), MainWindow, SLOT(getHelp()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        readMe->setText(QCoreApplication::translate("MainWindow", "readMe", nullptr));
        btn_1->setText(QCoreApplication::translate("MainWindow", "1.DAL->RPN", nullptr));
        btn_2->setText(QCoreApplication::translate("MainWindow", "2.RPN", nullptr));
        btn_3->setText(QCoreApplication::translate("MainWindow", "3.DAL", nullptr));
        btn_4->setText(QCoreApplication::translate("MainWindow", "4.EXIT", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
