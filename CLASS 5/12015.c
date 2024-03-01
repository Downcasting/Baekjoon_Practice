
// 12015번 - 가장 긴 증가하는 부분 수열 2

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */

/* Function */
int binary(int* arr, int gab, int size);

/* Main */
int main(void){
    int num;
    scanf("%d",&num);
    int arr[num];
    int big[num];
    int max = 0;
    f(i,num){
        scanf("%d",&arr[i]);
        big[i] = 0;
    }
    int location;
    f(i,num){
        location = binary(big,arr[i],max);
        big[location] = arr[i];
        max = MAX(max,location+1);
        //printf("Stage %d - ",i+1);
        //f(j,num)
            //printf("%d ",big[j]);
        //printf("\n");
    }
    printf("%d\n",max);
    f(i,max)
        printf("%d ",big[i]);
    return 0;
}
/* Functions */
int binary(int* arr, int gab, int size){
    if(size == 0)
        return 0;
    int start = 0;
    int end = size-1;
    int mid = start;
    while(start <= end){
        if(start == end){
            if(gab > arr[start])
                return start+1;
            else
                return start;
        }
        mid = (start+end)/2;
        if(arr[mid] == gab){
            return mid;
        }
        else if(arr[mid] < gab){
            start = mid+1;
        }
        else
            end = mid - 1;
    }
    if(arr[mid] < gab && arr[mid+1] == 0)
        return mid+1;
    return mid;
}