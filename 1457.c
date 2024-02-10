#include <stdio.h>
#include <math.h>

int main(void){
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);

    int multI;
    int total = 0; // 총 멋진 수의 개수

    for(int i=2; i<=(A+B); i++){
        total += ((A+B) / i) - ((A-1) / i); // A ~ A+B 사이의 i의 배수의 개수
        multI = (int)pow(i,N);
        total -= ((A+B) / multI) - ((A-1) / multI); // A ~ A+B 사이의 i의 N제곱수의 배수의 개수만큼 빼기
        if(i >= A && i <= (A+B))
            total--;
    }
    printf("%d",total);
    return 0;
}