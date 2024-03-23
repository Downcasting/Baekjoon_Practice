
// 16565번 - N포커

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int N;
int level;
long long count;

/* Function Declarations */
long long comb(int N, int k);

/* Main */
int main(void){
    // 1 : N 입력받음
    scanf("%d",&N);
    level = N / 4;
    count=0;
    f(i,level){
        if(i % 2 == 0)
            count += comb(13,i+1)*comb(48-i*4,N-4-i*4);
        else
            count -= comb(13,i+1)*comb(48-i*4,N-4-i*4);
        count %= 10007;
    }
    printf("%d",count);
    return 0;
}

/* Functions */
long long comb(int N, int k){
    int revK;
    long long dap=1;
    if(k < N-k)
        revK=k;
    else
        revK=N-k;
    f(i,revK){
        dap *= N-i;
        dap /= (i+1);
    }
    dap %= 10007;
    return dap;
}