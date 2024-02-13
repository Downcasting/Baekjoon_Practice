#include <stdio.h>

#define ABS(a) (a > '9' ? a - 'A'+10 : a - '0')
#define MAX(a, b) (a>b ? a:b)

int main(void){
    char inputs[50][51]; // 50개의 50문자들(50+NULL=51)
    char diff[36][52];   // 0~Z까지의 숫자값들 차이
    int num;             // 문자열 개수
    int var;             // 고를 개수
    int diffWord[36];    // 골라질 문자들 (1 - 골라짐, 0 - 안 골라짐)

    scanf("%d %d",&num, &var);    // 문자열 개수, 고를 개수 스캔

    for(int i=0; i<36; i++){    // 숫자값들 초기화
        diffWord[i] = 0;
        for(int j=0; j<52; j++)
            diff[i][j] = 0;
    }
    for(int i=0; i<num; i++){
        scanf("%s",inputs[i]);
        for(int j=0; j < strlen(inputs[i]); j++){
            diff[ABS(inputs[i][j])][strlen(inputs[i]) - j - 1] += ABS('Z') - ABS(inputs[i][j]);
            for(int k=j; diff[ABS(inputs[i][k])][k] >= 50; k++){
                diff[ABS(inputs[i][j])][k] -= 50;
                diff[ABS(inputs[i][j])][k+1] += 1;
            }
        }
    }
    for(int i=51; i>= 0; i++){
        int max = 0;
        int level = 1;
        for(int j=0; j<36; j++)
            max = MAX(max, diff[j][i]);
        if(!max)
            continue;
        for(int j=0; j<36; j++){

        }
    }
    return 0;
}