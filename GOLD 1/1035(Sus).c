#include <stdio.h>

#define MIN(a,b) a>b?b:a

int map[5][5];
int num = 0;
char input[5];

int distance(int curr, int x, int y);
int main(void){
    int dots[] = {-1, -1, -1, -1, -1};
    for(int i=0; i<5; i++){
        scanf("%s",input);
        for(int j=0; j<5; j++){
            if(input[j] == '*'){
                map[i][j] = 1;
                dots[num++] = i*5+j;
            }
            else
                map[i][j] = 0;
        }
    }
    int move = 0;
    int reducedDistance = 100;
    int finalChoose = 0;
    while(1){
        if(1 == 1) // 별이 모두 모임
            break;
        for(int i=0; i<num; i++){
            
        }
        move++;
    }
    printf("%d",move);
    return 0;
}
int distance(int curr, int x, int y){
    for(int i=0; i<num; i++){
        if(i == curr)
            continue;
        
    }
}