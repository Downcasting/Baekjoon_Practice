
// 1113번 - 수영장 만들기

#include <stdio.h>

#define MIN(a,b) a>b ? b : a

int main(void){

    int N, M;   // 수영장 크기의 열 / 행
    scanf("%d %d",&N, &M);

    int pool[N][M];     // 입력된 수영장 데이터
    int value[N][M];    // 재고할 수영장 데이터
    char input[N][M];

    int up, left, down, right, temp; // value 지정 시 필요한 임시변수

    int water = 0; // 물의 총량

    /* 수영장 데이터 입력받기 + 재고할 데이터 초기화 */
    for(int i=0; i<N; i++){
        scanf("%s",input[i]);
        for(int j=0; j<M; j++){
            pool[i][j] = (int) (input[i][j] - '0');
            value[i][j] = 0;
        }
    }
    /* 1차: 오른쪽 아래로 값 수정 */
    for(int i=1; i<N-1; i++){
        for(int j=1; j<M-1; j++){

            /* 위쪽 검사 */
            if(pool[i][j] >= value[i-1][j] + pool[i-1][j])      // 위쪽의 수위보다 아래쪽 수위가 훨 높음
                up = 0;
            else                                                // 위쪽의 수위 + 바닥이 더 높음
                up = value[i-1][j] + pool[i-1][j] - pool[i][j];
            
            /* 왼쪽 검사 */
            if(pool[i][j] >= value[i][j-1] + pool[i][j-1])      // 왼쪽의 수위보다 아래쪽 수위가 훨 높음
                left = 0;
            else                                                // 왼쪽의 수위 + 바닥이 더 높음
                left = value[i][j-1] + pool[i][j-1] - pool[i][j];
            value[i][j] = MIN(up, left);
        }
    }
    for(int k=0; k<50; k++){
        /* 2차: 왼쪽 위로 값 수정 */
        for(int i=N-2; i>0; i--){
            for(int j=M-2; j>0; j--){
                
                /* 아래쪽 검사 */
                if(pool[i][j] >= value[i+1][j] + pool[i+1][j])      // 아래쪽의 수위보다 아래쪽 수위가 훨 높음
                    down = 0;
                else                                                // 아래쪽의 수위 + 바닥이 더 높음
                    down = value[i+1][j] + pool[i+1][j] - pool[i][j];
                
                /* 오른쪽 검사 */
                if(pool[i][j] >= value[i][j+1] + pool[i][j+1])      // 오른쪽의 수위보다 아래쪽 수위가 훨 높음
                    right = 0;
                else                                                // 오른쪽의 수위 + 바닥이 더 높음
                    right = value[i][j+1] + pool[i][j+1] - pool[i][j];
                temp = MIN(down, right);
                value[i][j] = MIN(temp, value[i][j]);
            }
        }

        /* 3차: 오른쪽 아래로 값 수정 */
        for(int i=1; i<N-1; i++){
            for(int j=1; j<M-1; j++){

                /* 위쪽 검사 */
                if(pool[i][j] >= value[i-1][j] + pool[i-1][j])      // 위쪽의 수위보다 아래쪽 수위가 훨 높음
                    up = 0;
                else                                                // 위쪽의 수위 + 바닥이 더 높음
                    up = value[i-1][j] + pool[i-1][j] - pool[i][j];
                
                /* 왼쪽 검사 */
                if(pool[i][j] >= value[i][j-1] + pool[i][j-1])      // 왼쪽의 수위보다 아래쪽 수위가 훨 높음
                    left = 0;
                else                                                // 왼쪽의 수위 + 바닥이 더 높음
                    left = value[i][j-1] + pool[i][j-1] - pool[i][j];
                temp = MIN(up, left);
                value[i][j] = MIN(value[i][j], temp);
            }
        }
    }
    
    for(int i=1; i<N-1; i++){
        for(int j=1; j<M-1; j++)
            water += value[i][j];
    }
    printf("%d",water);

    return 0;
}