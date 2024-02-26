/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)
#define FM 4000000

/* Struct */

/* Global Var */

/* Function */
int sum(int* prime, int start, int end);
/* Main */
int main(void){
    bool* isPrime = (bool*) malloc((FM+1)*sizeof(bool));
    int prime[300000];
    int index=0;
    for(int i=0; i<FM; i++)
        isPrime[i] = true;
    for(int i=2; i<FM; i++){
        if(isPrime[i]){
            prime[index++] = i;
            for(int j=i*2; j<FM; j += i)
                isPrime[j] = 0;
        }
    }
    prime[index] = -1;
    int N;
    scanf("%d",&N);
    int start = 0;
    int end = 0;

    int current;
    int count = 0;
    while(prime[start] <= N && prime[end] != -1){ 
        current = sum(prime,start,end);
        //printf("Start is %d, End is %d, Sum is %d\n",prime[start], prime[end], current);
        if(current == N){
            count++;
            end++;
        }
        else if(current < N)
            end++;
        else
            start++;
    }
    printf("%d",count);
    return 0;
}

/* Functions */
int sum(int* prime, int start, int end){
    int summ = 0;
    for(int i=start; i<=end; i++)
        summ += prime[i];
    return summ;
}