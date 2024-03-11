
// 2357번 - 최솟값과 최댓값

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct Node{
    int max;
    int min;
}Node;

/* Global Var */
int num;
int* arr;
Node** tree;
/* Function Declarations */
Node* makeNode(int max, int min);
Node* makeTree(int start, int end, int index);
Node* getMinMax(int start, int end, int index, int L, int R);

/* Main */
int main(void){
    int question;
    scanf("%d %d",&num, &question);
    arr = (int*)malloc(num*sizeof(int));
    f(i,num)
        scanf("%d",&arr[i]);
    tree = (Node**)malloc(4*num*sizeof(Node*));
    makeTree(0, num-1, 1);
    int start, end;
    Node* nd[question];
    f(i,question){
        scanf("%d %d",&start, &end);
        nd[i] = getMinMax(0, num-1, 1, start-1, end-1);
    }
    f(i,question)
        printf("%d %d\n",nd[i]->min, nd[i]->max);
    return 0;
}

/* Functions */
Node* makeNode(int max, int min){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->max = max;
    newNode->min = min;
    return newNode;
}
Node* makeTree(int start, int end, int index){
    if(start == end){
        Node* node = makeNode(arr[start], arr[start]);
        tree[index] = node;
        return node;
    }
    int mid = (start+end)/2;
    Node* n1 = makeTree(start, mid, index*2);
    Node* n2 = makeTree(mid+1, end, index*2+1);
    int max = MAX(n1->max, n2->max);
    int min = MIN(n1->min, n2->min);
    Node* node = makeNode(max, min);
    tree[index] = node;
    return node;
}
Node* getMinMax(int start, int end, int index, int L, int R){
    if(start > R || end < L)
        return NULL;
    if(L <= start && end <= R)
        return tree[index];
    int mid = (start+end)/2;
    Node* n1 = getMinMax(start, mid, index*2, L, R);
    Node* n2 = getMinMax(mid+1, end, index*2+1, L, R);
    if(n1 == NULL)
        return n2;
    if(n2 == NULL)
        return n1;
    int max = MAX(n1->max, n2->max);
    int min = MIN(n1->min, n2->min);
    Node* node = makeNode(max, min);
    return node;
}