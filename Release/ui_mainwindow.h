/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QChartView *widget;
    QChartView *widget_2;
    QChartView *widget_3;
    QChartView *widget_4;
    QTextEdit *text_NengLi;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *zhifangtu_1;
    QPushButton *zizu_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *zizu_1;
    QPushButton *pushButton;
    QPushButton *Show_Chart;
    QPushButton *jichatu_2;
    QPushButton *zhifangtu_2;
    QPushButton *jichatu_1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1961, 1067);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 301, 161));
        widget = new QChartView(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 160, 1371, 271));
        widget->setMinimumSize(QSize(0, 271));
        widget_2 = new QChartView(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(-1, 439, 1371, 261));
        widget_2->setMinimumSize(QSize(0, 261));
        widget_3 = new QChartView(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(1370, 160, 581, 601));
        widget_3->setMinimumSize(QSize(0, 261));
        widget_4 = new QChartView(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 710, 1371, 261));
        widget_4->setMinimumSize(QSize(0, 261));
        text_NengLi = new QTextEdit(centralWidget);
        text_NengLi->setObjectName(QStringLiteral("text_NengLi"));
        text_NengLi->setGeometry(QRect(1370, 760, 171, 211));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 10, 740, 141));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        zhifangtu_1 = new QPushButton(layoutWidget);
        zhifangtu_1->setObjectName(QStringLiteral("zhifangtu_1"));

        gridLayout->addWidget(zhifangtu_1, 1, 3, 1, 1);

        zizu_2 = new QPushButton(layoutWidget);
        zizu_2->setObjectName(QStringLiteral("zizu_2"));

        gridLayout->addWidget(zizu_2, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        zizu_1 = new QPushButton(layoutWidget);
        zizu_1->setObjectName(QStringLiteral("zizu_1"));

        gridLayout->addWidget(zizu_1, 1, 2, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        Show_Chart = new QPushButton(layoutWidget);
        Show_Chart->setObjectName(QStringLiteral("Show_Chart"));

        gridLayout->addWidget(Show_Chart, 1, 0, 1, 1);

        jichatu_2 = new QPushButton(layoutWidget);
        jichatu_2->setObjectName(QStringLiteral("jichatu_2"));

        gridLayout->addWidget(jichatu_2, 2, 1, 1, 1);

        zhifangtu_2 = new QPushButton(layoutWidget);
        zhifangtu_2->setObjectName(QStringLiteral("zhifangtu_2"));

        gridLayout->addWidget(zhifangtu_2, 2, 3, 1, 1);

        jichatu_1 = new QPushButton(layoutWidget);
        jichatu_1->setObjectName(QStringLiteral("jichatu_1"));

        gridLayout->addWidget(jichatu_1, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1961, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        zhifangtu_1->setText(QApplication::translate("MainWindow", "\346\255\243\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-\350\203\275\345\212\233\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        zizu_2->setText(QApplication::translate("MainWindow", "\350\264\237\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-\346\234\200\345\220\21625\344\270\252\345\255\220\347\273\204", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\350\203\275\345\212\233\345\233\276\346\225\260\346\215\256", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\264\237\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-Xbar\346\216\247\345\210\266\345\233\276", Q_NULLPTR));
        zizu_1->setText(QApplication::translate("MainWindow", "\346\255\243\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-\346\234\200\345\220\21625\344\270\252\345\255\220\347\273\204", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\225\260\346\215\256", Q_NULLPTR));
        Show_Chart->setText(QApplication::translate("MainWindow", "\346\255\243\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-Xbar\346\216\247\345\210\266\345\233\276", Q_NULLPTR));
        jichatu_2->setText(QApplication::translate("MainWindow", "\350\264\237\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-R\346\216\247\345\210\266\345\233\276", Q_NULLPTR));
        zhifangtu_2->setText(QApplication::translate("MainWindow", "\350\264\237\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-\350\203\275\345\212\233\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        jichatu_1->setText(QApplication::translate("MainWindow", "\346\255\243\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233-R\346\216\247\345\210\266\345\233\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
