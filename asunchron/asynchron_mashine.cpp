#include "asynchron_mashine.h"
#include "math_convert.h"

 void asynchronous_motor::model_AM(float Ua, float Ub, float Uc, float M){

     static float Ualfa=0, Ubetta=0, Tetta=0;
     static float U1d=0, U1q=0;
     static float dt=0.0001; //шаг расчёта, надо подумать, как граммотно его использовать в модуляции
     static float di1d=0,di1q=0;
     static float i1d=0,i1q=0;
     static float psi2d=0, dpsi2d=0;
     static float dif=0, ym1=0, summ1=0;//верхний сумматор
     static float summ2=0, ym2=0, ym3=0;//нижний сумматор
     static float ym4=0, mitog=0, m=0, mc=0, ym5=0, w2=0, w=0, w1=0, omega_itog=0, ym6=0;
     float summ11=0,summ21=0, i11d=0, ym5_new=0, ym5_old=0, dym5=0, alfa_buf=0, betta_buf=0 ,
     abuf=0, bbuf=0, cbuf=0,sk_vrash;
     mc=M;
     /////////////////////////////////////////////Переменные для векторного управления
     static float  Tetta_reg=0, id_reg=0, iq_reg=0;
     //////////////////////////////АД модель тау уравнения////////////////////////////////////////////////////////////
              ABC_dq(Ua, Ub, Uc, &U1d, &U1q, Tetta);

              summ1=U1d+ym1-dif;//расчет верхнего сумматора
              summ2=U1q-ym2-ym3;//рассчет нижнего сумматора
              summ11=summ1/r1;  //вводим коэффициент для расчета звена
              summ21=summ2/r1;  //вводим коэффициент для расчета звена
              di1d= ((summ11-i1d)/T_1)*dt;//расчет Аппериодического звена верхнего
              i1d+=di1d;
              di1q= ((summ21-i1q)/T_1)*dt;//расчет Аппериодического звена нижнего
              i1q+=di1q;
              i11d=i1d*Lm;
              dpsi2d=((i11d-psi2d)/T2)*dt;
              psi2d+=dpsi2d;
              ym4=i1q*(Lm/T2);
              ym6=psi2d*ym4;
              m=ym6*((3*zp)/(2*r2));
              mitog=m-mc;
              if (mitog==0) mitog=0.00001;
              omega_itog+=(mitog/J)*dt;
              if(psi2d==0) psi2d=0.0001;
              w2=ym4/psi2d;
              w=omega_itog*zp;
              w1=w2+w;
              ym5_old=ym5;
              ym5=k2*psi2d;
              ym5_new=ym5;
              dym5=ym5_new- ym5_old;
              ym3=ym5*w1;
              ym2=w1*L_1*i1d;
              ym1=w1*L_1*i1q;
              Tetta+= dt*w1;
              dif=dym5/dt;
     ////////////////////////////////АД модель тау уравнения///////////////////////////////////////////////////
              alfa_buf=Ualfa;
              betta_buf=Ubetta;
     ////////////////////////////////Выходные параметры АД//////////////////////////////////////////
            dq_ABC(&abuf, &bbuf, &cbuf, i1d, i1q, Tetta);
            Ia=abuf;            //токи статора А
            Ib=bbuf;            //             В
            Ic=cbuf;            //             С
            ABC_dq(Ia , Ib, Ic, &id_reg, &iq_reg,  Tetta_reg);
            sk_vrash=omega_itog;  //скорость вращения ротора рад/сек
     ////////////////////////////////Выходные параметры АД//////////////////////////////////////////
 }
