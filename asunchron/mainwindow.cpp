#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
QRgb graf_rgb[12]={ //создание массива цвыетов, для графиков
    0x5df745,
    0x2bdecf,
    0xB6D094 ,
    0xff0524 ,
    0x07aced,
    0xf2545b ,
    0xa29f15 ,
    0xf3b61f ,
    0xbbd8b3  ,
    0xd449c4 ,
    0xfff4e9 ,
    0xf5741f ,
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer_100_ms.start(10);//настройка таймеров
    connect(&timer_100_ms, SIGNAL(timeout()),
            this, SLOT(timeout_100_ms())); //подключаем(запускаем) тамер на 1/10 С


    for(int i=0;i<5;i++)
    {
        ui->widget->addGraph(); //инициализация графиков
        ui->widget->graph()->setPen(QPen(QColor(graf_rgb[i]))); //смена цветов у графиков
        ui->widget->graph()->setName(QString("ADC_chanel %1").arg(i+1));
    }
    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->setBackground(QColor(50,50,50));//задание цвета
    ui->widget->setInteractions(QCP::iRangeZoom); //разрешаем зум по графику
    ui->widget->setInteraction(QCP::iRangeDrag, false);  // отключаем взаимодействие перетаскивания графика
ui->widget->xAxis->setRange(0,10); //рендж во всех других случаях
ui->widget->yAxis->setRange(0,3000); //рендж во всех других случаях

    am= new asynchronous_motor(0.005974,0.005974, 0.2037, 1.115, 1.083,2,0.02, 60);
}


void MainWindow::timeout_100_ms(){
    double Ua, Ub, Uc;
    static float T=0;




    Ua=320 * sin(60*2*3.14*T);
    Ub=320 * sin(60*2*(3.14)*T-(3.14*2/3));
    Uc=320 * sin(60*2*(3.14)*T+(3.14*2/3));




        ui->widget->replot();
    am->model_AM(Ua,Ub,Uc,0);
    ui->widget->graph(0)->addData(T,am->sk_vrash);
    qDebug()<<am->sk_vrash;


//    ui->widget->graph(1)->addData(T,Ub);
//    ui->widget->graph(2)->addData(T,Uc);
    T+=0.001;
}

MainWindow::~MainWindow()
{
    delete ui;
}
