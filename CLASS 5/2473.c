
// 2473번 - 세 용액

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
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

/* Main */
int main(void){
    int num;
    scanf("%d",&num);

    long long potion[num];

    f(i,num)
        scanf("%lld",&potion[i]);
    qsort(potion, num, sizeof(long long), compare);
    int start = 0;
    int mid = 1;
    int end = num-1;
    long long min = 4000000000;
    int minA, minB, minC;
    while(mid < end){
        while(start < mid && mid < end){
            if(abs(potion[start] + potion[mid] + potion[end]) < min){
                min = abs(potion[start] + potion[mid] + potion[end]);
                minA = potion[start];
                minB = potion[mid];
                minC = potion[end];
            }
            if((abs(potion[start+1] + potion[mid] + potion[end]) > abs(potion[start] + potion[mid] + potion[end-1]) && (mid != end-1))  // end로 줄어들 용건이 충분하거나
            || ((mid == start+1) && abs(potion[start] + potion[mid] + potion[end-1]) < abs(potion[start] + potion[mid] + potion[end]))) // 더 이상 올라올 곳이 없고, 내려가는 게 나을 때
                end--;
            else
                start++;
        }
        start = 0;
        mid++;
        end = num-1;
    }
    printf("%d %d %d",minA, minB, minC);
    return 0;
}

/* Functions */