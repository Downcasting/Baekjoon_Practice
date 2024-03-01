
// 12100번 - 2048 (Easy)

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int*** map;
int size;
int max;

/* Function */
void move(int index);
void spinNpush(int origin, int** panel, int dir);

/* Main */
int main(void){
    max = 0;
    map = (int***)malloc(1365*sizeof(int**));
    scanf("%d",&size);
    f(i,1365){
        map[i] = (int**)malloc(size*sizeof(int*));
        f(j,size)
            map[i][j] = (int*)malloc(size*sizeof(int));
    }
    f(i,size){
        f(j,size)
            scanf("%d",map[0][i][j]);
    }
    move(0);
    printf("%d",max);
    return 0;
}

/* Functions */
void move(int index){
    if(index >= 341){
        f(i,size){
            f(j,size)
                max = MAX(map[index][i][j], max);
        }
        return;
    }
    int** temp;
    temp = (int**)malloc(size*sizeof(int*));
    f(i,size)
        temp[i] = (int*)malloc(size*sizeof(int));
    for(int i=4*index+1; i<=4*index+4; i++){
        spinNpush(index, temp, i);
        f(j,size){
            f(k,size)
                map[i][j][k] = temp[j][k];
        }
        move(i);
    }
    f(i,size)
        free(temp[i]);
    free(temp);
}
void spinNpush(int origin, int** panel, int dir){
    
    switch(dir){ // 돌리기
        case 0:
            // 270도 회전
            f(i, size){
                f(j, size)
                    panel[(size-1)-j][i] = map[origin][i][j];
            }
            break;
        case 1:
            // 무회전
            break;
        case 2:
            // 90도 회전
            f(i, size){
                f(j, size)
                    panel[j][(size-1)-i] = map[origin][i][j];
            }
            break;
        case 3:
            // 180도 회전
            f(i, size){
                f(j, size)
                    panel[(size-1)-i][j] = map[origin][i][j];
            }
            break;
        default:
            printf("WHAT\n");
    }
    f(i,size-1){
        f(j,size){
            if(panel[i][j] == panel[i+1][j] && panel[i][j] != 0){
                panel[i][j] *= 2;
                panel[i+1][j] = 0;
            }
        }
    }
    for(int i=size-1; i>=1; i--){
        f(j,size){
            if(panel[i][j] != 0 && panel[i-1][j] == 0){
                panel[i-1][j] = panel[i][j];
                panel[i][j] = 0;
            }
        }
    }
    switch(dir){ // 원상복구
        case 0:
            // 270도 회전
            f(i, size){
                f(j, size)
                    panel[j][(size-1)-i] = map[origin][i][j];
            }
            break;
        case 1:
            // 무회전
            break;
        case 2:
            // 90도 회전
            f(i, size){
                f(j, size)
                    panel[(size-1)-j][i] = map[origin][i][j];
            }
            break;
        case 3:
            // 180도 회전
            f(i, size){
                f(j, size)
                    panel[(size-1)-i][j] = map[origin][i][j];
            }
            break;
        default:
            printf("WHAT\n");
    }
    return;
}