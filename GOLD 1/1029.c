#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) a>b?a:b

int recursive(int index, int money, int** priceArr, int N, int current);
// index - N명의 소유했던 로그 : 11001 -> O[4]/O[3]/X[2]/X[1]/O[0] <역순>
// money - 지금까지 올라온 가격
// priceArr - price 행렬
// N - 총 사람 수
// current - 지금 팔려는 사람

int main(void){
    int N;
    scanf("%d",&N);
    int** price = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        price[i] = (int*)malloc(N * sizeof(int));
    char input[N+1];
    for(int i=0; i<N; i++){
        scanf("%s",input);
        for(int j=0; j<N; j++)
            price[i][j] = input[j] - '0';
    }
    int max = recursive(1, 0, price, N, 0);
    printf("%d", max);

    for (int i = 0; i < N; i++) {
        free(price[i]);
    }
    free(price);

    return 0;
}
int recursive(int index, int money, int** priceArr, int N, int current){
    int max=0;
    for(int i=0; i<N; i++){
        if(!(index & 1<<i) && priceArr[current][i] >= money)
            max = MAX(max, recursive(index | 1<<i, priceArr[current][i], priceArr, N, i));
    }
    return max+1;
}