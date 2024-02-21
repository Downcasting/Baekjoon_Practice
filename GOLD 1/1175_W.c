/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Global Variables */
int** map;
int** dp;
int** move;
int N, M;

/* Function declaration */

/* Main */
int main(void){
    scanf("%d %d",&N, &M);
    char input[M];
    map = (int**)malloc(N*sizeof(int*));
    dp = (int**)malloc(N*sizeof(int*));
    move = (int**)malloc(N*sizeof(int*));
    f(i,N){
        map[i] = (int*)malloc(M*sizeof(int));
        dp[i] = (int*)malloc(M*sizeof(int));
        move[i] = (int*)malloc(M*sizeof(int));
        scanf("%s",input);
        f(j,M){
            switch(input[j]){
                case '#': 
                    map[i][j] = -1;
                    break;
                case '.':
                    map[i][j] = 0;
                    break;
                case 'C':
                    map[i][j] = 100;
                    break;
                case 'S':
                    map[i][j] = 1;
                    break;
                default:
            }
        }
    }
    recursive();
    return 0;
}

/* Functions */
int recursive(){
    return 0;
}