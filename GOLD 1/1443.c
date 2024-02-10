#include <stdio.h>
#include <math.h>

int main(void){
    int D, P;
    scanf("%d %d", &D, &P);
    if((int)pow(2, P) >= (int)pow(10, D+1)){
        printf("-1");
        return 0;
    }
    printf("%d\n",D*P);

    return 0;
}