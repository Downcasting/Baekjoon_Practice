#include <stdio.h>
#include <math.h>

#define MAX(a,b) a>b?a:b

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(void){

    int L, K, C;
    int blockCount = 0;

    scanf("%d %d %d", &L, &K, &C);
    
    int cut[K];     // K개의 칼집
    int block[K+1]; // (최대) K+1개의 블록

    for(int i=0; i<K; i++)
        scanf("%d", &cut[i]);
    qsort(cut, K, sizeof(int), compare);
    block[blockCount++] = cut[0] - 0;
    for(int i=0; i<K-1; i++){
        if(cut[i+1] - cut[i])
            block[blockCount++] = cut[i+1] - cut[i];
    }
    if(L - cut[K-1])
        block[blockCount++] = L - cut[K-1];

    int biggestBlock = 0;
    for(int i=0; i<blockCount; i++)
        biggestBlock = MAX(biggestBlock, block[i]);

    int base = MAX((int) ceil((double)L / (double)(C+1)),biggestBlock);
    int tempblockCount, container, success, firstCut;

    while(1){
        success = 0;
        tempblockCount = blockCount-1;
        for(int i=C; i>=0; i--){ // 최대 C+1 도막까지 만들어낼 수 있다
            container = base;
            if(!i){                                         // 마지막 블록에 도달함
                while(tempblockCount >= 0){                 // 있는 대로 다 집어넣음
                    container -= block[tempblockCount--];
                    //printf("%d Block was put in %d container, left: %d\n", tempblockCount+1, i, container);
                }
                if(container >= 0){                         // 넣고도 공간이 남음(성공)
                    success = 1;
                    firstCut = base - container; // 여기서 0이?
                    break;
                }
                else                                        // 다 못 넣음(실패)
                    break;
            }
            while(tempblockCount >= 0 && container >= block[tempblockCount]){   // 넣을 수 있는 블록이 남아 있다
                container -= block[tempblockCount--];
                //printf("%d Block was put in %d container, left: %d\n", tempblockCount+1, i, container);
            }
            if(tempblockCount < 0){ // 모든 도막 소요됨
                success = 1;
                firstCut = cut[0]; // 1 이상?
                break;
            } 
                
        }
        if(success > 0)
            break;
        // 여기다가 이제 올라갈 방법을 적어 넣으면 될 듯 합니다 //
        base++;
    }
    printf("%d %d",base, firstCut);
    return 0;
}