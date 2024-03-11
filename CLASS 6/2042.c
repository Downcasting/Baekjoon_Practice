

// 2042번 - 구간 합 구하기

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(i,N) for(int i=0; i<N; i++)

long long* arr;
long long* tree;
int N, M, K;

long long makeTree(int start, int end, int index);
void update(int start, int end, int index, int target, long long diff);
long long sum(int start, int end, int index, int L, int R);

int main(void){

    scanf("%d %d %d",&N, &M, &K);
    arr = (long long*)malloc(N*sizeof(long long));
    tree = (long long*)malloc(N*4*sizeof(long long));
    f(i,N)
        scanf("%lld",&arr[i]);
    makeTree(0, N-1, 1);
    int a, b;
    long long c;
    int answer = 0;
    long long dap[K];
    f(i,M+K){
        scanf("%d %d %lld",&a ,&b, &c);
        if(a == 1){
            update(0, N-1, 1, b-1, c - arr[b-1]);
            arr[b-1] = c;
        }
        else if(a == 2){
            dap[answer++] = sum(0, N-1, 1, b-1, c-1);
        }
        else
            printf("asdf\n");
    }
    f(i,K)
        printf("%lld\n",dap[i]);
    makeTree(0, N-1, 1);
    return 0;
}
long long makeTree(int start, int end, int index){
    if(start == end){
        tree[index] = arr[start];
        return arr[start];
    }
    int mid = (start+end)/2;
    tree[index] = makeTree(start, mid, index*2) + makeTree(mid+1, end, index*2+1);
    return tree[index];
}
void update(int start, int end, int index, int target, long long diff){
    if(start > target || end < target)
        return;
    tree[index] += diff;
    if(start == end)
        return;
    int mid = (start+end)/2;
    update(start,mid,index*2,target,diff);
    update(mid+1,end,index*2+1,target,diff);
    return;
}
long long sum(int start, int end, int index, int L, int R){
    if(start > R || end < L)
        return 0;
    if(L <= start && end <= R)
        return tree[index];
    int mid = (start+end)/2;
    return sum(start, mid, index*2, L, R) + sum(mid+1, end, index*2+1, L, R);
}