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
    int size;
    scanf("%d",&size);

    int board[size][size];
    int dp[size][size];

    f(i,size){
        f(j,size){
            scanf("%d",&board[i][j]);
            dp[i][j] = 0;
        }
    }
    int count = 0;
    printf("%d",count);
    return 0;
}
/* Functions */