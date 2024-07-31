
// 1086번 - 박성원

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

#define LENGTH 50
#define DIGITS 100

/* Struct */

/* Global Var */
int** dp; // 50(최대 50 자리) * 10(0~9)
int divisor; // 유일한 나누기 수

int* divisors; // 각 배열의 정리된 나머지
int* lengths;  // 각 배열의 길이

int N;

/* Function Declarations */

/* Main */
int main(void){
    dp = (int**)malloc(LENGTH * sizeof(int*));
    f(i,LENGTH){
        dp[i] = (int*)malloc(DIGITS * sizeof(int));
        f(j,DIGITS)
            dp[i][j] = -1;
    }
    char arr[51]; // 입력받을 문자열
    scanf("%d",&N);
    divisors = (int*)malloc(N*sizeof(int));
    lengths = (int*)malloc(N*sizeof(int));
    f(i,N){
        scanf("%s",arr);
        int dig = strlen(arr)-1;
        for(int j=0; arr[j] != 0; j++){
            divisors[j] += getRemainder(dig, arr[j] - '0');
            dig--;
        }
    }

    return 0;
}

/* Functions */
int getRemainder(int length, int digit){
    if(dp[length][digit] != -1)
        return dp[length][digit];
    if(length == 0)
        return digit;
    return dp[length][digit] = getRemainder(length-1, (digit*10) % divisor);
}