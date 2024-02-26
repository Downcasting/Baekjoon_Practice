
// 1517번 - 버블 소트

#include <stdio.h>
#include <stdlib.h>

long swapCount = 0;
int* tempArr;
void merge(int* arr, int start, int mid, int end){
    int i = start;
    int s = start;
    int m = mid + 1;
    while(s <= mid && m <= end){
        if(arr[s] <= arr[m])
            tempArr[i++] = arr[s++];
        else{
            swapCount += m-i;
            tempArr[i++] = arr[m++];
        }
    }
    if(s > mid){
        for(int a=m; a<=end; a++)
            tempArr[i++] = arr[a];
    }
    else{
        for(int a=s; a<=mid; a++)
            tempArr[i++] = arr[a];
    }
    for(int a=start; a<=end; a++)
        arr[a] = tempArr[a];

}
void mergeSort(int* arr, int start, int end){
    if(start < end){
        mergeSort(arr, start, (start+end)/2);
        mergeSort(arr, (start+end)/2 + 1,end);
        merge(arr, start,(start+end)/2, end);
    }
}

int main(void)
{
    int num;
    scanf("%d",&num);
    int* numArr = (int*)malloc(sizeof(int)*num);
    tempArr = (int*)malloc(sizeof(int)*num);
    for (int i = 0; i < num; i++)
        scanf("%d",&numArr[i]);
    mergeSort(numArr,0,num-1);
    printf("%ld",swapCount);
    free(numArr);
    free(tempArr);
    return 0;
}