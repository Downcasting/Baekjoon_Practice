/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int** dp;
char input[2500];
/* Function */
int recursive(int start, int end);
int isPal(int start, int end);
/* Main */
int main(void){
    scanf("%s",input);
    int length = strlen(input);
    dp = (int**) malloc(length*sizeof(int*));
    f(i,length){
        dp[i] = (int*) malloc(length*sizeof(int));
        for(int j = i; j < length; j++)
            dp[i][j] = 0;
    }
    long long totalWay = recursive(0,length-1);
    printf("%lld",totalWay);
    return 0;
}

/* Functions */
int recursive(int start, int end){
    if(end == start){
        return 1;
    }
    if(dp[start][end])
        return dp[start][end];
    if(isPal(start, end)){
        return dp[start][end] = 1;
    }
    int min = end-start+1;
    for(int i=0; i < end-start; i++){
        if(isPal(start, start+i)){
            min = MIN(min,recursive(start+i+1,end));
        }
    }
    return dp[start][end] = min + 1;
}
int isPal(int start, int end){
    for(int i = 0; i < (end - start + 1)/2; i++){
        if(input[start+i] != input[end-i])
            return 0;
    }
    return 1;
}