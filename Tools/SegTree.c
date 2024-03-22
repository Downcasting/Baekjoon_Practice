long long makeTree(int start, int end, int index){
    if(start == end){
        tree[index] = arr[start];
        return arr[start];
    }
    int mid = (start+end)/2;
    tree[index] = (makeTree(start, mid, index*2) + makeTree(mid+1, end, index*2+1)) % SOSU;
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
    tree[index] = (update(start,mid,index*2,target,newData)+update(mid+1,end,index*2+1,target,newData));
    return tree[index];
}
long long sum(int start, int end, int index, int L, int R){
    if(start > R || end < L)
        return 0;
    if(L <= start && end <= R)
        return tree[index];
    int mid = (start+end)/2;
    return (sum(start, mid, index*2, L, R)+sum(mid+1, end, index*2+1, L, R));
}