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
    int count = 0;
    int even = recursive(0,totalIndex);
    int odd = recursive(1,totalIndex);
    printf("%d\n",even);
    printf("%d",odd);
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
}
int recursive(int location, int index){
    if(!index)
        return 0;
    int max = 0;
    for(int i=location; i<size*size - 2*(index-1); i += 2){
        array[totalIndex-index] = i;
        if(inPlace(i, totalIndex - index))
            max = MAX(max, 1 + recursive(i+2, index-1));
        if(index == totalIndex){
            for(int i=0; i<totalIndex; i++)
                printf("%d ",array[i]);
            printf("\n");
        }
    }
    return max;
}
