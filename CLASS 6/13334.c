
// 13334번 - 철로

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct Line{
    int start;
    int end;
}Line;

/* Global Var */
int num;
Line** lines;
int length;

/* Function Declarations */

/* Main */
int main(void){
    scanf("%d",&num);
    lines = (Line**)malloc(num*sizeof(Line*));
    int a, b;
    f(i,num){
        scanf("%d %d",&a, &b);
        lines[i] = makeLine(MIN(a,b),MAX(a,b));
    }
    scanf("%d",&length);
    int many = 0;
    f(i,num){
        
    }
    return 0;
}

/* Functions */
Line* makeLine(int a, int b){
    Line* newLine = (Line*)malloc(sizeof(Line));
    newLine->start = a;
    newLine->end = b;
    return newLine;
}
int static compare (const void* first, const void* second)
{
    if ((*(Line**)first)->start > (*(Line**)second)->start)
        return 1;
    else if ((*(Line**)first)->start < (*(Line**)second)->start)
        return -1;
    else{
        if ((*(Line**)first)->second > (*(Line**)second)->second)
            return 1;
        else if ((*(Line**)first)->second < (*(Line**)second)->second)
            return -1;
    }
        return 0;
}