#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a,b) a>b?a:b

int recursive(int index, int money, int current);
// index - N명의 소유했던 로그 : 11001 -> O[4]/O[3]/X[2]/X[1]/O[0] <역순>
// money - 지금까지 올라온 가격
// priceArr - price 행렬
// N - 총 사람 수
// current - 지금 팔려는 사람

int N;

int** price; // 가격
// N - 파는 사람이...
// N - 사는 사람이...

int*** memoization; // 사람 수
// N - 파는 사람이...
// 10 - 지금까지의 가격이...
// 2^15 - 

int main(void){
    scanf("%d",&N);
    memoization = (int***)malloc(N*sizeof(int**));
    price = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++){
        price[i] = (int*)malloc(N * sizeof(int));
        memoization[i] = (int*)malloc(10 * sizeof(int));
    }
    char input[N+1];
    for(int i=0; i<N; i++){
        scanf("%s",input);
        for(int j=0; j<N; j++)
            price[i][j] = input[j] - '0';
    }
    int max = recursive(1, 0, 0);
    printf("%d", max);

    for (int i = 0; i < N; i++) {
        free(price[i]);
    }
    free(price);
    return 0;
}
int recursive(int index, int money, int current){
    int max=0;
    for(int i=0; i<N; i++){
        if(!(index & 1<<i) && price[current][i] >= money)
            max = MAX(max, recursive(index | 1<<i, price[current][i], i));
    }
    return max+1;
}