
// 4386번 - 별자리

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct line{
    int first;
    int second;
    float length;
}line;

/* Global Var */
float* x;
float* y;

/* Function */
line* makeLine(int first, int second);
int static compare (const void* first, const void* second);
int getParent(int* arr, int index);

/* Main */
int main(void){
    int num;
    scanf("%d",&num);
    x = (float*)malloc(num*sizeof(float));
    y = (float*)malloc(num*sizeof(float));

    line* lines[(num*(num-1))/2];
    int index = 0;

    int stars[num];

    f(i,num){
        scanf("%f %f", &x[i], &y[i]);
        stars[i] = -1;
    }
    
    f(i,num-1){
        for(int j=i+1; j<num; j++)
            lines[index++] = makeLine(i,j);
    }
    qsort(lines, (num*(num-1))/2, sizeof(line*), compare);
    float total = 0;
    f(i,(num*(num-1))/2){
        if(getParent(stars, lines[i]->first) != getParent(stars, lines[i]->second)){
            total += lines[i]->length;
            stars[getParent(stars,lines[i]->first)] = getParent(stars, lines[i]->second);
        }
    }
    printf("%.3f",total);
    return 0;
}

/* Functions */
line* makeLine(int first, int second){
    float xDiff = x[first] - x[second];
    float yDiff = y[first] - y[second];
    float length = sqrt(xDiff*xDiff + yDiff*yDiff);

    line* newLine = (line*)malloc(sizeof(line));
    newLine->first = first;
    newLine->second = second;
    newLine->length = length;
    return newLine;
}
int static compare (const void* first, const void* second)
{
    if ((*(line**)first)->length > (*(line**)second)->length)
        return 1;
    else if ((*(line**)first)->length < (*(line**)second)->length)
        return -1;
    else
        return 0;
}
int getParent(int* arr, int index){
    int curr = index;
    while(arr[curr] != -1){
        curr = arr[curr];
    }
    return curr;
}


