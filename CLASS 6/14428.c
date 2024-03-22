
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

/* Main */
int main(void){
    scanf("%d",&num);
    arr = (int*)malloc(num*sizeof(num));
    tree = (Node**)malloc(num*4*sizeof(Node*));
    f(i,num)
        scanf("%d",&arr[i]);
    makeTree(0,num-1,1);
    int query;
    scanf("%d",&query);
    int a, b, c;
    f(i,query){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            update(0,num-1,1,b-1,c);
        }
        else if(a==2){
            int minn = getMin(0,num-1,1,b-1,c-1)->min;
            printf("%d\n",minn);
        }
        else
            printf("WTF??\n");
    }

    return 0;
}

/* Functions */
Node* makeNode(int num, int index){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->min = num;
}
Node* makeTree(int start, int end, int index){
    if(start == end){
        tree[index] = newNode(arr[start], index);
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
        return arr[start];
    }
    int mid = (start+end)/2;
    int smaller = update(start,mid,index*2,target,newData)->min <= update(mid+1,end,index*2+1,target,newData)->min ? index*2, index*2+1;
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
    int smaller = getMin(start,mid,index*2,target,newData)->min <= getMin(mid+1,end,index*2+1,target,newData)->min ? index*2, index*2+1;
    return tree[smaller];
}