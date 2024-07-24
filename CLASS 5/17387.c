
// 17387번 - 선분 교차 2

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct point{
    int x;
    int y;
}point;

/* Global Var */
point* p1;
point* p2, p3, p4;

/* Function Declarations */

/* Main */
int main(void){
    p1 = (point*)malloc(sizeof(point));
    p2 = (point*)malloc(sizeof(point));
    p3 = (point*)malloc(sizeof(point));
    p4 = (point*)malloc(sizeof(point));
    scanf("%d %d %d %d %d %d %d %d",&(p1->x),&(p1->y),&(p2->x),&(p2->y),&(p3->x),&(p3->y),&(p4->x),&(p4->y));

    return 0;
}

/* Functions */
int CCW()