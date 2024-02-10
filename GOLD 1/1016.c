#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int* arr;
    long long maxSqrt, max, min;
    int count = 0;
    long long temp = 0;
    scanf("%lld %lld",&min, &max);
    arr = (int*)malloc(sizeof(int) * ((int)(max - min) + 1));
    for(int i=0; i<=(int)(max-min); i++)
        arr[(int)i] = 0;
    maxSqrt = (int)sqrt(max)+1 < 3 ? 3 : (int)sqrt(max) + 1;

    for(long long i=2; i<maxSqrt; i++){
        long long start = ((min - 1) / (i * i) + 1) * (i * i);
        for (long long j = start; j <= max; j += (i * i)) {
            arr[(int)(j - min)] = 1;
        }
    }
    for(int i=0; i<=(int)(max-min); i++){
        if(!arr[i])
            count++;
    }
    printf("%d",count);
    free(arr);
    return 0;
}