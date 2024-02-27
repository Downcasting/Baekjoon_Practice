
// 2098번 - 외판원 순회 <작업 중>

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
int** map;
int num;

/* Function */
int minimum(int binary, int current);

/* Main */
int main(void){

    scanf("%d",&num);

    dp = (int**)malloc((1<<num)*sizeof(int*));
    map = (int**)malloc((num)*sizeof(int*));

    f(i,1<<num){
        dp[i] = (int*)malloc((num)*sizeof(int));
        f(j,num){
            dp[i][j] = 0;
            //printf("%d %d confirmed\n",i,j);
        }
    }
    f(i,num){
        map[i] = (int*)malloc((num)*sizeof(int));
        f(j,num)
            scanf("%d",&map[i][j]);
    }
    int min = 2147483647;
    min = minimum(1,0);
    printf("%d",min);
    return 0;
}

/* Functions */
int minimum(int binary, int current){
    if(dp[binary][current] != 0)
        return dp[binary][current];
    if(binary == (1 << num) - 1){
        if(map[current][0] != 0)
            return map[current][0]; // 도달 가능
        else
            return 1000001;        // 도달 불가능
    }

    int min = 16000001;
    f(i,num){
        if(((binary & (1 << i)) == 0) && map[current][i] != 0){
            //printf("%x %d, destination to %d - %d\n",binary,current, i, map[current][i]);
            min = MIN(minimum(binary | (1 << i), i) + map[current][i], min);
        }
    }
    //printf("%x %d, Mimimum was %d\n",binary,current, min);
    return dp[binary][current] = min;
}