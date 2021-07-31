#include "sfp.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

sfp int2sfp(int input){
    sfp z = 0x0000;     /*���̽��� sfp���� �ϳ� �������ݴϴ�.*/
    int k =0;
    int i =0;
    int b =1;
    int x;
    if(input < 0){
        z = z|0x8000;
        x= -input;}     /*�����̸� -�� �ٿ� ������� �޾��ݴϴ�.*/
    else if(input >0)
        x= input;
    else
        x =0;
    int y =x;
    while(y > 1){
        y= y/2;
        k++;
    }                   /*2�� �ִ��� ������ 2�� �������� �����ݴϴ�.*/
    int exp = k+31;     /*bias���� �����ݴϴ�.*/
    if(x ==0)
        exp =0;
    int a = x;
    for(i=0; i<k; i++)
        b = b*2;
    a = a-b;    /*frac���� 1�� ������ �ݴϴ�.*/
    if(exp >0 && exp < 63){ /*exp���� normal�̸� ���ó�� ������ݴϴ�.*/
        exp = exp <<9;
        z = z + exp;
        if(k<=8){
            for(i=0; i<9-k; i++)
                a = a<<1;}  /*k�� ������ frac�� ���� ���ʱ��� ����ݴϴ�.(9��° ��Ʈ����)*/
        else{
            for(i=0; i<k-9; i++)
                a = a>>1;}  /*k�� ũ�� frac�� ���� �ٱ������� �����ݴϴ�.(9��°��Ʈ����)*/
    z = z + a;}
/*z�� frac���� �����ݴϴ�. ���ʿ� exp�� 0�̸� ���������� frac�� 0�̹Ƿ� �Ű澲�� �ʾҽ��ϴ�.*/


    return z;



}



int sfp2int(sfp input){

    sfp m;
    sfp k = input;
    m = input & 0x7FFF;     /*m�� sign�� ������ input���� �޽��ϴ�.*/

    int a;
    int n=0;
    int x;
    x = input >>9;      /*exp���� �޽��ϴ�.*/
    int y,i;
    y = input & 0x01FF;     /*frac���� �޽��ϴ�.*/
    if(x>=31){
        for(i=0; i<x-31; i++)
            n++;        /*exp�� 31����ũ�� 2^n�� ���ϱ����� 2�� x-31��ŭ �������ݴϴ�.*/
    }
    else
        a=0;        /*ó���� int���� �޾Ƽ� exp�� 31���� ������ 0�Դϴ�.*/
    if(n!=0)
        y = y+0x0200;   /*exp�� 0�� �ƴϸ� frac �� �տ� 1�� �����ݴϴ�.*/
    else
        y=y;
    if(n<9){
        y=y>>(9-n);
    }
    else
        y = y<<(n-9);       /*frac�� ���ڿ� ���� ��Ʈ �̵��� ���ݴϴ�.*/


    if(m == k)
        a = y;      /*����̸� �״�� a�� �޾��ݴϴ�.*/
    else
        a= -y;      /*�����̸� �������� -�� �ٿ��ݴϴ�.*/

    return a;
}

sfp float2sfp(float input){
    float b;
    b= input;   /*input���� ���� �޾��ݴϴ�.*/
    int over=0; /*���� �ʰ��Ҷ��� ���� over�� ������ֿ����ϴ�*/

    int a = 0;
    sfp sign;
    if(b<0)
        sign = 0x8000;
    else
        sign =0;    /*sign��Ʈ�� ���� �޾��ݴϴ�.*/
    memcpy((void*)(&a),(void*)(&b),sizeof(a));  /*float���� bitwise���ֱ����� memcpy�� ����մϴ�.*/
    int exp;
    exp = a & 0x7F800000;
    if(exp <=0x4F800000 && exp >0x30000000){    /*exp�� �������� bias�� bit ���̸� ������ݴϴ�.*/
    exp = exp >>23;
    exp = exp-127+31;
    exp = exp <<9;
    }
    else if(exp > 0x4F800000)       /*ǥ�� �������� ũ�� over�� ���ݴϴ�.*/
        over=1;
    else                    /*ǥ���������� ������ 0���� �ٲ��ݴϴ�.*/
        exp =0;

    int frac = a & 0x007FFFFF;  /*frac�κ��� �����ݴϴ�.*/
    frac = frac >>14;       /*frac�κ��� sfp�� 9�ڸ��̹Ƿ� �׸�ŭ �̵����ݴϴ�.*/
    sfp x;

    x = x | frac;
    x = x | exp;
    x = x+sign;

    if(over ==1 && b>0) /*���� exp�� special value�̰� ����̸� */
        x = 0x7E00;
    else if(over ==1 & b<0) /*���� exp�� special value�̰� �����̸�*/
        x=0xFE00;








    return x;
}

float sfp2float(sfp input){

    sfp m;
    sfp k = input;
    m = input & 0x7FFF;     /*sign��Ʈ�� ������ ���� �޾��ݴϴ�.*/
    int sign;
    if(k != m)
        sign = 0x80000000;
    else
        sign =0;        /*sign���� ���� ǥ�����ݴϴ�.*/



    int a =0;
    int n=0;
    int x;
    x = input & 0x7E00;     /*x�� exp���� �޾��ݴϴ�.*/
    int y,i;
    y = input & 0x01FF;     /*y�� frac���� �޾��ݴϴ�.*/
    if(x !=0){
        x = x>>9;
        x = x-31+127;
        x = x<<23;      /*x�� 0�� �ƴϸ� bit�� bias���̸�ŭ �ٲ��ݴϴ�.*/
    }
    else
        x=0;
    y = y<<14;      /*frac���� ��Ʈ �� ���̸�ŭ �÷��ݴϴ�.*/
    a = a |x;       /*bitwise����� ���� int�� a�� �� �־��ݴϴ�.*/
    a = a|y;
    a = a+sign;

    if(m == 0x7E00){
        a = 0x7F800000+sign;
    }


    float e;
    memcpy((void*)(&e), (void*)(&a), 32);
    /*a ��Ʈ���� memcpy�� ����� float�� �Ѱ��ݴϴ�.*/








    return e;
}

sfp sfp_add(sfp in1, sfp in2){
    sfp m1;
    sfp k1 = in1;
    m1 = in1 & 0x7FFF;  /*�� input�� sign�� ������ ��Ʈ�� �޾��ݴϴ�.*/
    int sign1;
    if(k1 != m1){       /*�� input�� ��Ʈ���� �޾��ݴϴ�.*/
        sign1 = 0x80000000;
        sign1 = sign1>>16;
    }
    else
        sign1 =0;

    sfp m2;
    sfp k2 = in2;
    m2 = in2 & 0x7FFF;
    int sign2;
    if(k2 != m2){
        sign2 = 0x80000000;
        sign2 = sign2>>16;
    }
    else
        sign2 =0;

    int sign;


    int over1=0;
    int over2=0;
    sfp exp,exp1,exp2;
    exp1 = in1 & 0x7E00;    /*�� input�� exp���� �޾��ݴϴ�.*/
    if(exp1 == 0x7E00)      /*exp�� special�϶��� ������ݴϴ�.*/
        over1 =1;
    exp1 = exp1 >>9;
    exp2 = in2 & 0x7E00;
    if(exp2 == 0x7E00)
        over2=1;
    exp2 = exp2>>9;

    float frac,frac1,frac2;     /*exp�� 0�϶��� 1�� ������ frac�� �ް� 0�� �ƴҶ��� 1�� �߰����ݴϴ�.*/
    frac1 = in1 & 0x01FF;
    frac2 = in2 & 0x01FF;
    if(exp1 != 0)
        frac1 = frac1+0x0200;
    if(exp2 != 0)
        frac2 = frac2+0x0200;

    int i,k;

    int minus=0;

    if(exp1 > exp2){        /*exp �񱳸� �Ͽ� �������� frac�� �ٲ��ݴϴ�.*/
        k = exp1 -exp2;
        for(i=k; i>0; i--)
            frac2 = frac2/2;
        exp = exp1;
        sign = sign1;
    }
    else if(exp1 < exp2){
        k = exp2 -exp1;
        for(i=k; i>0; i--)
            frac1 = frac1/2;
        exp = exp2;
        sign = sign2;
    }
    else{
        exp = exp1;     /*exp���� ������ frac���� �� ū ���� ��ȣ�� �����ݴϴ�.*/
        if(frac1 > frac2)
            sign = sign1;
        else
            sign = sign2;
    }

    if(sign1 == sign2){     /*��ȣ�� ������ frac���� �����ݴϴ�.*/
        frac = frac1 +frac2;
        }
    else{                   /*��ȣ�� �ٸ��� ū ������ ���� ���� ���ݴϴ�.*/
        if(frac1 > frac2){
            frac = frac1 - frac2;
        }
        else if(frac1 < frac2){
            frac = frac2 - frac1;
        }
        else{       /*��ȣ�� �ٸ��� frac�� ������ �������� 0�� �˴ϴ�.*/
            exp =0;
            frac =0;
        }

    }
    while(1){       /*���ؼ� frac�� 2.xxx�� �� ���� �ٿ��ְ� 0.xxx�� �Ǹ� Ű���ݴϴ�.*/
    if(frac >=1024){
        frac = frac/2;
        exp = exp+1;
    }
    else if(frac>=512 && frac <1024){   /*�ݺ� �� 1.xxx�� �Ǹ� 1�� �������ݴϴ�.*/
        frac = frac-512;
        break;
    }
    else if(frac ==0)
        break;
    else{
        frac = frac*2;
        exp = exp-1;
    }
    }





    int m =frac;



    exp = exp<<9;


    m= m| exp;

    sfp x =m;       /*�Ϲ����� ����� exp�� frac���� �޾��ݴϴ�.(0����)*/

    if(over1 ==1 && over2 ==1){     /*inf�� ���� ��츦 �������ݴϴ�.*/
        if(sign1 == sign2)
            x = 0x7E00;
        else
            x= 0x7E00+1;
    }
    else if(over1 ==0 && over2==0)
        x=x;
    else
        x=0x7E00;


    x = x+sign;









    return x;
}

sfp sfp_mul(sfp in1, sfp in2){
    sfp exp,exp1,exp2;      /*add�� ���� ������� exp, frac�� �޽��ϴ�.*/
    int over1=0;
    int over2=0;
    exp1 = in1 & 0x7E00;
    if(exp1 == 0x7E00)
        over1=1;
    exp1 = exp1 >>9;
    exp2 = in2 & 0x7E00;
    if(exp2 == 0x7E00)
        over2=1;
    exp2 = exp2>>9;
    exp = exp1+exp2;
    if(exp !=0)
        exp = exp-31;

    float frac,frac1,frac2;
    frac1 = in1 & 0x01FF;
    frac2 = in2 & 0x01FF;
    if(exp1 !=0)
        frac1 = frac1+0x0200;
    if(exp2 !=0)
        frac2 = frac2+0x0200;
    int i;
    for(i=0; i<9; i++){     /*������ frac�� 1.xxx�� ǥ���ϱ� ���� 2�� 9�� ������ �ݴϴ�.*/
        frac1 = frac1/2;
        frac2 = frac2/2;
    }
    frac = frac1 * frac2;
    if(frac >2){        /*frac�� 2���� ũ�� 2�� ���� �� exp�� 1 �����ݴϴ�.*/
        frac = frac/2;
        exp =exp+1;
    }
    int over;
    if(exp != 63)
        exp = exp<<9;
    else
        over =1;

    for(i=0; i<9; i++)
       frac = frac *2;  /*frac�� 9�� 2�����ݴϴ�. frac�� bitwise�� ������� ���Ͽ� *2�� ǥ��*/
    if(frac !=0)
        frac = frac - 0x0200;   /*frac�� 0�� �ƴϸ� 1�� �����Ͽ��ݴϴ�.*/

    int a=0;
    a = frac;
    a = a | exp;        /*int a���� ���� �־��ݴϴ�.*/

    sfp x;


    sfp m1;
    sfp k1 = in1;
    m1 = in1 & 0x7FFF;      /*������ sign��Ʈ�� ������ݴϴ�.*/
    int sign1;
    if(k1 != m1)
        sign1 = 0x80000000;
    else
        sign1 =0;

    sfp m2;
    sfp k2 = in2;
    m2 = in2 & 0x7FFF;
    int sign2;
    if(k2 != m2)
        sign2 = 0x80000000;
    else
        sign2 =0;

    int sign;
    if(sign1 == sign2)      /*sign���� ������ ��� �ٸ��� �����Դϴ�.*/
        sign =0;
    else
        sign = 0x8000;

    x = a;

    if(in1 ==0 || in2 ==0)
        x=0;                /*�� �� �ϳ��� 0�̸� 0�� ���ɴϴ�.*/

    if(over1 ==1 || over2 ==1){ /*�� �� �ϳ��� inf���� inf�� ������ inf�� (-inf)�� ���ϸ� NAN�� ���ɴϴ�.*/
        if(exp !=0)
            x = 0x7E00;
        else
            x=0x7E00+1; /*0�� special�� ���Ҷ��� NAN */
    }



    x = x+sign;

    return x;
}
