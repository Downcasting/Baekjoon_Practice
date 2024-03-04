
// 2239번 - 스도쿠

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int** field;
int** answer;
int*** possible;
/* Function */
int recursive(int index);

/* Main */
int main(void){
    field = (int**)malloc(9*sizeof(int*));
    answer = (int**)malloc(9*sizeof(int*));
    possible = (int***)malloc(9*sizeof(int**));

    char input[11];

    f(i,9){
        field[i] = (int*)malloc(9*sizeof(int));
        answer[i] = (int*)malloc(9*sizeof(int));
        possible[i] = (int**)malloc(9*sizeof(int*));
        scanf("%s",input);
        f(j,9){
            field[i][j] = input[j] - '0';
            answer[i][j] = input[j] - '0';
            possible[i][j] = (int*)malloc(10*sizeof(int));
        }
    }
    recursive(0);
    f(i,9){
        f(j,9)
            printf("%d",answer[i][j]);
        printf("\n");
    }
    return 0;
}

/* Functions */
int recursive(int index){
    if(index >= 81)
        return 1;
    int row = index/9;
    int col = index%9;

    if(field[row][col] != 0)
        return recursive(index+1);

    answer[row][col] = 0;
    f(k,10)
        possible[row][col][k] = 1; // 일단 모두 가능하다고 가정
    f(k,9){
        possible[row][col][answer[row][k]] = 0;
        possible[row][col][answer[k][col]] = 0;
        possible[row][col][answer[(row/3)*3 + k/3][(col/3)*3 + k%3]] = 0;
    }
    for(int i=1; i<=9; i++){
        if(possible[row][col][i] == 0)
            continue;
        answer[row][col] = i;
        if(recursive(index+1) == 1)
            return 1;
    }
    answer[row][col] = 0;
    return 0;
}