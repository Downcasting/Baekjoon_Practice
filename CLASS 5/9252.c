
// 9252번 - LCS 2

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
char* input1;
char* input2;
int length1;
int length2;
int** dp;
/* Function */
int recursive(int a, int b);

/* Main */
int main(void){
    input1 = (char*)malloc(sizeof(char)*1001);
    input2 = (char*)malloc(sizeof(char)*1001);
    scanf("%s %s",input1, input2);
    length1 = strlen(input1);
    length2 = strlen(input2);
    dp = (int**)malloc(length1*sizeof(int*));
    f(i,length1){
        dp[i] = (int*)malloc(length2*sizeof(int));
        f(j,length2)
            dp[i][j] = -1;
    }
    int big = recursive(length1-1,length2-1);
    printf("%d",big);
    return 0;
}
/* Functions */
int recursive(int a, int b){
    if(a == 0 || b == 0)
        return dp[a][b] = 0;
    if(input1[a] == input2[b])
        return dp[a][b] = recursive(a-1,b-1)+1;
    if(dp[a][b] != -1)
        return dp[a][b];
    return dp[a][b] = MAX(recursive(a-1,b),recursive(a,b-1));
}