
// 1806번 - 부분합

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */

/* Function Declarations */

/* Main */
int main(void){
    int num, sum;
    scanf("%d %d",&num, &sum);
    int arr[num];
    int sumArr[num];
    int sumInput = 0;

    f(i,num){
        scanf("%d",&arr[i]);
        sumInput += arr[i];
        sumArr[i] = sumInput;
    }

    int left = num-1;
    int right = num-1;

    int shortest = 100001;

    while(left >= -1 && right >= 0){
        int lefty;
        if(left == -1)
            lefty = 0;
        else
            lefty = sumArr[left];
        if(sumArr[right] - lefty < sum || right <= left)
            left--;
        else{
            shortest = MIN(shortest, right - left);
            right--;
        }
    }
    if(shortest > 100000)
        shortest = 0;
    printf("%d",shortest);

    return 0;
}

/* Functions */