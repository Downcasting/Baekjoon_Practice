
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
int aNum;
int* arr;
int qNum;
int* qArr;
/* Function */

/* Main */
int main(void){

    scanf("%d",&aNum);
    arr = (int*)malloc(aNum*sizeof(int));

    f(i,aNum)
        scanf("%d",&arr[i]);
    
    scanf("%d",&qNum);
    qArr = (int*)malloc(qNum*sizeof(int));

    int a,b;
    f(i, qNum){
        scanf("%d %d",&a,&b);
        qArr[i] = question(a,b);
    }

    f(i,qNum)
        printf("%d\n",qArr[i]);
    
    return 0;
}

/* Functions */
int question(int a, int b){
    return 1;
}