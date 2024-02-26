
// 1799번 - 비숍

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int size;
int** board;

int* array;
int totalIndex;

/* Function */
int inPlace(int location, int index);
int recursive(int location, int index);
int next(int location);

/* Main */
int main(void){
    scanf("%d",&size);

    totalIndex = size-1;

    board = (int**) malloc(size*sizeof(int*));
    array = (int*) malloc(size*sizeof(int));

    f(i,size){
        array[i] = -1;
        board[i] = (int*) malloc(size*sizeof(int));
        f(j,size)
            scanf("%d",&board[i][j]);
    }
    if(size == 1){
        printf("%d",board[0][0]);
        return 0;
    }
    
    int count = 0;
    int even = recursive(0,totalIndex);
    int odd = recursive(1,totalIndex);
    printf("%d",even+odd);
    return 0;
}
/* Functions */
int inPlace(int location, int index){
    if(!board[location / size][location % size])
        return 0;
    int row = location / size;
    int col = location % size;
    for(int i=0; i<index; i++){
        int r = array[i] / size;
        int c = array[i] % size;
        if (abs(row - r) == abs(col - c))
            return 0;
    }
    return 1;
    // 따로 짝수, 홀수 자리에 대한 위치를 만들어야 함
}
int recursive(int location, int index){
    if(!index || location >= size*size)
        return 0;
    int max = 0;
    for(int i=location; i<size*size; i = next(i)){
        array[totalIndex-index] = i;
        if(inPlace(i, totalIndex - index))
            max = MAX(max, 1 + recursive(next(i), index-1));
        if(max == index)
            continue;
    }
    return max;
}
int next(int location){
    int row = location / size;
    int col = location % size;
    int odd = size % 2;
    if(col + 2 < size || odd)
        return location+2;
    else{
        if(col == size-1)
            return location+1;
        else if(col == size-2)
            return location+3;
        else
            printf("asdf\n");
    }
    return location+2;
}