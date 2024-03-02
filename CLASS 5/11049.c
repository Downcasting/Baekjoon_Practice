
// 11049번 - 행렬 곱셈 순서

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int** dp;
int* dim;

/* Function */
int recursive(int start, int end);

/* Main */
int main(void){
    int num;
    scanf("%d",&num);
    dim = (int*)malloc((num+1)*sizeof(int));
    f(i,num)
        scanf("%d %d",&dim[i], &dim[i+1]);
    
    dp = (int**)malloc((num+1)*sizeof(int*));
    f(i,num+1){
        dp[i] = (int*)malloc((num+1)*sizeof(int));
        f(j,num+1)
            dp[i][j] = 0;
    }
    printf("%d",recursive(0,num-1));
    return 0;
}

/* Functions */
int recursive(int start, int end){
    if(start == end)
        return 0;
    if(dp[start][end] != 0)
        return dp[start][end];
    int min = __INT_MAX__;
    for(int i=start; i<end; i++){
        min = MIN(min,recursive(start,i)+recursive(i+1,end)+dim[start]*dim[i+1]*dim[end+1]);
    }
    return dp[start][end] = min;
}