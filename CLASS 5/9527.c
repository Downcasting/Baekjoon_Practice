
// 9527번 - 1의 개수 세기

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */

/* Function */
long long getBinary(long long input);

/* Main */
int main(void){
    long long a, b;
    scanf("%lld %lld",&a,&b);
    long long bin = getBinary(b);
    bin -= getBinary(a-1);
    printf("%lld",bin);
    return 0;
}

/* Functions */
long long getBinary(long long input){
    long long total = 0;
    long long test = input;
    int index = 0;
    while(test != 0){
        test /= 2;
        index++;
    }
    for(int i=index-1; i>= 0; i--){
        total += (input >> (i+1)) << i;
        if(input & (1LL << i))
            total += 1LL + (input % (1LL << i));
    }
    return total;
}