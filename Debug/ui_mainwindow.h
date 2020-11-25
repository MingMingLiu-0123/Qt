/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QChartView *widget;
    QChartView *widget_2;
    QChartView *widget_3;
    QChartView *widget_4;
    QTextEdit *text_NengLi;
    QWidget *widget1;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QSpinBox *spinBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *getSQLit;
    QPushButton *zhengya;
    QPushButton *fuya;
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
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(40, 40, 811, 101));
        gridLayout_3 = new QGridLayout(widget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 4, 1, 1);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        dateTimeEdit = new QDateTimeEdit(widget1);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setDate(QDate(2020, 1, 1));

        gridLayout_2->addWidget(dateTimeEdit, 0, 1, 1, 1);

        spinBox = new QSpinBox(widget1);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout_2->addWidget(spinBox, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_4 = new QPushButton(widget1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        getSQLit = new QPushButton(widget1);
        getSQLit->setObjectName(QStringLiteral("getSQLit"));

        gridLayout->addWidget(getSQLit, 0, 0, 1, 1);

        zhengya = new QPushButton(widget1);
        zhengya->setObjectName(QStringLiteral("zhengya"));

        gridLayout->addWidget(zhengya, 1, 0, 1, 1);

        fuya = new QPushButton(widget1);
        fuya->setObjectName(QStringLiteral("fuya"));

        gridLayout->addWidget(fuya, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

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
        label->setText(QApplication::translate("MainWindow", "\344\273\216", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\210\206\351\222\237\345\217\226\346\240\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\357\274\214\351\227\264\351\232\224", Q_NULLPTR));
        dateTimeEdit->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd HH:mm:ss", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\350\203\275\345\212\233\345\233\276\346\225\260\346\215\256", Q_NULLPTR));
        getSQLit->setText(QApplication::translate("MainWindow", "\346\214\207\345\256\232\346\227\266\351\227\264\345\274\200\345\247\213\346\237\245\350\257\242", Q_NULLPTR));
        zhengya->setText(QApplication::translate("MainWindow", "\346\255\243\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233\345\210\206\346\236\220", Q_NULLPTR));
        fuya->setText(QApplication::translate("MainWindow", "\350\264\237\345\216\213\345\274\200\345\220\257\345\216\213\345\212\233\345\210\206\346\236\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
