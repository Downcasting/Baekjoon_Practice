
// 1509번 - 계단 수

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)
#define parse(digit, lo, hi) digit*100 + lo*10 + hi

#define QUOTIENT 1000000000

/* Struct */

/* Global Var */
int** dp;

/* Function */
long long getStair(int N, int lastDigit, int low, int high);

/* Main */
int main(void){
    int N;
    long long sum = 0;
    scanf("%d", &N);;
    dp = (int**)malloc(N * sizeof(int*));
    f(i,N){
        dp[i] = (int*)malloc(1000*sizeof(int));
        f(j,1000)
            dp[i][j] = 0;
    }
    for(int i=1; i<10; i++){
        if(getStair(N-1, i, i, i) > 0)
            sum += getStair(N-1, i, i, i);
    }
    printf("%lld",sum%QUOTIENT);
    return 0;
}
/* Functions */
long long getStair(int N, int lastDigit, int low, int high){
    if(N == 0){
        if(low == 0 && high == 9)
            return 1;
        else
            return -1;
    }
    if(dp[N][parse(lastDigit, low, high)])
        return dp[N][parse(lastDigit, low, high)];
    long long sum = 0;
    if(lastDigit != 0){
        if(getStair(N-1, lastDigit-1, MIN(lastDigit-1, low), high) > 0)
            sum += getStair(N-1, lastDigit-1, MIN(lastDigit-1, low), high);
    }
    if(lastDigit != 9){
        if(getStair(N-1, lastDigit+1, low, MAX(lastDigit+1, high)) > 0)
           sum += getStair(N-1, lastDigit+1, low, MAX(lastDigit+1, high));
    }
    return dp[N][parse(lastDigit, low, high)] = sum % QUOTIENT;
}
