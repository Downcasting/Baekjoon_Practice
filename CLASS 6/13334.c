
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
Line** heap;
int heapSize;
int length;

/* Function Declarations */

/* Main */
int main(void){
    scanf("%d",&num);
    lines = (Line**)malloc(num*sizeof(Line*));
    heap = (Line**)malloc((num+1)*sizeof(Line*));
    int a, b;
    f(i,num){
        scanf("%d %d",&a, &b);
        lines[i] = makeLine(MIN(a,b),MAX(a,b));
        heap[i+1] = NULL;
    }
    scanf("%d",&length);
    qsort(lines, num, sizeof(Line*),compare);
    heapSize = 0;
    int maxSize = 0;
    f(i,num){
        if(lines[i]->end - lines[i]->start > length)
            continue;
        addHeap(lines[i]);
        maxSize = MAX(heapSize, maxSize);
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
    while(line->end - heap[1]->start > length && heap[1] != NULL){
        heap[1] = heap[heapSize];
        heap[heapSize--] = NULL;
        curr = 1;
        while(2*curr <= heapSize){
            int s1 = heap[curr*2] == NULL ? 2147483647 : heap[curr*2]->start;
            int s2 = heap[curr*2] == NULL ? 2147483647 : heap[curr*2+1]->start;
            if(MIN(s1,s2) < heap[curr]->start){
                if(s1 < s2){
                    Line* temp = heap[curr];
                    heap[curr] = heap[curr*2];
                    heap[curr*2] = temp;
                    curr = curr*2;
                }
                else{
                    Line* temp = heap[curr];
                    heap[curr] = heap[curr*2+1];
                    heap[curr*2+1] = temp;
                    curr = curr*2+1;
                }
            }
            else
                break;
        }
    }
    heap[++heapSize] = line;
    curr = heapSize;
    while(curr > 0){
        if(heap[curr/2]->start > heap[curr]){
            Line* temp = heap[curr];
            heap[curr] = heap[curr/2];
            heap[curr/2] = temp;
            curr = curr/2;
        }
        else
            break;
    }
}