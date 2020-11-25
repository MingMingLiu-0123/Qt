#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "math.h"
#include <QSqlDatabase>
#include <QSqlQuery>//执行sql语句
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>
#include <QList>
#include <QDateTime>
#include <QObject>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Line = 0;
    temp = 0;
    n_A = 0;
    n_B = 0;
    ZF_n = 0;
    ZF_EX = 0;
    ZF_DX = 0;
    for (i=0;i<n_A;i++)
    {
        ZF_y[i] = 0;
    }

    JC_max = 0;
    JC_min = 0;
    //获取当前路径
    qDebug()<<"current applicationDirPath: "<<QCoreApplication::applicationDirPath();
    qDebug()<<"current currentPath: "<<QDir::currentPath();


   // ui->datetimeEdit->setDateTime( QDateTime::currentDateTime() );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getSQLit_clicked()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/QT_Projects/SPC/Data/MarkLogDB.db");//数据库地址

    if (!database.open())
    {
        qDebug() << database.lastError().text();

        QMessageBox::warning(nullptr, "警告", "无法连接数据库！");
    }
    else
    {
        qDebug("Sql connected.");
    }

//读取相应字段存入数组
    float a;
    float b;
    QSqlQuery query;
    QList<float> list_a,list_b;            //创建取结果的列表，之所以使用列表，不用数组，因为现在还不知道结果有多少，不能确定数组长度，所有先用list接收，然后转为数组

    //按时间从数据库中读取,250个数据
    QDateTime datetimeEdit_1=ui->dateTimeEdit->dateTime();
    QString datetime_1 = datetimeEdit_1.toString("yyyy-MM-dd hh:mm:ss");
    QString sqlquery_1 = QString("select * from plclog where createtime >= '%1' limit 250;").arg(datetime_1);
    query.exec(sqlquery_1);

    while (query.next())
    {
        a = query.value("PosiPOAP").toFloat();
        list_a.append(a);                 //如果有数据，取第一列,添加到list

    }
    if(!list_a.empty() && list_a.size()>0)      //如果list中存入了数据，转化为数组
    {
        for(i=0;i<list_a.size();i++)
        {
            A[i]=list_a.at(i);          //数组赋值
        }
    }


    //按时间从数据库中读取,250个数据
    QDateTime datetimeEdit_2=ui->dateTimeEdit->dateTime();
    QString datetime_2 = datetimeEdit_2.toString("yyyy-MM-dd hh:mm:ss");
    QString sqlquery_2 = QString("select * from plclog where createtime >= '%1' limit 250;").arg(datetime_2);
    query.exec(sqlquery_2);
    while (query.next())
    {
        b = query.value("NegaPOAP").toFloat();
        list_b.append(b);                 //如果有数据，取第一列,添加到list

    }
    if(!list_b.empty() && list_b.size()>0)      //如果list中存入了数据，转化为数组
    {
        for(i=0;i<list_b.size();i++)
        {
           B[i]=list_b.at(i);          //数组赋值
        }
    }

    on_data();
}

void MainWindow::on_data()
{
    //分割，处理数据
    int Index = 0;
    for(i=0;i<250;i++)
    {
        if(0 != A[i])
        {
            A[Index++] = A[i];//不等于0的往前移位
        }
    }
    Index = 0;
    for (i=0;i<25;i++)
    {
        temp = 0;
        for (j=0;j<5;j++)
        {

            A_1[i][j] = A[Index++];//取前125个数据分25组
            temp += A_1[i][j];
        }
        ave_A = temp/5;//5点求平均
        A_a[i] = ave_A;
    }
    n_A = 125;


    Index = 0;
    for(i=0;i<250;i++)
    {
        if(0 != B[i])
        {
            B[Index++] = B[i];//不等于0的往前移位
        }
    }
    Index = 0;
    for (i=0;i<25;i++)
    {
        temp = 0;
        for (j=0;j<5;j++)
        {
            B_1[i][j] = B[Index++];//取前125个数据分25组
            temp += B_1[i][j];
        }
        ave_B = temp/5;//5点求平均
        B_b[i] = ave_B;
    }
    n_B = 125;


    min_A = A_1[0][0];
    max_A = A_1[0][0];
    min_B = B_1[0][0];
    max_B = B_1[0][0];
    for (i=0;i<25;i++)
    {
        for (j=0;j<5;j++)
        {
            if(min_A>A_1[i][j])
                min_A = A_1[i][j];
            if(max_A<A_1[i][j])
                max_A = A_1[i][j];

            if(min_B>B_1[i][j])
                min_B = B_1[i][j];
            if(max_B<B_1[i][j])
                max_B = B_1[i][j];
        }
    }
    ZF_blank_A = qAbs((max_A-min_A)/25);//取绝对值
    ZF_blank_B = qAbs((max_B-min_B)/25);

    ZF_n = 0;
    for (i=0;i<25;i++)//分割25个间隔
    {
        for (j=0;j<175;j++)
        {

            if(min_A+ZF_blank_A*i <= A_1[i][j] && A_1[i][j] < min_A+ZF_blank_A*(i+1))
                ZF_n++;
        }
        A_3[i] = ZF_n;
        ZF_n = 0;
        qDebug()<<A_3[i];
    }

    ZF_n = 0;
    for (i=0;i<25;i++)//分割25个间隔
    {
        for (j=0;j<175;j++)
        {
            if(min_B+ZF_blank_B*i <= B_1[i][j] && B_1[i][j]< min_B+ZF_blank_B*(i+1))
                ZF_n++;
        }
        B_3[i] = ZF_n;
        ZF_n = 0;
        qDebug()<<B_3[i];
    }



//=======================================================================
//求极差
    temp = 0;
    for(i=0;i<25;i++)
    {
        JC_max = A_1[i][0];
        JC_min = A_1[i][0];
        for(j=0;j<5;j++)
        {
            if(A_1[i][j]>JC_max)
                JC_max = A_1[i][j];
            if(A_1[i][j]<JC_min)
                JC_min = A_1[i][j];
        }
        JC_A[i] = JC_max - JC_min;//差值
        temp += JC_A[i];
    }
    JC_ave_A = temp/25;


    temp = 0;
    for(i=0;i<25;i++)
    {
        JC_max = B_1[i][0];
        JC_min = B_1[i][0];
        for(j=0;j<5;j++)
        {
            if(B_1[i][j]>JC_max)
                JC_max = B_1[i][j];
            if(B_1[i][j]<JC_min)
                JC_min = B_1[i][j];
        }
        JC_B[i] = JC_max - JC_min;
        temp += JC_B[i];
    }
    JC_ave_B = temp/25;

    JC_max_A = JC_A[0];
    JC_min_A = JC_A[0];
    JC_max_B = JC_B[0];
    JC_min_B = JC_B[0];
    for (i=0;i<25;i++)
    {
        if(JC_min_A>JC_A[i])
            JC_min_A = JC_A[i];
        if(JC_max_A<JC_A[i])
            JC_max_A = JC_A[i];

        if(JC_min_B>JC_B[i])
            JC_min_B = JC_B[i];
        if(JC_max_B<JC_B[i])
            JC_max_B = JC_B[i];
    }
}


//===============================Xbar图表显示按钮========================================
void MainWindow::on_xbar_1_clicked()//显示图表1
{
    int max,ave,min;
    QChart* chart = new QChart();//定义折线
    QLineSeries *series = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();
    QLineSeries *series3 = new QLineSeries();


    QScatterSeries *series0 = new QScatterSeries();//定义 散点
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series0->setMarkerSize(12); //点大小
    chart->setTitle("Xbar控制图");
    series->setName(QStringLiteral("正压"));
    series1->setName(QStringLiteral("LSL"));
    series2->setName(QStringLiteral("AVE"));
    series3->setName(QStringLiteral("USL"));
    series0->setPointLabelsFormat("@yPoint");
    series0->setPointLabelsVisible();//显示数值

    max = A_a[0];
    min = A_a[0];
    temp = 0;
    for (i=0;i<25;i++)
    {
        if(min>A_a[i])
            min = A_a[i];
        if(max<A_a[i])
            max = A_a[i];
        temp += A_a[i];
    }
    ave = temp/25;

    for(i=0;i<25;i++)
    {
        series0->append(i+1,A_a[i]);
        series->append(i+1,A_a[i]);
        series1->append(i+1,min*0.9);
        series2->append(i+1,ave);
        series3->append(i+1,max*1.1);
    }

    for(i=0;i<25;i++)//显示数据
    {
        *series0 << QPointF(i+1,A_a[i]);
    }
    chart->addSeries(series0);
    chart->addSeries(series);
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addSeries(series3);

    chart->createDefaultAxes();

    ui->widget->setChart(chart);

}

void MainWindow::on_xbar_2_clicked()
{
    int max,ave,min;
    QChart* chart = new QChart();//定义折线
    QLineSeries *series = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();
    QLineSeries *series3 = new QLineSeries();

    QScatterSeries *series0 = new QScatterSeries();//定义 散点
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series0->setMarkerSize(12); //点大小
    chart->setTitle("Xbar控制图");
    series->setName(QStringLiteral("负压"));
    series1->setName(QStringLiteral("LSL"));
    series2->setName(QStringLiteral("AVE"));
    series3->setName(QStringLiteral("USL"));
    series0->setPointLabelsFormat("@yPoint");
    series0->setPointLabelsVisible();//显示数值

    max = B_b[0];
    min = B_b[0];
    temp = 0;
    for (i=0;i<25;i++)
    {
        if(min>B_b[i])
            min = B_b[i];
        if(max<B_b[i])
            max = B_b[i];
        temp += B_b[i];
    }
    ave = temp/25;

    for(i=0;i<25;i++)
    {
        series0->append(i+1,B_b[i]);
        series->append(i+1,B_b[i]);
        series1->append(i+1,min*1.1);// 负数最小值扩大
        series2->append(i+1,ave);
        series3->append(i+1,max*0.9);
    }
    chart->addSeries(series0);
    chart->addSeries(series);
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addSeries(series3);

    chart->createDefaultAxes();
    ui->widget->setChart(chart);

}

//=============================R样本极差图=========================
void MainWindow::on_jichatu_1_clicked()
{
    QChart* chart = new QChart();//定义折线
    QLineSeries *series = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();
    QLineSeries *series3 = new QLineSeries();

    QScatterSeries *series0 = new QScatterSeries();//定义 散点
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series0->setMarkerSize(12); //点大小
    chart->setTitle("R控制图");
    series0->setPointLabelsFormat("@yPoint");
    series0->setPointLabelsVisible();//显示数值

    for(i=0;i<25;i++)
    {
        series0->append(i+1,JC_A[i]);
        series->append(i+1,JC_A[i]);
        series1->append(i+1,JC_max_A*1.1);
        series2->append(i+1,JC_ave_A);
        series3->append(i+1,JC_min_A*0.9);

    }
    chart->addSeries(series0);
    chart->addSeries(series);
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addSeries(series3);

    chart->createDefaultAxes();

    ui->widget_2->setChart(chart);

}

void MainWindow::on_jichatu_2_clicked()
{
    QChart* chart = new QChart();//定义折线
    QLineSeries *series = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();
    QLineSeries *series3 = new QLineSeries();

    QScatterSeries *series0 = new QScatterSeries();//定义 散点
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series0->setMarkerSize(12); //点大小
    chart->setTitle("R控制图");
    series0->setPointLabelsFormat("@yPoint");
    series0->setPointLabelsVisible();//显示数值

    for(i=0;i<25;i++)
    {
        series0->append(i+1,JC_B[i]);
        series->append(i+1,JC_B[i]);
        series1->append(i+1,JC_max_B*1.1);
        series2->append(i+1,JC_ave_B);
        series3->append(i+1,JC_min_B*0.9);

    }
    chart->addSeries(series0);
    chart->addSeries(series);
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addSeries(series3);

    chart->createDefaultAxes();

    ui->widget_2->setChart(chart);

}


//=======================================最后子组按钮=============================================
void MainWindow::on_zizu_1_clicked()
{
    QChart* chart = new QChart();

    QScatterSeries *series1 = new QScatterSeries();//定义 散点
    series1->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series1->setMarkerSize(12);                     //点大小
    chart->setTitle("最后25个子组");

    for(i=0;i<25;i++)
    {
        for (j=0;j<5;j++)
        {
            series1->append(i,A_1[i][j]);
        }

    }
    chart->addSeries(series1);

    chart->createDefaultAxes();

    ui->widget_4->setChart(chart);
}

void MainWindow::on_zizu_2_clicked()
{
    QChart* chart = new QChart();

    QScatterSeries *series1 = new QScatterSeries();//定义 散点
    series1->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series1->setMarkerSize(12);                     //点大小
    chart->setTitle("最后25个子组");


    for(i=0;i<25;i++)
    {
        for (j=0;j<5;j++)
        {
            series1->append(i,B_1[i][j]);
        }

    }
    chart->addSeries(series1);

    chart->createDefaultAxes();

    ui->widget_4->setChart(chart);
}

//====================================能力直方图================================
void MainWindow::on_zhifangtu_1_clicked()
{
    QChart *chart = new QChart();
    QBarSeries *series2 = new QBarSeries();
    QSplineSeries *series3 = new QSplineSeries();
    chart->setTitle("能力直方图");
    ZF_EX = 0;ZF_DX = 0;
    float t,t2;

    for (i=0;i<n_A/5;i++)
    {
        for(j=0;j<5;j++)
        {
            ZF_EX += A_1[i][j];
        }
    }
    ZF_EX = ZF_EX/n_A;
    for (i=0;i<n_A/5;i++)
    {
        for(j=0;j<5;j++)
        {
            ZF_DX += pow((A_1[i][j] - ZF_EX),2);
        }
    }
    ZF_DX = ZF_DX/n_A;
    for (i=0;i<n_A;i++)
    {
        t2 = -23000+i*1000-ZF_EX;
        t = -0.5*t2*t2/ZF_DX;
        //ZF_y[i] = exp(- pow((29000+i*20-ZF_EX),2) / 2*ZF_DX) / (sqrt(2*3.14*ZF_DX))*200000;
        ZF_y[i] = 1.0/(sqrt(2*3.14*ZF_DX))*exp(t);
    }
    for (i=0;i<101;i++)//画正态曲线
    {
        series3->append(min_A+i*100,ZF_y[i]*500000);
    }


    for (i=0;i<25;i++)//柱状图
    {
        QBarSet *set = new QBarSet(QString("%1").arg(min_A+ZF_blank_A*i));
        *set << A_3[i];
        series2->append(set);
    }

    chart->addSeries(series2);
    chart->addSeries(series3);
    chart->createDefaultAxes();
    ui->widget_3->setChart(chart);
}

void MainWindow::on_zhifangtu_2_clicked()
{
    QChart *chart = new QChart();
    QBarSeries *series2 = new QBarSeries();
    QSplineSeries *series3 = new QSplineSeries();
    chart->setTitle("能力直方图");

    ZF_EX = 0;ZF_DX = 0;
    float t,t2;

    for (i=0;i<n_B/5;i++)
    {
        for(j=0;j<5;j++)
        {
            ZF_EX += B_1[i][j];
        }
    }
    ZF_EX = ZF_EX/n_B;
    for (i=0;i<n_B/5;i++)
    {
        for(j=0;j<5;j++)
        {
            ZF_DX += pow((B_1[i][j] - ZF_EX),2);
        }
    }
    ZF_DX = ZF_DX/n_B;
    for (i=0;i<500;i++)
    {
        t2 = -27000+i*500-ZF_EX;
        t = -0.5*t2*t2/ZF_DX;
        ZF_y[i] = 1.0/(sqrt(2*3.14*ZF_DX))*exp(t);
    }
    for (i=0;i<101;i++)//画正态曲线
    {
        series3->append(min_B+i*180,ZF_y[i]*230000);
    }
    for (i=0;i<25;i++)
    {
        QBarSet *set = new QBarSet(QString("%1").arg(min_B+ZF_blank_B*i));
        *set << B_3[i];
        series2->append(set);
    }


    chart->addSeries(series2);
    chart->addSeries(series3);
    chart->createDefaultAxes();
    ui->widget_3->setChart(chart);
}

//=================================求CPK，PPK=================================
void MainWindow::on_pushButton_4_clicked()
{
    //求CPK.PPK
    float max_cpk,min_cpk,sum_cpk=0,midmin_cpk=0;
    float max_ppk,min_ppk,sum_ppk=0,midmin_ppk=0;
    max_cpk = A_a[0];
    min_cpk = A_a[0];
    max_ppk = A_1[0][0];
    min_ppk = A_1[0][0];
    sum_cpk = 0;
    sum_ppk = 0;
    for(i=0;i<25;i++)//找上下限
        for(j=0;j<5;j++)
        {
            if(A_1[i][j]>max_ppk)//ppk选取175
                max_ppk = A_1[i][j];
            if(A_1[i][j]<min_ppk)
                min_ppk = A_1[i][j];
            sum_ppk += A_1[i][j];
        }
    for(j=0;j<25;j++)
    {
        if(A_a[j]>max_cpk)//cpk选取xBar数据
            max_cpk = A_a[j];
        if(A_a[j]<min_cpk)
            min_cpk = A_a[j];
        sum_cpk += A_a[j];
    }
    UCL_cpk[0] = max_cpk;
    LCL_cpk[0] = min_cpk;
    Avg_cpk[0] = sum_cpk/25;

    UCL_ppk[0] = max_ppk;
    LCL_ppk[0] = min_ppk;
    Avg_ppk[0] = sum_ppk/n_A;


    for(i=0;i<25;i++)//求标准差
        for(j=0;j<5;j++)
        {
            sum_ppk += pow((A_1[i][j] - Avg_ppk[0]),2);
        }
    for(j=0;j<25;j++)
    {
        sum_cpk += pow((A_a[j] - Avg_cpk[0]),2);
    }
    BZC_cpk[0] = sqrt(sum_cpk/25);
    BZC_ppk[0] = sqrt(sum_ppk/n_A);
    if((UCL_cpk[0]-Avg_cpk[0])>(Avg_cpk[0]-LCL_cpk[0]))//取两者较小值
        midmin_cpk = Avg_cpk[0]-LCL_cpk[0];
    else
        midmin_cpk = UCL_cpk[0]-Avg_cpk[0];
    CPK[0] =  midmin_cpk/(3*BZC_cpk[0]);

    if((UCL_ppk[0]-Avg_ppk[0])>(Avg_ppk[0]-LCL_ppk[0]))//取两者较小值
        midmin_ppk = Avg_ppk[0]-LCL_ppk[0];
    else
        midmin_ppk = UCL_ppk[0]-Avg_ppk[0];
    PPK[0] =  midmin_ppk/(3*BZC_ppk[0]);

    ui->text_NengLi->append(QString("正压标准差: %1   正压CPK: %2   正压PPK: %3").arg(BZC_ppk[0]).arg(CPK[0]).arg(PPK[0]));


    max_cpk = B_b[j];
    min_cpk = B_b[j];
    max_ppk = B_1[0][0];
    min_ppk = B_1[0][0];
    sum_cpk = 0;
    sum_ppk = 0;
    for(i=0;i<25;i++)//找上下限
        for(j=0;j<5;j++)
        {
            if(B_1[i][j]>max_ppk)//ppk选取当日所有数据
                max_ppk = B_1[i][j];
            if(B_1[i][j]<min_ppk)
                min_ppk = B_1[i][j];
            sum_ppk += B_1[i][j];
        }
    for(j=0;j<25;j++)
    {
        if(B_b[j]>max_cpk)//cpk选取xBar数据
            max_cpk = B_b[j];
        if(B_b[j]<min_cpk)
            min_cpk = B_b[j];
        sum_cpk += B_b[j];
    }
    UCL_cpk[1] = max_cpk;
    LCL_cpk[1] = min_cpk;
    Avg_cpk[1] = sum_cpk/25;

    UCL_ppk[1] = max_ppk;
    LCL_ppk[1] = min_ppk;
    Avg_ppk[1] = sum_ppk/n_B;

    for(i=0;i<25;i++)//求标准差
        for(j=0;j<5;j++)
        {
            sum_ppk += pow((B_1[i][j] - Avg_ppk[1]),2);
        }
    for(j=0;j<25;j++)
    {
        sum_cpk += pow((B_b[j] - Avg_cpk[1]),2);
    }
    BZC_cpk[1] = sqrt(sum_cpk/25);
    BZC_ppk[1] = sqrt(sum_ppk/n_B);

    if((UCL_cpk[1]-Avg_cpk[1])>(Avg_cpk[1]-LCL_cpk[1]))//取两者较小值
        midmin_cpk = Avg_cpk[1]-LCL_cpk[1];
    else
        midmin_cpk = UCL_cpk[1]-Avg_cpk[1];
    CPK[1] =  midmin_cpk/(3*BZC_cpk[1]);

    if((UCL_ppk[1]-Avg_ppk[1])>(Avg_ppk[1]-LCL_ppk[1]))//取两者较小值
        midmin_ppk = Avg_ppk[1]-LCL_ppk[1];
    else
        midmin_ppk = UCL_ppk[1]-Avg_ppk[1];
    PPK[1] =  midmin_ppk/(3*BZC_ppk[1]);

    ui->text_NengLi->append(QString("负压标准差: %1   负压CPK: %2   负压PPK: %3").arg(BZC_ppk[1]).arg(CPK[1]).arg(PPK[1]));

}


void MainWindow::on_zhengya_clicked()
{
    on_xbar_1_clicked();
    on_zizu_1_clicked();
    on_zhifangtu_1_clicked();
    on_jichatu_1_clicked();

}

void MainWindow::on_fuya_clicked()
{
    on_xbar_2_clicked();
    on_zizu_2_clicked();
    on_zhifangtu_2_clicked();
    on_jichatu_2_clicked();

}
