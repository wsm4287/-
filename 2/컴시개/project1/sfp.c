#include "sfp.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

sfp int2sfp(int input){
    sfp z = 0x0000;     /*베이스로 sfp값을 하나 지정해줍니다.*/
    int k =0;
    int i =0;
    int b =1;
    int x;
    if(input < 0){
        z = z|0x8000;
        x= -input;}     /*음수이면 -를 붙여 양수값만 받아줍니다.*/
    else if(input >0)
        x= input;
    else
        x =0;
    int y =x;
    while(y > 1){
        y= y/2;
        k++;
    }                   /*2롤 최대한 나누어 2의 진수값을 구해줍니다.*/
    int exp = k+31;     /*bias값을 더해줍니다.*/
    if(x ==0)
        exp =0;
    int a = x;
    for(i=0; i<k; i++)
        b = b*2;
    a = a-b;    /*frac에서 1을 제거해 줍니다.*/
    if(exp >0 && exp < 63){ /*exp값이 normal이면 평소처럼 계산해줍니다.*/
        exp = exp <<9;
        z = z + exp;
        if(k<=8){
            for(i=0; i<9-k; i++)
                a = a<<1;}  /*k가 작으면 frac를 가장 안쪽까지 당겨줍니다.(9번째 비트부터)*/
        else{
            for(i=0; i<k-9; i++)
                a = a>>1;}  /*k가 크면 frac를 가장 바깥쪽으로 보내줍니다.(9번째비트부터)*/
    z = z + a;}
/*z에 frac값을 더해줍니다. 애초에 exp가 0이면 정수에서는 frac도 0이므로 신경쓰지 않았습니다.*/


    return z;



}



int sfp2int(sfp input){

    sfp m;
    sfp k = input;
    m = input & 0x7FFF;     /*m에 sign을 제외한 input값을 받습니다.*/

    int a;
    int n=0;
    int x;
    x = input >>9;      /*exp값을 받습니다.*/
    int y,i;
    y = input & 0x01FF;     /*frac값을 받습니다.*/
    if(x>=31){
        for(i=0; i<x-31; i++)
            n++;        /*exp가 31보다크면 2^n을 구하기위해 2로 x-31만큼 나누어줍니다.*/
    }
    else
        a=0;        /*처음에 int값을 받아서 exp가 31보다 작으면 0입니다.*/
    if(n!=0)
        y = y+0x0200;   /*exp가 0이 아니면 frac 맨 앞에 1을 더해줍니다.*/
    else
        y=y;
    if(n<9){
        y=y>>(9-n);
    }
    else
        y = y<<(n-9);       /*frac를 숫자에 맞춰 비트 이동을 해줍니다.*/


    if(m == k)
        a = y;      /*양수이면 그대로 a에 받아줍니다.*/
    else
        a= -y;      /*음수이면 마지막에 -를 붙여줍니다.*/

    return a;
}

sfp float2sfp(float input){
    float b;
    b= input;   /*input값을 새로 받아줍니다.*/
    int over=0; /*값을 초과할때를 위해 over를 만들어주웠습니다*/

    int a = 0;
    sfp sign;
    if(b<0)
        sign = 0x8000;
    else
        sign =0;    /*sign비트를 따로 받아줍니다.*/
    memcpy((void*)(&a),(void*)(&b),sizeof(a));  /*float값을 bitwise해주기위해 memcpy를 사용합니다.*/
    int exp;
    exp = a & 0x7F800000;
    if(exp <=0x4F800000 && exp >0x30000000){    /*exp가 범위내면 bias와 bit 차이를 고려해줍니다.*/
    exp = exp >>23;
    exp = exp-127+31;
    exp = exp <<9;
    }
    else if(exp > 0x4F800000)       /*표현 범위보다 크면 over로 해줍니다.*/
        over=1;
    else                    /*표현범위보다 작으면 0으로 바꿔줍니다.*/
        exp =0;

    int frac = a & 0x007FFFFF;  /*frac부분을 꺼내줍니다.*/
    frac = frac >>14;       /*frac부분을 sfp가 9자리이므로 그만큼 이동해줍니다.*/
    sfp x;

    x = x | frac;
    x = x | exp;
    x = x+sign;

    if(over ==1 && b>0) /*만약 exp가 special value이고 양수이면 */
        x = 0x7E00;
    else if(over ==1 & b<0) /*만약 exp가 special value이고 음수이면*/
        x=0xFE00;








    return x;
}

float sfp2float(sfp input){

    sfp m;
    sfp k = input;
    m = input & 0x7FFF;     /*sign비트를 제외한 값을 받아줍니다.*/
    int sign;
    if(k != m)
        sign = 0x80000000;
    else
        sign =0;        /*sign값을 따로 표현해줍니다.*/



    int a =0;
    int n=0;
    int x;
    x = input & 0x7E00;     /*x에 exp값을 받아줍니다.*/
    int y,i;
    y = input & 0x01FF;     /*y에 frac값을 받아줍니다.*/
    if(x !=0){
        x = x>>9;
        x = x-31+127;
        x = x<<23;      /*x가 0이 아니면 bit와 bias차이만큼 바꿔줍니다.*/
    }
    else
        x=0;
    y = y<<14;      /*frac값을 비트 수 차이만큼 올려줍니다.*/
    a = a |x;       /*bitwise계산을 위해 int인 a에 다 넣어줍니다.*/
    a = a|y;
    a = a+sign;

    if(m == 0x7E00){
        a = 0x7F800000+sign;
    }


    float e;
    memcpy((void*)(&e), (void*)(&a), 32);
    /*a 비트값을 memcpy를 사용해 float로 넘겨줍니다.*/








    return e;
}

sfp sfp_add(sfp in1, sfp in2){
    sfp m1;
    sfp k1 = in1;
    m1 = in1 & 0x7FFF;  /*각 input의 sign을 제외한 비트를 받아줍니다.*/
    int sign1;
    if(k1 != m1){       /*각 input의 비트값을 받아줍니다.*/
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
    exp1 = in1 & 0x7E00;    /*각 input의 exp값을 받아줍니다.*/
    if(exp1 == 0x7E00)      /*exp가 special일때를 고려해줍니다.*/
        over1 =1;
    exp1 = exp1 >>9;
    exp2 = in2 & 0x7E00;
    if(exp2 == 0x7E00)
        over2=1;
    exp2 = exp2>>9;

    float frac,frac1,frac2;     /*exp가 0일때는 1을 제외한 frac를 받고 0이 아닐때는 1을 추가해줍니다.*/
    frac1 = in1 & 0x01FF;
    frac2 = in2 & 0x01FF;
    if(exp1 != 0)
        frac1 = frac1+0x0200;
    if(exp2 != 0)
        frac2 = frac2+0x0200;

    int i,k;

    int minus=0;

    if(exp1 > exp2){        /*exp 비교를 하여 작은값의 frac를 바꿔줍니다.*/
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
        exp = exp1;     /*exp값이 같으면 frac값이 더 큰 것의 부호를 따라줍니다.*/
        if(frac1 > frac2)
            sign = sign1;
        else
            sign = sign2;
    }

    if(sign1 == sign2){     /*부호가 같으면 frac값을 더해줍니다.*/
        frac = frac1 +frac2;
        }
    else{                   /*부호가 다르면 큰 값에서 작은 것을 빼줍니다.*/
        if(frac1 > frac2){
            frac = frac1 - frac2;
        }
        else if(frac1 < frac2){
            frac = frac2 - frac1;
        }
        else{       /*부호가 다르고 frac가 갑으면 더했을때 0이 됩니다.*/
            exp =0;
            frac =0;
        }

    }
    while(1){       /*더해서 frac가 2.xxx가 될 때는 줄여주고 0.xxx가 되면 키워줍니다.*/
    if(frac >=1024){
        frac = frac/2;
        exp = exp+1;
    }
    else if(frac>=512 && frac <1024){   /*반복 후 1.xxx가 되면 1을 제거해줍니다.*/
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

    sfp x =m;       /*일반적인 경우의 exp와 frac값을 받아줍니다.(0포함)*/

    if(over1 ==1 && over2 ==1){     /*inf가 포함 경우를 생각해줍니다.*/
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
    sfp exp,exp1,exp2;      /*add와 같은 방법으로 exp, frac을 받습니다.*/
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
    for(i=0; i<9; i++){     /*각각의 frac를 1.xxx로 표현하기 위해 2로 9번 나누어 줍니다.*/
        frac1 = frac1/2;
        frac2 = frac2/2;
    }
    frac = frac1 * frac2;
    if(frac >2){        /*frac가 2보다 크면 2를 나눈 후 exp를 1 더해줍니다.*/
        frac = frac/2;
        exp =exp+1;
    }
    int over;
    if(exp != 63)
        exp = exp<<9;
    else
        over =1;

    for(i=0; i<9; i++)
       frac = frac *2;  /*frac를 9번 2곱해줍니다. frac는 bitwise를 사용하지 못하여 *2로 표현*/
    if(frac !=0)
        frac = frac - 0x0200;   /*frac가 0이 아니면 1을 제거하여줍니다.*/

    int a=0;
    a = frac;
    a = a | exp;        /*int a값에 값을 넣어줍니다.*/

    sfp x;


    sfp m1;
    sfp k1 = in1;
    m1 = in1 & 0x7FFF;      /*각각의 sign비트를 만들어줍니다.*/
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
    if(sign1 == sign2)      /*sign값이 같으면 양수 다르면 음수입니다.*/
        sign =0;
    else
        sign = 0x8000;

    x = a;

    if(in1 ==0 || in2 ==0)
        x=0;                /*둘 중 하나가 0이면 0이 나옵니다.*/

    if(over1 ==1 || over2 ==1){ /*둘 중 하나면 inf여도 inf가 나오고 inf와 (-inf)를 곱하면 NAN이 나옵니다.*/
        if(exp !=0)
            x = 0x7E00;
        else
            x=0x7E00+1; /*0과 special를 곱할때는 NAN */
    }



    x = x+sign;

    return x;
}
