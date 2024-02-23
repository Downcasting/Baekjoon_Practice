/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int dp[][];
char input[2500];
/* Function */
int recursive(int start, int end);
int isPal(int start, int end);
/* Main */
int main(void){
    scanf("%s",input);


    return 0;
}

/* Functions */
int recursive(int start, int end){
    if(end == start)
        return 1;
    int total = 0;
    for(int i=start+1; i < end; i++){
        total += recursive(first) * recursive(second);
    }
    return total + isPal(str);
}
int isPal(int start, int end){
    for(int i = start; i < (end - start + 1)/2; i++){
        if(input[i] != input[end-i])
            return 0;
    }
    return 1;
}