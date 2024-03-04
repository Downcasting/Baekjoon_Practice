
// 9252번 - LCS 2

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
char* input1;
char* input2;
int length1;
int length2;
int** dp;
int** way;
/* Function */
void recursive(int a, int b);
void print(int a, int b);

/* Main */
int main(void){
    input1 = (char*)malloc(sizeof(char)*1001);
    input2 = (char*)malloc(sizeof(char)*1001);
    scanf("%s %s",input1, input2);
    length1 = strlen(input1);
    length2 = strlen(input2);
    dp = (int**)malloc((length1)*sizeof(int*));
    way = (int**)malloc((length1)*sizeof(int*));
    f(i,length1){
        dp[i] = (int*)malloc((length2)*sizeof(int));
        way[i] = (int*)malloc((length2)*sizeof(int));
        f(j,length2){
            dp[i][j] = 0;
            way[i][j] = 0;
        }
    }
    f(i,length1){
        f(j,length2)
            recursive(i,j);
    }
    printf("%d\n",dp[length1-1][length2-1]);
    print(length1-1, length2-1);
    return 0;
}
/* Functions */
void recursive(int a, int b){
    if(input1[a] == input2[b]){
        way[a][b] = 1;
        if(a == 0 || b == 0)
            dp[a][b] = 1;
        else
            dp[a][b] = dp[a-1][b-1]+1;
        return;
    }

    int up = (a == 0 ? 0 : dp[a-1][b]);
    int left = (b == 0 ? 0 : dp[a][b-1]);

    if(up > left){
        way[a][b] = 2;
        dp[a][b] = up;
    }
    else{
        way[a][b] = 3;
        dp[a][b] = left;
    }
    return;
}
void print(int a, int b){
    if(a < 0 || b < 0)
        return;
    switch(way[a][b]){
        case 0:
            return;
        case 1:
            print(a-1,b-1);
            printf("%c",input1[a]);
            return;
        case 2:
            print(a-1,b);
            return;
        case 3:
            print(a,b-1);
            return;
        default:
            break;
    }
    return;
}