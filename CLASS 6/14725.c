
// 14725번 - 개미굴

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct Room{
    char name[16];
    struct Room* child;
    struct Room* bro;
}Room;

/* Global Var */

/* Function */
Room* head;

/* Main */
int main(void){
    head = (Room*)malloc(15*sizeof(Room));
    f(i,15)
        head[i] = NULL;

    int info;
    scanf("%d",&info);

    int deep;
    char input[240];
    f(i,info){
        scanf("%d",&deep);
        scanf("%s",input);
        recursive(input, deep, 1);
    }

    return 0;
}

/* Functions */
int recursive(char* input, int index, int isHead){
    if(index < 2)
        return;
    char* first = strtok(input, " ");
    char*
}
Room* makeRoom(char* name){
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->bro = NULL;
    newRoom->child = NULL;
    strcpy(newRoom->name, name);
    return newRoom;
}