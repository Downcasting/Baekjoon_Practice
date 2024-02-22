/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(a,b) for(int a=0; a<b; a++)

/* Struct */
typedef struct Jewel{
    int weight;
    int value;
} Jewel;

/* Global Var */

/* Function */
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
/* Main */
int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    Jewel* jewel[N];
    int bag[K];

    int a, b;
    f(i,N){
        scanf("%d %d",&a, &b);
        jewel[i] = makeJewel(a,b);
    }
    f(i,K)
        scanf("%d",&bag[i]);
    qsort(bag,K,sizeof(int),compare);
    f(i,K){ // 모든 가방에 대해서...
        f(j,bag[i]){ // 세로로 한 번 돌리고...
            f(k, K){ // K 번째 가방까지 돌린다
                if(!k)
                    dp[j][k] = 0;
            }
        }
    }
    
    return 0;
}

/* Functions */
Jewel* makeJewel(int weight, int value){
    Jewel* newJewel = (Jewel*)malloc(sizeof(Jewel));
    newJewel->value = value;
    newJewel->weight = weight;
    return newJewel;
}