
// 2166번 - 다각형의 면적

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */

/* Function */

/* Main */
int main(void){
    int num;
    scanf("%d",&num);

    double x[num];
    double y[num];

    f(i,num)
        scanf("%lf %lf",&x[i], &y[i]);

    double plus = 0.0f;
    double minus = 0.0f;
    f(i,num-1){
        plus += x[i]*y[i+1];
        minus += x[i+1]*y[i];
        //printf("%.3f %.3f\n",x[i]*y[i+1], x[i+1]*y[i]);
    }
    plus += x[num-1]*y[0];
    minus += x[0]*y[num-1];

    double sum = 0.5*(plus-minus);
    if(sum < 0)
        sum *= -1;
    printf("%.1f",sum);
    return 0;
}

/* Functions */