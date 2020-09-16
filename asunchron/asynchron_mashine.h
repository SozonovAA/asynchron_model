#ifndef ASYNCHRON_MASHINE_H
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
    explicit asynchronous_motor(float Ls, float Lr, float Lm_,
                                float Rs, float Rr, float P, float J_, int F){
        L1=Ls;
        L2=Lr;
        Lm=Lm_;
        r1=Rs;
        r2=Rr;
        zp=P;
        J=J_;
        f=F;
    }
    //выходные параметры двигателя:
    float Ia;            //токи статора А
    float Ib;            //             В
    float Ic;            //             С
    float sk_vrash;      //скорость вращения ротора рад/сек
private:
    float L1; //индуктивность статорной обмотки
    float L2; //индуктивность роторной обмотки
    float Lm; //взаимная индукция статорной и роторной обмоток
    float r1; //сопротивление статорной обмотки
    float r2; //сопротивление роторной обмотки
    float zp; //количество полюсов электродвигателя
    float J;  //инерция двигателя
    int f; //частота питающей сети
    float T2=(L2+Lm)*r1;
    float k1=Lm/(L1+Lm);
    float k2=Lm/(L2+Lm);
    float L_1=(L1+Lm)*(1-k1*k2);
    float T_1=L_1/r1;
    float omega= f * 3.14*2;

public slots:
    void model_AM(float Ua, float Ub, float Uc, float M);

};



#endif // ASYNCHRON_MASHINE_H
