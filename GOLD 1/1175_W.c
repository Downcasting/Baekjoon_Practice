/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)
#define MAX_SIZE 65536
#define rowDir(dir) (dir==0 ? -1 : (dir == 2 ? 1 : 0))
#define colDir(dir) (dir==1 ? 1 : (dir == 3 ? -1 : 0))

/* Global Variables */
int deliveryLocation[2];
int index;
int N, M;

/* Function declaration */
int deli(int row, int col){
    if(row*M + col == deliveryLocation[0])
        return 1;
    else if(row*M + col == deliveryLocation[1])
        return 2;
    else
        printf("WHAT\n");
    return 0;
}

/* Struct Declaration */
typedef struct{
    int row;
    int col;
    int dir;
    int delivery; // 0 / 1 / 10 / 11
} Vector;
Vector* makeVector(int row, int col, int dir, int delivery){
    Vector* myVector = (Vector*)malloc(sizeof(Vector));
    myVector->row = row;
    myVector->col = col;
    myVector->dir = dir;
    myVector->delivery = delivery;
    return myVector;
}
typedef struct {
    int front, rear;
    Vector* data[MAX_SIZE];
} Queue;
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}
int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
void enqueue(Queue* queue, Vector* value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->data[queue->rear] = value;
}
Vector* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return NULL; // 또는 다른 적절한 처리
    }
    Vector* value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        // 큐에 원소가 하나만 있을 때 초기화
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return value;
}
int size(Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    } else if (queue->front <= queue->rear) {
        return queue->rear - queue->front + 1;
    } else {
        return MAX_SIZE - (queue->front - queue->rear) + 1;
    }
}
/* Main */
int main(void){
    scanf("%d %d",&N, &M);
    int map[N][M];
    index = 0;
    
    Queue queue;
    initQueue(&queue);
    int archive[N][M][4][2];
    f(i,N){
        f(j,M){
            f(k,4){
                f(l,2)
                    archive[i][j][k][l] = 0;
            }
        }
    }
    char input[M];
    f(i,N){
        scanf("%s",input);
        f(j,M){
            switch(input[j]){
                case '#': 
                    map[i][j] = -1;
                    break;
                case '.':
                    map[i][j] = 0;
                    break;
                case 'C':
                    map[i][j] = 100;
                    deliveryLocation[index++] = M*i+j;
                    break;
                case 'S':
                    map[i][j] = 0;
                    enqueue(&queue,makeVector(i,j,-1,0));
                    break;
                default:
                    break;
            }
        }
    }
    int length = 1;
    int queueSize = 0;
    while(1){
        queueSize  = size(&queue);
        if (queueSize == 0) {
            length = -1;
            break;
        }
        f(i,queueSize){
            Vector* vec = dequeue(&queue);
            for(int i=0; i<4; i++){
                int newRow = vec->row + rowDir(i);
                int newCol = vec->col + colDir(i);
                if(i != vec->dir &&
                    newRow <= N-1 &&
                    newRow >= 0 &&
                    newCol <= M-1 &&
                    newCol >= 0){
                        switch(map[newRow][newCol]){
                            case -1:
                                break;
                            case 100:
                                if(!archive[newRow][newCol][i][vec->delivery | deli(newRow, newCol)]){
                                    if((vec->delivery | deli(newRow, newCol)) == 3){
                                        printf("%d",length);
                                        return 0;
                                    }
                                    enqueue(&queue,makeVector(newRow,newCol,i,vec->delivery | deli(newRow, newCol)));
                                    archive[newRow][newCol][i][vec->delivery | deli(newRow, newCol)] = length;
                                }
                                break;
                            case 0:
                                if(!archive[newRow][newCol][i][vec->delivery]){
                                    enqueue(&queue,makeVector(newRow,newCol,i,vec->delivery));
                                    archive[newRow][newCol][i][vec->delivery] = length;
                                }
                                break;
                        }

                }
            }
        }
        length++;
    }
    printf("%d",length);
    return 0;
}

/* Functions */