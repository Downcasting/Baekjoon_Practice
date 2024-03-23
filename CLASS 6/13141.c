
// 13141번 - Ignition (Floyd-Warshall 알고리즘 사용)

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int N, E;
int** length;

/* Function Declarations */

/* Main */
int main(void){
    scanf("%d %d",&N, &E);
    length = (int**)malloc(N*sizeof(int*));
    f(i,N){
        length[i] = (int*)malloc(N*sizeof(int));
        for(int j=i; j<N; j++)
            length[i][j] = 0;
    }
    int a, b, l;
    f(i,E){
        scanf("%d %d %d",&a,&b,&l);
        length[MIN(a,b)-1][MAX(a,b)-1] = l;
    }
    int temp[N][N];
    int same;
    f(i,N-1){
        f(j,N){
            for(k=j; k<N; k++){
                temp[j][k] = length[j][k];
                for(h=0; h<j; h++){
                    if(length[h][j] + length[h][k] < length[j][k])
                        length[j][k] = length[h][j] + length[h][k];
                }
                for(h=j+1; h<k; h++){
                    if(length[j][h] + length[h][k] < length[j][k])
                        length[j][k] = length[j][h] + length[h][k];
                }
                for(h=k+1; h<N; h++){
                    if(length[j][h] + length[k][h] < length[j][k])
                        length[j][k] = length[j][h] + length[k][h];
                }
            }
        }
        same = 1;
        f(j,N){
            for(k=j; k<N; k++){
                if(temp[j][k] != length[j][k]){
                    same = 0;
                    break;
                }
            }
            if(!same)
                break;
        }
        if(same)
            break;
    }
    

    return 0;
}

/* Functions */