
// 2568번 - 전깃줄 2

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct lines{
    int start;
    int end;
}line;

/* Global Var */

/* Function */
line* makeLine(int start, int end);
int static compare (const void* first, const void* second);
int binary(line** arr, line* gab, int size);
int static compareInt (const void* first, const void* second);

/* Main */
int main(void){
    int num;
    scanf("%d",&num);

    line* big[num];
    line* comboBig[num];
    line* lines[num];
    int records[num];
    int s,n;
    f(i,num){
        scanf("%d %d", &s, &n);
        lines[i] = makeLine(s,n);
        big[i] = makeLine(0,0);
        comboBig[i] = makeLine(0,0);
        records[i] = -1;
    }

    qsort(lines,num,sizeof(line*),compare);

    int location;
    int max = 0;
    int combo = 0;
    f(i,num){
        location = binary(big,lines[i],max);
        if(location < 0)
            continue;
        big[location] = lines[i];
        if(max < location+1){
            max = location+1;
            f(i,max){
                records[i] = comboBig[i]->start;
            }
        }
        /*
        
        */
        printf("Stage %d - ",i+1);
        f(j,max)
            printf("(%d,%d) ",big[j]->start, big[j]->end);
        printf("\n");
        
        
    }
    printf("%d\n",num-max);
    qsort(records, max, sizeof(int),compareInt);
    int index=0;
    /*
    
    */
    printf("Records : ");
    f(i,num)
        printf("%d ",records[i]);
    printf("\n");

    f(i,num){
        if(lines[i]->start != records[index])
            printf("%d\n",lines[i]->start);
        else
            index++;
    }
    return 0;
}

/* Functions */
line* makeLine(int start, int end){
    line* newLine = (line*)malloc(sizeof(line));
    newLine->start = start;
    newLine->end = end;
    return newLine;
}
int static compare (const void* first, const void* second)
{
    if ((*(line**)first)->start > (*(line**)second)->start)
        return 1;
    else if ((*(line**)first)->start < (*(line**)second)->start)
        return -1;
    else
        return 0;
}
int static compareInt (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
int binary(line** arr, line* gab, int size){
    if(size == 0)
        return 0;
    int start = 0;
    int end = size-1;
    int mid = start;
    while(start <= end){
        if(start == end){
            if(gab->end > arr[start]->end)
                return start+1;
            else
                return start;
        }
        mid = (start+end)/2;
        if(arr[mid]->end == gab->end){
            return mid;
        }
        else if(arr[mid]->end < gab->end){
            start = mid+1;
        }
        else
            end = mid - 1;
    }
    return end;
}