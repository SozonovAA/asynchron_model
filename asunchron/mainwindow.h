#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "math.h"
#include "qcustomplot.h"
#include "asynchron_mashine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    asynchronous_motor *am;
    //QTimer
    QTimer timer_100_ms;
    //QTimer timer_1000_ms;
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    //таймеры
    void timeout_100_ms();
   // void timeout_1000_ms();
};

#endif // MAINWINDOW_H
