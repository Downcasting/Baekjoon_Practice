#include <stdio.h>
#include <math.h>
#include <limits.h>

#define LMAX LLONG_MAX
#define LMIN LLONG_MIN

int main(void){
    int N, M, K;
    scanf("%d %d %d",&N, &M, &K);

    int blockCount = (int) sqrt(N);
    int blockSize = blockCount;
    if(blockCount*blockSize < N)
        blockCount++;
    long long arr[N];
    long long sumArr[blockCount];
    int sumCarryArr[blockCount]; // 여기의 1 = -LLMIN

    for(int i=0; i<N; i++)
        scanf("%lld",&arr[i]);
    for(int i=0; i<blockCount; i++){
        sumArr[i] = 0;
        sumCarryArr[i] = 0;
    }

    long long aa, bb;
    for(int i=0; i<blockCount; i++){
        for(int j=0; j<blockSize; j++){
            if(i*blockSize + j < N){ // 아직 끝에 다다르지 않음
                aa = sumArr[i];
                bb = arr[i*blockSize + j];
                if(bb > 0 && aa > LMAX - bb){
                    // OVERFLOW
                    sumArr[i] += LMIN;
                    sumCarryArr[i] += 1;
                }
                if(bb < 0 && aa < LMIN - bb){
                    // UNDERFLOW
                    sumArr[i] -= LMIN;
                    sumCarryArr[i] -= 1;
                }
                sumCarryArr[i] += arr[i*blockSize + j];
            }
        }
    }
    int a, b, c;
    int diff; // = c - arr[b-1] (기존에서의 변화값)
    for(int i=0; i<M+K; i++){
        scanf("%d %d %d",&a,&b,&c);
        switch(a){
            case 1: // 바꾸기
                if(arr[b-1] > 0 && c < LMIN + arr[b-1]){
                    // (-) - (+) => 양수 (UNDERFLOW)
                    arr[b-1] -= LMIN;
                    sumCarryArr[(b-1)/blockSize] -= 1;
                }
                if(arr[b-1] < 0 && c < LMAX + arr[b-1]){
                    // (+) - (-) => 음수 (OVERFLOW)
                    arr[b-1] += LMIN;
                    sumCarryArr[(b-1)/blockSize] += 1;
                }
                diff = c - arr[b-1];
                arr[b-1] = c;
                if(diff > 0 && sumArr[(b-1)/blockSize] > LMAX - diff){
                    // OVERFLOW
                    sumArr[(b-1)/blockSize] += LMIN;
                    sumCarryArr[(b-1)/blockSize] += 1;
                }
                if(diff < 0 && sumArr[(b-1)/blockSize] < LMIN - diff){
                    // UNDERFLOW
                    sumArr[(b-1)/blockSize] -= LMIN;
                    sumCarryArr[(b-1)/blockSize] -= 1;
                }
                sumArr[(b-1)/blockSize] += diff;
                break;
            case 2: // 더하기
                int sum = 0;
                int startBlock = (int) ceil(b / blockSize - 1);
                int endBlock = (c / blockSize - 1);
                for(int i= b-1; i < startBlock*blockSize; i++){
                    sum += arr[i];
                }
                for(int i=startBlock; i<endBlock; i++){

                }
                // 값 출력
                break;
            default:
            printf("What\n");
        }
    }

    return 0;
}