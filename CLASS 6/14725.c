
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
Room** head;

/* Function */
void recursive(char** input, int index, Room* room);
Room* makeRoom(char* name);
Room* place(Room* start, char* name);
void print(Room* room, int level);

/* Main */
int main(void){
    head = (Room**)malloc(1000*sizeof(Room*));
    f(i,1000)
        head[i] = NULL;

    int info;
    scanf("%d",&info);

    int deep;
    char** lines;
    lines = (char**)malloc(15*sizeof(char*));
    f(i,15)
        lines[i] = (char*)malloc(16*sizeof(char));
    f(i,info){
        scanf("%d",&deep);
        for(int j=0; j<deep; j++)
            scanf("%s", lines[j]);
        recursive(lines, deep, NULL);
    }
    for(int i=0; i<1000 && head[i] != NULL; i++)
        print(head[i], 0);
    return 0;
}

/* Functions */
void recursive(char** input, int index, Room* room){
    if(index == 1 && room != NULL)
       return;
    Room* rom;
    if(room == NULL){
        f(i,1000){
            if(head[i] == NULL || strcmp(head[i]->name,input[0]) > 0){
                for(int j=999; j>i; j--)
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
    if(index == 1)
        return;
    Room* nextRoom = place(rom, input[1]);
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
        return node;
    }
    else if(strcmp(now->name, name) == 0)
        return now;
    else{
        Room* node = makeRoom(name);
        node->bro = now;
        start->child = node;
        return node;
    }
    return NULL;
}
void print(Room* room, int level){
    if(room == NULL)
        return;
    char bar[32];
    memset(bar, '-', level*2);
    bar[level*2] = '\0';
    printf("%s%s\n",bar,room->name);
    print(room->child,level+1);
    print(room->bro,level);
    return;
}