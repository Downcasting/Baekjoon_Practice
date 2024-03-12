
// 11689번 - GCD(n,k) = 1

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

/* Function Declarations */

/* Main */
int main(void){
    long long n;
    scanf("%lld",&n);
    int sqrN = (int)sqrt(n);
    int divisor[sqrN];
    int num=0;
    long long temp = n;
    if(temp % 2 == 0){
        divisor[num++] = 2;
        while(temp % 2 == 0){
            temp /= 2;
        }
    }
    for(int i=3; i <= sqrN; i += 2){
        if(temp % i == 0){
            divisor[num++] = i;
            while(temp % i == 0){
                temp /= i;
            }
        }
        if(temp == 1)
            break;
    }
    divisor[num++] = temp;
    temp = n;
    f(i,num){
        temp -= n/divisor[i];
    }

    printf("%d",temp);
    return 0;
}

/* Functions */