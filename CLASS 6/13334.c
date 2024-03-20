
// 13334번 - 철로

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)
#define NULLVAL 999999999

#define PRINTn

/* Struct */
typedef struct Line{
    int start;
    int end;
}Line;

/* Global Var */
int num;
Line** lines;
int* heap;
int heapSize;
int length;

/* Function Declarations */
Line* makeLine(int a, int b);
int static compare (const void* first, const void* second);
void addHeap(Line* line);

/* Main */
int main(void){
    scanf("%d",&num);
    lines = (Line**)malloc(num*sizeof(Line*));
    heap = (int*)malloc((num+1)*sizeof(int));
    int a, b;
    f(i,num){
        scanf("%d %d",&a, &b);
        lines[i] = makeLine(MIN(a,b),MAX(a,b));
        heap[i+1] = NULLVAL;
    }
    scanf("%d",&length);
    qsort(lines, num, sizeof(Line*),compare);
    #ifdef PRINT
    f(i,num)
        printf("List %d, start: %d end: %d\n",i+1,lines[i]->start, lines[i]->end);
    #endif
    heapSize = 0;
    int maxSize = 0;
    f(i,num){
        if(lines[i]->end - lines[i]->start > length)
            continue;
        addHeap(lines[i]);
        maxSize = MAX(heapSize, maxSize);
        #ifdef PRINT
        printf("%dth Try: heapSize is %d\n",i+1,heapSize);
        #endif
    }
    printf("%d",maxSize);
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
    if ((*(Line**)first)->end > (*(Line**)second)->end)
        return 1;
    else if ((*(Line**)first)->end < (*(Line**)second)->end)
        return -1;
    else{
        if ((*(Line**)first)->start > (*(Line**)second)->start)
            return 1;
        else if ((*(Line**)first)->start < (*(Line**)second)->start)
            return -1;
    }
    return 0;
}
void addHeap(Line* line){
    int curr;
    while(heapSize > 0 && line->end - heap[1] > length){
        heap[1] = heap[heapSize];
        heap[heapSize--] = NULLVAL;
        curr = 1;
        // 여기가 문제였네;;;;
        while (2 * curr <= heapSize) {
            int minChild = (heap[curr * 2] < heap[curr * 2 + 1]) ? curr * 2 : curr * 2 + 1;
            if (heap[minChild] < heap[curr]) {
                int temp = heap[curr];
                heap[curr] = heap[minChild];
                heap[minChild] = temp;
                curr = minChild;
            } else {
                break;
            }
        }
    }
    heap[++heapSize] = line->start;
    curr = heapSize;
    while (curr > 1 && heap[curr / 2] > heap[curr]) {
        int temp = heap[curr];
        heap[curr] = heap[curr / 2];
        heap[curr / 2] = temp;
        curr = curr / 2;
    }
}