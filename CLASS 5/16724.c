
// 16724번 - 피리 부는 사나이

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
char** map;
int** route;

/* Function */

/* Main */
int main(void){
    int row, col;
    scanf("%d %d",&row, &col);
    map = (char**)malloc(row*sizeof(char*));
    route = (int**)malloc(row*sizeof(int*));

    char input[col+1];
    f(i,row){
        map[i] = (char*)malloc((col+1)*sizeof(char));
        route[i] = (int*)malloc((col+1)*sizeof(int));
        scanf("%s",input);
        f(j,col){
            map[i][j] = input[j];
            route[i][j] = -1;
        }
    }
    int r,c;
    int loc;
    f(i,row*col){
        r = i / col;
        c = i % col;
        if(route[r][c] != -1) // 시작하는 자리부터 누군가에게 먹힘
            continue;
        while(route[r][c] == -1){ // 도착한 곳이 처음 도달한 곳이 아닐 때까지
            route[r][c] = i;
            switch(map[r][c]){
                case 'U':
                    r--;
                    break;
                case 'D':
                    r++;
                    break;
                case 'L':
                    c--;
                    break;
                case 'R':
                    c++;
                    break;
                default:
                    printf("%d? WTF???\n",map[r][c]);
            }
        }
        if(route[r][c] != i){ // 이미 여기부터의 길은 누군가 갔다는 뜻 = 이것으로 되돌아가야 함
            int re = route[r][c];
            r = i / col;
            c = i % col;
            while(route[r][c] == i){
                route[r][c] = re;
                switch(map[r][c]){
                    case 'U':
                        r--;
                        break;
                    case 'D':
                        r++;
                        break;
                    case 'L':
                        c--;
                        break;
                    case 'R':
                        c++;
                        break;
                    default:
                        printf("%d? WTF???\n",map[r][c]);
                }
            }
        }
    }
    //f(i,row){
        //f(j,col)
            //printf("%d ",route[i][j]);
        //printf("\n");
    //}
    int var=0;
    f(i,row*col){
        r = i / col;
        c = i % col;
        if(route[r][c] == i)
            var++;
    }
    printf("%d",var);

    return 0;
}

/* Functions */