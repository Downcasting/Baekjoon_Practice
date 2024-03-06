
// 15824번 - 너 봄에는 캡사이신이 맛있단다

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

/* Function Declarations */
int static compare (const void* first, const void* second);

/* Main */
int main(void){
    scanf("%d",&num);
    arr = (int*)malloc(num*sizeof(int));
    qsort(arr,num,sizeof(int),compare);
    return 0;
}

/* Functions */
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}