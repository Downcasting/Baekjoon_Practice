
// 2342번 - Dance Dance Revolution

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int* input;
int** dp;
int size;
/* Function */
int recursive(int foot, int index);
int unify(int left, int right);
int power(int foot, int loc);

/* Main */
int main(void){
    input = (int*)malloc(100001*sizeof(int));
    size = 0;
    int scan = -1;
    while(scan != 0){
        scanf("%d",&scan);
        input[size++] = scan;
    }
    dp = (int**)malloc(64*sizeof(int*));
    f(i,64){
        dp[i] = (int*)malloc(size*sizeof(int));
        f(j,size)
            dp[i][j] = 0;
    }
    int min = recursive(0,0);
    printf("%d",min);
    return 0;
}

/* Functions */
int recursive(int foot, int index){
    if(dp[foot][index] != 0)
        return dp[foot][index];
    if(input[index] == 0)
        return 0;
    int min = 400004;
    int left = foot / 8;
    int right = foot % 8;

    int leftWeight = power(left, input[index]);
    int rightWeight = power(right, input[index]);

    int lefty = 999999;
    int righty = 999999;

    // 왼발
    if(input[index] != right){
        lefty = leftWeight + recursive(unify(input[index], right), index + 1);
        min = MIN(min, lefty);
    }
    
    // 오른발
    if(input[index] != left){
        righty = rightWeight + recursive(unify(left, input[index]), index + 1);
        min = MIN(min, righty);
    }
    //printf("Foot [%d, %d], to %d MIN: %d INDEX: %d Choosed %d\n",left,right,input[index],min,index, lefty>righty);
    return dp[foot][index] = min;
}
int unify(int left, int right){
    return left*8+right;
}
int power(int foot, int dest){
    switch(foot){
        case 0:                     // 기본 시작 - 발이 0
            return 2;
        default:
            if(dest == foot)     // 밟을 곳이 같음
                return 1;
            else if(dest + foot == 4 || dest + foot == 6)    // 밟을 곳이 정반대 4에서 2를!!
                return 4;
            else
                return 3;
    }
    printf("WTF???\n");
    return -1;
}