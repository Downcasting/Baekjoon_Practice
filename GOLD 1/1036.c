
// 1036번 - 36진수

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABS(a) (a > '9' ? a - 'A'+10 : a - '0')
#define SBA(b) (b > 9 ? b - 10 + 'A' : b + '0')
#define MAX(a, b) (a>b ? a:b)


int diff[36][55];   // 0~Z까지의 숫자값들 차이 + 0부터 54자리까지(점점 높아짐)

int compare(const void *a, const void *b) {
    int indexA = *((int *)a);
    int indexB = *((int *)b);

    // 크기를 비교하여 정렬 (내림차순)
    for (int i = 54; i >= 0; --i) {
        if (diff[indexA][i] > diff[indexB][i]) {
            return -1; // 내림차순으로 정렬
        } else if (diff[indexA][i] < diff[indexB][i]) {
            return 1;
        }
    }
    return 0; // 두 수가 같음
}
int main(void){
    int index = 1;
    char inputs[50][54]; // 50개의 50문자들(50+NULL=54)
    int final[55];
    int num;             // 문자열 개수
    int var;             // 고를 개수
    int diffWord[36];    // 골라질 문자들 (-1 - 안 골라짐, 1 ~ - 순위)

    scanf("%d",&num);    // 문자열 개수, 고를 개수 스캔

    for(int i=0; i<36; i++){    // 숫자값들 초기화
        diffWord[i] = i;
        for(int j=0; j<55; j++)
            diff[i][j] = 0;
    }
    for(int i=0; i<55; i++)
        final[i] = 0;
    int verify = 0;
    for(int i=0; i<num; i++){
        scanf("%s",inputs[i]);
        while(inputs[i][0] == '0'){
            for(int j=0; j<strlen(inputs[i]); j++)
                inputs[i][j] = inputs[i][j+1];
        }
        if(inputs[i][0] == '\0'){
            inputs[i][0] = '0';
            inputs[i][1] = '\0';
        }
        for(int j=strlen(inputs[i])-1; j >= 0; j--)
            diff[ABS(inputs[i][j])][strlen(inputs[i]) - j - 1] += ABS('Z') - ABS(inputs[i][j]); // 다른 값만큼만
    }
    for(int i=0; i<36; i++){
        for(int j=0; j<52; j++){
            diff[i][j+1] += diff[i][j] / 36;
            diff[i][j] = diff[i][j] % 36;
        }
    }
    scanf("%d",&var);
    qsort(diffWord, 36, sizeof(int), compare);
    for(int i=0; i<var; i++){
        for(int j=0; j<num; j++){
            for(int k=0; k<strlen(inputs[j]); k++){
                if(ABS(inputs[j][k]) == diffWord[i])
                    inputs[j][k] = 'Z';                    
            }
        }
    }
    for(int i=0; i<num; i++){
        for(int j=0; j < strlen(inputs[i]); j++)
            final[j] += ABS(inputs[i][strlen(inputs[i]) - j - 1]); // 이번에는 그냥 더하기
    }
    for(int i = 0; i<54; i++){
        final[i+1] += final[i] / 36;
        final[i] = final[i] % 36;
    }
    // 자릿수 변경 필요
    int start = 0;
    int shallow = 1;
    for(int i=54; i>=0; i--){
        if(final[i] <= 0){
            if(start)
                printf("0");
        }
        else{
            start = 1;
            shallow = 0;
            printf("%c",(char)SBA(final[i]));
        }
    }
    if(shallow)
        printf("0");
    return 0;
}