
// 11505번 - 구간 곱 구하기

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)
#define SOSU 1000000007LL

/* Struct */

/* Global Var */
long long* arr;
long long* tree;
int N, M, K;

/* Function Declarations */
long long makeTree(int start, int end, int index);
long long update(int start, int end, int index, int target, long long newData);
long long mult(int start, int end, int index, int L, int R);

/* Main */
int main(void){
    scanf("%d %d %d",&N, &M, &K);
    arr = (long long*)malloc(N*sizeof(long long));
    tree = (long long*)malloc(N*4*sizeof(long long));
    f(i,N)
        scanf("%lld",&arr[i]);
    makeTree(0,N-1,1);
    int a, b;
    long long c;
    int answer = 0;
    long long dap[K];
    f(i,M+K){
        scanf("%d %d %lld",&a ,&b, &c);
        if(a == 1){
            update(0, N-1, 1, b-1, c);
        }
        else if(a == 2){
            dap[answer++] = mult(0, N-1, 1, b-1, c-1);
        }
        else
            printf("asdf\n");
    }
    f(i,K)
        printf("%lld\n",dap[i]);
    makeTree(0, N-1, 1);
        
    return 0;
}

/* Functions */
long long makeTree(int start, int end, int index){
    if(start == end){
        tree[index] = arr[start];
        return arr[start];
    }
    int mid = (start+end)/2;
    tree[index] = (makeTree(start, mid, index*2) * makeTree(mid+1, end, index*2+1)) % SOSU;
    return tree[index];
}
long long update(int start, int end, int index, int target, long long newData){
    if(start > target || end < target)
        return tree[index];
    if(start == end){
        if(start == target){
            arr[start] = newData;
            tree[index] = arr[start];
        }
        return arr[start];
    }
    int mid = (start+end)/2;
    tree[index] = (update(start,mid,index*2,target,newData)*update(mid+1,end,index*2+1,target,newData)) % SOSU;
    return tree[index];
}
long long mult(int start, int end, int index, int L, int R){
    if(start > R || end < L)
        return 1;
    if(L <= start && end <= R)
        return tree[index];
    int mid = (start+end)/2;
    return (mult(start, mid, index*2, L, R)*mult(mid+1, end, index*2+1, L, R)) % SOSU;
}