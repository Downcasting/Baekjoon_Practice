/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(a,b) for(int a=0; a<b; a++)

/* Struct */
typedef struct Jewel{
    int weight;
    int value;
} Jewel;

/* Global Var */
int heapSize=0;

/* Function */
Jewel* makeJewel(int weight, int value);
int static compare (const void* first, const void* second);
int static compareJewel (const void* first, const void* second);
void addNode(Jewel** heap, Jewel* newJewel);
int pop(Jewel** heap);

/* Main */
int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    Jewel* jewel[N];
    Jewel** maxHeap = (Jewel**)malloc(N * sizeof(Jewel*));

    int bag[K];

    long long totalValue=0;

    int aa, bb;
    f(i,N){
        scanf("%d %d",&aa, &bb);
        jewel[i] = makeJewel(aa,bb);
        maxHeap[i] = NULL;
    }
    f(i,K)
        scanf("%d",&bag[i]);
    
    qsort(bag,K,sizeof(int),compare);
    f(i,K)
        printf("Bag %d - %d\n", i+1, bag[i]);
    qsort(jewel, N, sizeof(Jewel*),compareJewel);
    f(i,N)
        printf("Jewel %d - weight[%d], value[%d]\n", i+1, jewel[i]->weight, jewel[i]->value);

    int usedBag = 0;
    f(i,N){
        if(usedBag == K) // 모든 가방 다 넣음
            break;
        if(bag[usedBag] < jewel[i]->weight){ // 이번에 집을 보석이 현재 가방보다 커짐
            // 따라서 현재 보석 중 가장 가치 있는 걸 넣어야 함
            printf("%dth try - max weight of %d, collided with the bag %d [size: %d]\n",i+1, jewel[i]->weight, usedBag+1, bag[usedBag]);
            int maxJewel = pop(maxHeap); // 지금 있는 보석 중 가장 가치 있는 보석을...
            if(maxJewel != -1)           // 뽑아 온게 이상한 보석이 아니라면
                totalValue += maxJewel;
            printf("%d was added to totalValue, sum: %d\n",maxJewel, totalValue);
            i--;                         // 다시, 다음으로 집을 보석을 조사하기(가방만 다음 가방으로 바뀜)
            usedBag++;
        }
        else
            addNode(maxHeap, jewel[i]);  // 문제 없으면, Heap에 새 보석을 넣기로
    }
    if(usedBag < K){ // 모든 보석을 돌았는데, 가방에 안 넣은 상태임 (가방이 남았고, 넣을 보석도 남음)
        for(int i=usedBag; i<K; i++){
            int maxJewel = pop(maxHeap); // 가장 높은 가치의 것들부터
            if(maxJewel != -1)
                totalValue += maxJewel;
            printf("%d was added to totalValue, sum: %d\n",maxJewel, totalValue);
        }
    }
    printf("%lld\n",totalValue);
    return 0;
}

/* Functions */
Jewel* makeJewel(int weight, int value){
    Jewel* newJewel = (Jewel*)malloc(sizeof(Jewel));
    newJewel->weight = weight;
    newJewel->value = value;
    return newJewel;
}
int static compareJewel (const void* first, const void* second)
{
    if ((*(Jewel**)first)->weight > (*(Jewel**)second)->weight)
        return 1;
    else if ((*(Jewel**)first)->weight < (*(Jewel**)second)->weight)
        return -1;
    else
        return 0;
}
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
void addNode(Jewel** heap, Jewel* newJewel){
    heap[heapSize++] = newJewel;
    int index = heapSize-1;
    Jewel* temp;
    while(index > 0 && heap[index]->value > heap[index/2]->value){
        temp = heap[index];
        heap[index] = heap[index/2];
        heap[index/2] = temp;
        index /= 2;
    }
    return;
}
int pop(Jewel** heap){
    
    printf("Current Heap Status...\n");
    printf("Size: %d, elements - {",heapSize);
    f(i,heapSize)
        printf("[v %d, w %d]",heap[i]->value, heap[i]->weight);
    printf("}\n");
    
    if(!heapSize)
        return -1;
    int min = heap[0]->value;
    heap[0] = heap[--heapSize];
    heap[heapSize] = NULL;
    int index = 0;
    Jewel* temp = NULL;
    while(index < heapSize){
        int val1 = 2*index+1 < heapSize ? heap[2*index+1]->value : -1;
        int val2 = 2*index+2 < heapSize ? heap[2*index+2]->value : -1;
        if(MAX(val1, val2) > heap[index]->value){ // 일단 아래로 내려갈 만 함
            if(val1 > val2){
                temp = heap[index];
                heap[index] = heap[2*index+1];
                heap[2*index+1] = temp;
                index = 2*index+1;
            }
            else{
                temp = heap[index];
                heap[index] = heap[2*index+2];
                heap[2*index+2] = temp;
                index = 2*index+2;
            }
        }
        else{ // 더 이상 안 내려가도 됨
            break;
        }
    }
    return min;
}