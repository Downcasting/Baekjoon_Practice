
// 14428번 - 수열과 쿼리 16

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */
typedef struct Node{
    int min;
    int index;
}Node;

/* Global Var */
Node** tree;
int* arr;
int num;

/* Function Declarations */
Node* makeNode(int num, int index);
Node* makeTree(int start, int end, int index);
Node* update(int start, int end, int index, int target, int newData);
Node* getMin(int start, int end, int index, int L, int R);

/* Main */
int main(void){
    // 1 : N 입력받음
    scanf("%d",&num);
    arr = (int*)malloc(num*sizeof(int));
    tree = (Node**)malloc(num*4*sizeof(Node*));

    // 2 : 배열 입력받음
    f(i,num)
        scanf("%d",&arr[i]);
    makeTree(0,num-1,1);

    // 3 : 들어올 쿼리 개수들 입력받음
    int query;
    scanf("%d",&query);

    // 4 : 들어올 쿼리들 입력받음
    int a, b, c;
    int answer[query];
    int now=0;
    f(i,query){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            update(0,num-1,1,b-1,c);
        }
        else if(a==2){
            answer[now++] = getMin(0,num-1,1,b-1,c-1)->min;
        }
        else
            printf("WTF??\n");
    }
    f(i,now)
        printf("%d\n",answer[i]);
    return 0;
}

/* Functions */
Node* makeNode(int num, int index){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->min = num;
    newNode->index = index;
    return newNode;
}
Node* makeTree(int start, int end, int index){
    if(start == end){
        tree[index] = makeNode(arr[start], index);
        return tree[index];
    }
    int mid = (start+end)/2;
    int smaller = makeTree(start, mid, index*2)->min <= makeTree(mid+1, end, index*2+1)->min ? index*2 : index*2+1;
    tree[index] = makeNode(tree[smaller]->min, tree[smaller]->index);
    return tree[index];
}
Node* update(int start, int end, int index, int target, int newData){
    if(start > target || end < target)
        return tree[index];
    if(start == end){
        if(start == target){
            arr[start] = newData;
            tree[index]->min = arr[start];
        }
        return tree[index];
    }
    int mid = (start+end)/2;
    int smaller = update(start,mid,index*2,target,newData)->min <= update(mid+1,end,index*2+1,target,newData)->min ? index*2 : index*2+1;
    tree[index]->min = tree[smaller]->min;
    tree[index]->index = tree[smaller]->index;
    return tree[index];
}
Node* getMin(int start, int end, int index, int L, int R){
    if(start > R || end < L)
        return makeNode(1000000001, 0);
    if(L <= start && end <= R)
        return tree[index];
    int mid = (start+end)/2;
    int smaller = getMin(start,mid,index*2,L,R)->min <= getMin(mid+1,end,index*2+1,L,R)->min ? index*2 : index*2+1;
    return tree[smaller];
}