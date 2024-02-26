
// 1443번 - 망가진 계산기

#include <stdio.h>
#include <math.h>

void calc(int* max, int digit, int untilNow, int level, int start); // 가장 컸던 가능한 수, 지금까지의 digit, 지금까지의 곱셈값, 남은 곱셈 개수, 시작하는 값

int main(void){
    int D, P;
    int max = 0;
    int digit = 1;
    scanf("%d %d", &D, &P);
    for(int i=0; i<D; i++)
        digit *= 10;
    if((int)pow(2, P) >= digit)
        printf("-1");
    else{
        calc(&max, digit, 1, P, 2);
        printf("%d",max);
    }
    //system("pause");
    return 0;
}
void calc(int* max, int digit, int untilNow, int level, int start){
    if(level == 0){
        if(*max < untilNow)
            *max = untilNow;
    }
    for(int i=start; i<10; i++){
        if(untilNow * i < digit && (untilNow * i) / i == untilNow)
            calc(max, digit, untilNow*i, level-1, i);
        else
            break;
    }
}
