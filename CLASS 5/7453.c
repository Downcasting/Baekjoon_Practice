
// 7453번 - 합이 0인 네 정수

/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define f(i,N) for(int i=0; i<N; i++)

/* Struct */

/* Global Var */
int* A;
int* B;
int* C;
int* D;
int* AB;
int* CD;

/* Function Declarations */
static int compare (const void* first, const void* second);


/* Main */
int main(void){
    int num;
    long long count = 0;
    scanf("%d",&num);
    A = (int*)malloc(num*sizeof(int));
    B = (int*)malloc(num*sizeof(int));
    C = (int*)malloc(num*sizeof(int));
    D = (int*)malloc(num*sizeof(int));

    AB = (int*)malloc(num*num*sizeof(int));
    CD = (int*)malloc(num*num*sizeof(int));

    f(i,num)
        scanf("%d %d %d %d",&A[i], &B[i], &C[i], &D[i]);

    int idx=0;
    f(i,num){
        f(j,num){
            AB[idx] = A[i] + B[j];
            CD[idx] = C[i] + D[j];
            idx++;
        }
    }


    qsort(AB, num*num, sizeof(int), compare);
    qsort(CD, num*num, sizeof(int), compare);
    
    int left = 0;
    int right = num*num - 1;
    while(left < num*num && right >= 0){
        if(AB[left] + CD[right] > 0)
            right--;
        else if(AB[left] + CD[right] < 0)
            left++;
        else{
            long long leftCount = 1;
            long long rightCount = 1;

            // AB 배열에서 동일한 값 개수 세기
            while (left + leftCount < num * num && AB[left + leftCount] == AB[left]) {
                leftCount++;
            }

            // CD 배열에서 동일한 값 개수 세기
            while (right - rightCount >= 0 && CD[right - rightCount] == CD[right]) {
                rightCount++;
            }

            count += leftCount * rightCount;
            left += leftCount;
            right -= rightCount;
        }
    }
    
    printf("%lld",count);
    free(A);
    free(B);
    free(C);
    free(D);
    free(AB);
    free(CD);
    return 0;
}

/* Functions */
static int compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
/* 이진 탐색

int left, right, target;
    int leftFind;
    int rightFind;
    f(i,num*num){
        leftFind = -1;
        rightFind = -1;
        left = 0;
        right = num*num-1;
        target = -AB[i];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (CD[mid] < target) {
                left = mid + 1;
            } else if (CD[mid] > target) {
                right = mid - 1;
            } else {
                leftFind = mid;
                right = mid - 1; // 계속해서 왼쪽 탐색
            }
        }

        left = 0;
        right = num * num - 1;

        // 오른쪽 끝 찾기
        while (left <= right) {
            int mid = (left + right) / 2;
            if (CD[mid] < target) {
                left = mid + 1;
            } else if (CD[mid] > target) {
                right = mid - 1;
            } else {
                rightFind = mid;
                left = mid + 1; // 계속해서 오른쪽 탐색
            }
        }
        if (leftFind != -1 && rightFind != -1) 
            count += (rightFind - leftFind + 1);
    }

*/