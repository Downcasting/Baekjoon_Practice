
// 10942번 - 팰린드롬?

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int num;
int* arr;
int qNum;
int* qArr;
int* dp;
/* Function */
int question(int a, int b);

/* Main */
int main(void){

    scanf("%d",&num);
    arr = (int*)malloc(num*sizeof(int));
    dp = (int*)malloc(2*num*sizeof(int));

    f(i,num)
        scanf("%d",&arr[i]);
    f(i,2*num)
        dp[i] = 0;
    
    scanf("%d",&qNum);
    qArr = (int*)malloc(qNum*sizeof(int));

    int a,b;
    f(i, qNum){
        scanf("%d %d",&a,&b);
        qArr[i] = question(a-1,b-1);
    }

    f(i,qNum)
        printf("%d\n",qArr[i]);
    
    return 0;
}

/* Functions */
int question(int a, int b){
    if(b - a <= 0)                 // 같을 수 밖에 없음
        return 1;

    if(dp[a+b] >= b-a)              // 이미 정의가 되어 있음
        return 1;
    if(arr[a] != arr[b])            // 애초에 이게 양 끝이 다름 -> 0
        return 0;
    else{                           // 이게 양 끝이 같다면...
        if(question(a+1,b-1)){      // 1. 아래쪽도 같으면
            dp[a+b] = b-a;              // dp 업데이트하기
            return 1;                   // 옳다고 올려보내기
        }
        else                        // 2. 아래쪽은 다르다 -> 0
            return 0;
    }
    return -1;
}