
// 7579번 - 앱

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

#define MAX_COST 100

/* Struct */

/* Global Var */
int numOfApps;
int needMem;
int* memOfApps;
int* costOfApps;
int* map;
/* Function Declarations */

/* Main */
int main(void){
    scanf("%d %d",&numOfApps, &needMem);
    memOfApps = (int*)malloc(numOfApps*sizeof(int));
    costOfApps = (int*)malloc(numOfApps*sizeof(int));
    map = (int*)malloc((numOfApps*MAX_COST + 1)*sizeof(int));

    f(i,numOfApps)
        scanf("%d", &memOfApps[i]);
    f(i,numOfApps)
        scanf("%d", &costOfApps[i]);

    f(i,numOfApps*MAX_COST + 1)
        map[i] = 0;
    
    f(i,numOfApps){
        for(int j = numOfApps*MAX_COST; j >= costOfApps[i]; j--){
            map[j] = MAX(map[j], map[j-costOfApps[i]] + memOfApps[i]);
        }
    }
    f(i,numOfApps*MAX_COST+1){ // 틀렸던 이유: 여기가 +1이 아니라 그냥 깡으로 함
        if(map[i] >= needMem){
            printf("%d", i);
            break;
        }
    }
    free(memOfApps);
    free(costOfApps);
    free(map);
    return 0;
}

/* Functions */