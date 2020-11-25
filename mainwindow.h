#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QChartView>
#include <QSplineSeries>
#include <QSqlDatabase>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
//--------原数据--去0后数据----Xbar数据---直方图数据
    float A[250],A_1[25][5],A_a[25],A_3[25];
    float B[250],B_1[25][5],B_b[25],B_3[25];


    int Line;
    int i,j;
    int n_A,n_B;//处理后每列的个数
    float temp;
    float min_A,ave_A,max_A,min_B,ave_B,max_B;
    float ZF_blank_A,ZF_blank_B,ZF_n,ZF_EX,ZF_DX,ZF_x[550],ZF_y[550];//直方图
    float USL[2];//上限
    float LSL[2];//下限
    float CL[2];//中线

    float JC_A[25],JC_B[25];//极差数组
    float JC_max,JC_min,JC_max_A,JC_ave_A,JC_min_A,JC_max_B,JC_ave_B,JC_min_B;

    float BZC_cpk[2],BZC_ppk[2];//标准差
    float UCL_cpk[2],LCL_cpk[2],Avg_cpk[2],UCL_ppk[2],LCL_ppk[2],Avg_ppk[2];//上限，下限，平均值
    float PPK[2],CPK[2];

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectMYSQL();

private slots://槽函数

    void on_getSQLit_clicked();

    void on_data();

    void on_xbar_1_clicked();

    void on_xbar_2_clicked();

    void on_zizu_1_clicked();

    void on_zizu_2_clicked();

    void on_zhifangtu_1_clicked();

    void on_zhifangtu_2_clicked();

    void on_jichatu_1_clicked();

    void on_jichatu_2_clicked();

    void on_pushButton_4_clicked();

    void on_zhengya_clicked();

    void on_fuya_clicked();



private:
    Ui::MainWindow *ui;

    QSqlDatabase database;

};

#endif // MAINWINDOW_H
