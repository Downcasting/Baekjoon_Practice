
// 9466번 - 팀 프로젝트

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)


/* Global Var */
int* cycleArray;    // 현재 iteration에 생성된 cycle의 node들
int* nodeArray;     // 전체 iteration에 저장된 node들
int* visited;       // 전체 iteration에 방문된 node들
int currentAdd;
int count;

/* Function Declarations */
void dfs(int n);

/* Main */
int main(void){
    int T, num, input;
    cycleArray = (int*)malloc(4);
    nodeArray = (int*)malloc(4);

    scanf("%d", &T);
    f(i,T){
        scanf("%d", &num);
        free(cycleArray);
        free(nodeArray);
        free(visited);
        cycleArray = (int*)malloc(sizeof(int)*num);
        nodeArray = (int*)malloc(sizeof(int)*num);
        visited = (int*)malloc(sizeof(int)*num);
        memset(cycleArray, -1, num*sizeof(int));
        memset(visited, 0, num*sizeof(int));
        f(j,num){
            scanf("%d", &input);
            nodeArray[j] = input-1;
        }
        count = num;
        f(j,num){
            currentAdd = 0;
            if(visited[j] == 0)
                dfs(j);
        }
        printf("%d\n",count);
    }

    return 0;
}

/* Functions */
void dfs(int n){
    visited[n] = 1;
    cycleArray[currentAdd++] = n;

    int next = nodeArray[n];

    if(visited[next] == 1){ // 도착하려는 곳이 이미 방문한 곳
        int add=0;
        f(i,currentAdd){
            if(cycleArray[i] == n)
                break;
            add++;
        }
        count -= currentAdd-add;
        return;
    }
    else
        dfs(next);
}