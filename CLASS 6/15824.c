
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
long long* arr;

/* Function Declarations */
int static compare (const void* first, const void* second);

/* Main */
int main(void){
    scanf("%d",&num);
    arr = (long long*)malloc(num*sizeof(long long));
    f(i,num)
        scanf("%lld",&arr[i]);
    
    qsort(arr,num,sizeof(long long),compare);

    long long pow2[num];
    pow2[0] = 1;
    for(int i=1; i<num; i++){
        pow2[i] = pow2[i-1] << 1;
        if(pow2[i] >= 1000000007)
            pow2[i] %= 1000000007LL;
    }
    long long total = 0;
    f(i,num){
        total += (pow2[i] - pow2[num-(i+1)])*arr[i];
    }
    total %= 1000000007LL;
    printf("%lld",total);

    return 0;
}

/* Functions */
int static compare (const void* first, const void* second)
{
    if (*(long long*)first > *(long long*)second)
        return 1;
    else if (*(long long*)first < *(long long*)second)
        return -1;
    else
        return 0;
}