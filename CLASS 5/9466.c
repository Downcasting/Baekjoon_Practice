
// 9466번 - 팀 프로젝트

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct node{
    int next;
    int group; // -1 to undefined, -999 to no group
    int visit;
}node;
/* Global Var */

/* Function Declarations */
node* makeNode(int next);
/* Main */
int main(void){
    int T, num, input, count;
    scanf("%d", &T);
    f(i,T){
        scanf("%d", &num);
        node* nodeArray[num];
        f(j,num){
            scanf("%d", &input);
            nodeArray[j] = makeNode(input-1);
        }
        f(j,num){
            node* curNode = nodeArray[j];
            if(curNode->group != -1)
                continue;
            while(curNode->visit != j && curNode->group == -1){
                curNode->visit = j;
                curNode = nodeArray[curNode->next];
            }
            if(curNode == nodeArray[j]){ // 결국 돌고 돌아 처음으로
                f(k,num){
                    if(nodeArray[k]->visit == j)
                        nodeArray[k]->group = j;
                }
            }
            else
                nodeArray[j]->group = -999;
        }
        count = 0;
        f(j,num){
            if(nodeArray[j]-> group = -999)
                count++;
        }
        printf("%d\n",count);
    }

    return 0;
}

/* Functions */
node* makeNode(int next){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = -1;
    newNode->group = -1;
    newNode->visit = -1;
    return newNode;
}