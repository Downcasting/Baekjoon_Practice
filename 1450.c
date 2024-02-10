#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
      

int main(void){
    int N, C;
    scanf("%d %d",&N, &C);
    int mid = N / 2;
    int* A = (int*) malloc(mid * sizeof(int));
    int* B = (int*) malloc((N - mid) * sizeof(int));
    int* modA = (int*) malloc((int)pow(2,mid) * sizeof(int));
    int* modB = (int*) malloc((int)pow(2,N-mid) * sizeof(int));

    int tempSum = 0;
    int tempCurr = 0;
    int tempLoc = 0;

    int volume = 0;

    int totalWay = 0;

    for(int i=0; i<mid; i++)
        scanf("%d",&A[i]);
    for(int i=0; i<N-mid; i++)
        scanf("%d",&B[i]);

    for(int i=0; i<(int)pow(2,mid); i++){
        tempSum = 0;
        tempLoc = 0;
        tempCurr = i;
        while(tempCurr){
            if(tempSum > 1000000000)
                break;
            if(tempCurr % 2)
                tempSum += A[tempLoc];
            tempCurr /= 2;
            tempLoc += 1;
        }
        modA[i] = tempSum;
    }
    for(int i=0; i<(int)pow(2,N-mid); i++){
        tempSum = 0;
        tempLoc = 0;
        tempCurr = i;
        while(tempCurr){
            if(tempSum > 1000000000)
                break;
            if(tempCurr % 2)
                tempSum += B[tempLoc];
            tempCurr /= 2;
            tempLoc += 1;
        }
        modB[i] = tempSum;
    }
    qsort(modA, (int)pow(2,mid), sizeof(int), compare);
    qsort(modB, (int)pow(2,N-mid), sizeof(int), compare);
    
    for(int i=0; i<(int)pow(2,mid); i++){
        volume = C - modA[i];
        if(volume < 0)
            continue;
        int left = 0, right = (int)pow(2,N-mid) - 1;
        int result = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            // 중간 값이 volume 이하인 경우
            if (modB[mid] <= volume) {
                result = mid + 1; // 현재까지의 개수를 누적
                left = mid + 1;   // 오른쪽 부분 탐색
            } else {
                right = mid - 1;  // 왼쪽 부분 탐색
            }
        }

        totalWay += result;
    }
    printf("%d",totalWay);
    free(A);
    free(B);
    free(modA);
    free(modB);
    return 0;
}   