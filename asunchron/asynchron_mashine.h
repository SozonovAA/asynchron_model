﻿#ifndef ASYNCHRON_MASHINE_H
#define ASYNCHRON_MASHINE_H
#include <QMainWindow>
/*
 * Заголовочный файл в котором описан клас асинхронного двигателя и методы,
 * которые описывают математику работы машины.
 */


class asynchronous_motor : public QObject
{
    Q_OBJECT

public:
    asynchronous_motor(float Ls, float Lr, float Lm_,
                                float Rs, float Rr, float P, float J_, int F);
    //выходные параметры двигателя:
    float Ia;            //токи статора А
    float Ib;            //             В
    float Ic;            //             С
    double sk_vrash;      //скорость вращения ротора рад/сек
private:
    float L1; //индуктивность статорной обмотки
    float L2; //индуктивность роторной обмотки
    float Lm; //взаимная индукция статорной и роторной обмоток
    float r1; //сопротивление статорной обмотки
    float r2; //сопротивление роторной обмотки
    float zp; //количество полюсов электродвигателя
    float J;  //инерция двигателя
    int f; //частота питающей сети
    float T2;
    float k1;
    float k2;
    float L_1;
    float T_1;
    float omega;

public slots:
    void model_AM(float Ua, float Ub, float Uc, float M);

};

#endif // ASYNCHRON_MASHINE_H
