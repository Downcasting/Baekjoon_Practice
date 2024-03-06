
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
Room** head;

/* Main */
int main(void){
    head = (Room**)malloc(15*sizeof(Room*));
    f(i,15)
        head[i] = NULL;

    int info;
    scanf("%d",&info);

    int deep;
    char input[240];
    f(i,info){
        scanf("%d",&deep);
        scanf("%s",input);
        char lines[15][16];
        lines[0] = strtok(input, " ");
        for(int j=1; j<deep; j++)
            strcpy(lines[j],strtok(NULL, " "));
        recursive(lines, deep, NULL);
    }

    return 0;
}

/* Functions */
int recursive(char** input, int index, Room* room){
    if(index == 1)
       return;
    Room* rom;
    if(room == NULL){
        f(i,15){
            if(head[i] == NULL || strcmp(head[i]->name,input[0]) > 0){
                for(int j=14; j>i; j--)
                    head[j] = head[j-1];
                head[i] = makeRoom(input[0]);
                rom = head[i];
                break;
            }
            else if(strcmp(head[i]->name,input[0]) == 0){
                rom = head[i];
                break;
            }
        }
    }
    else
        rom = room;
    Room* nextRoom = place(room, input[1]);
    recursive(input+1, index-1, nextRoom);

}
Room* makeRoom(char* name){
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->bro = NULL;
    newRoom->child = NULL;
    strcpy(newRoom->name, name);
    return newRoom;
}
Room* place(Room* start, char* name){
    // 부모 노드로 시작
    if(start->child == NULL){
        start->child = makeRoom(name);
        return start->child;
    }
    Room* now = start->child;
    while(now->bro != NULL && strcmp(now->bro->name, name) <= 0){
        now = now->bro;
    }
    if(strcmp(now->name, name) < 0){
        Room* node = makeRoom(name);
        node->bro = now->bro;
        now->bro = node;
    }
    else if(strcmp(now->name, name) == 0)
        return now;
    else{
        Room* node = makeRoom(name);
        node->bro = now;
        start->child = node;
    }
    return node;
}