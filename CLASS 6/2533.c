
// 2533번 - 사회망 서비스

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)
#define NULL 0

/* Struct */
typedef struct edge{
    int dest;
    edge* next;
}edge;

/* Global Var */
int** dp;
edge** map;
/* Function Declarations */

/* Main */
int main(void){
    int num, a, b;
    scanf("%d",&num);

    dp = (int**)malloc(num*sizeof(int*));
    map = (edge**)malloc(num*sizeof(edge*));
    f(i,num){
        dp[i] = (int*)malloc(2*sizeof(int));
        dp[i][0] = 0;
        dp[i][1] = 0;
        map[i] = NULL;
    }

    f(i,num){
        scanf("%d %d",&a, &b);
        addNode(map[a], b);
    }

    return 0;
}

/* Functions */
void addNode(edge* currentNode, int dest){
    edge* curr = currentNode;
    edge* befCurr = NULL;
    while(curr != NULL){
        befCurr = curr;
        curr = curr->next;
    }
    if(befCurr != NULL)
        befCurr->next = curr;
    curr = makeNode(dest);
    return;
}
edge* makeNode(int dest){
    edge* newNode = (edge*)malloc(sizeof(edge));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}