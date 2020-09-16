#ifndef MATH_CONVERT_H
#define MATH_CONVERT_H
#include "math.h"
#include "stdio.h"
/*
 * Заголовочный файл в котором описаны основные математические преобразования
 * для описания работы и управления приводом.
*/
void ABC_alfa(float A, float B, float C, float *alf, float *bet);
void alfa_ABC(float *A, float *B, float *C,float alf, float bet);
void alfa_dq(float alf, float bet, float *d, float *q, float teta);
void dq_alfa(float *alf, float *bet, float d, float q, float teta);
void ABC_dq(float A, float B, float C, float *d, float *q, float teta);
void dq_ABC(float *A, float *B, float *C, float d, float q, float teta);
void PI_reg(float x_vh, float *x_vyh, float k_i, float k_p, float *sum_x);

void ABC_alfa(float A, float B, float C, float *alf, float *bet)// переход от трех фазх  к альфа и бетта
{
    *alf=A;
    *bet=(B-C)/1.732;
}
void alfa_ABC(float *A, float *B, float *C,float alf, float bet)//переход от альфа бетта в три фазы
{
    *A = alf;
    *B = (sqrt(3)*bet - alf)/2;
    *C = -(sqrt(3)*bet + alf)/2;
}
void alfa_dq(float alf, float bet, float *d, float *q, float teta)//переходт в Д и КУ от альфы и бетты
{
    *d=alf*cos(teta)+bet*sin(teta);
    *q=bet*cos(teta)-alf*sin(teta);
}
void dq_alfa(float *alf, float *bet, float d, float q, float teta)//переход в альфу и бетту от Д и Ку
{
    *alf = d*cos(teta) - q*sin(teta);
    *bet  = d*sin(teta) + q*cos(teta);
}
void ABC_dq(float A, float B, float C, float *d, float *q, float teta)// переход от трех фазх  к альфа и бетта
{
    float alf, bet;
    alf=A;
    bet=(B-C)/1.732;

    *d=alf*cos(teta)+bet*sin(teta);
    *q=bet*cos(teta)-alf*sin(teta);
}
void dq_ABC(float *A, float *B, float *C, float d, float q, float teta)// переход от трех фазх  к альфа и бетта
{
    float alf, bet;
    alf = d*cos(teta) - q*sin(teta);
    bet  = d*sin(teta) + q*cos(teta);

    *A = alf;
    *B = (sqrt(3)*bet - alf)/2;
    *C = -(sqrt(3)*bet + alf)/2;
}
void PI_reg(float x_vh, float *x_vyh, float k_i, float k_p, float *sum_x)
{
    float x1, x2,dx;
    dx=x_vh;
    x1=dx*k_p;// значение пропорцилонального звена
    //ниже расчет интегральной части
    *sum_x+=dx*k_i;//расчет интеграла, нет учета времени, т.к его можно учесть в интегральном коэффициенте
    x2=*sum_x;
    *x_vyh=x1+x2; //после ПИ регулятора
}

#endif // MATH_CONVERT_H
