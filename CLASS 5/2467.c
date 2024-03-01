
// 2467번 - 용액

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */

/* Function */

/* Main */
int main(void){
    int num;
    scanf("%d",&num);

    int potion[num];

    f(i,num)
        scanf("%d",&potion[i]);
    int start = 0;
    int end = num-1;
    int min = 2000000001;
    int minA, minB;
    while(start < end){
        if(abs(potion[start] + potion[end]) < min){
            min = abs(potion[end] + potion[start]);
            minA = potion[start];
            minB = potion[end];
        }
        if(abs(potion[start+1] + potion[end]) > abs(potion[start] + potion[end-1]))
            end--;
        else
            start++;
    }
    printf("%d %d",minA, minB);

    return 0;
}

/* Functions */