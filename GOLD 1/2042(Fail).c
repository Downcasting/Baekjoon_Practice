#include <stdio.h>
#include <math.h>
#include <limits.h>

#define LMAX LLONG_MAX
#define LMIN LLONG_MIN

int main(void){
    long long N, M, K;
    scanf("%lld %lld %lld",&N, &M, &K);

    long long blockCount = (long long) sqrt(N);
    long long blockSize = blockCount;
    if(blockCount*blockSize < N)
        blockCount++;
    long long arr[N];
    long long sumArr[blockCount];
    long long sumCarryArr[blockCount]; // 여기의 1 = -LLMIN

    long long dap[K];
    long long answer = 0;

    for(long long i=0; i<N; i++)
        scanf("%lld",&arr[i]);
    for(long long i=0; i<blockCount; i++){
        sumArr[i] = 0;
        sumCarryArr[i] = 0;
    }

    long long aa, bb;
    for(long long i=0; i<blockCount; i++){
        for(long long j=0; j<blockSize; j++){
            if(i*blockSize + j < N){ // 아직 끝에 다다르지 않음
                aa = sumArr[i];
                bb = arr[i*blockSize + j];
                if(bb > 0 && aa > LMAX - bb){
                    // OVERFLOW
                    sumArr[i] -= LMAX;
                    sumCarryArr[i] += 1;
                }
                if(bb < 0 && aa < LMIN - bb){
                    // UNDERFLOW
                    sumArr[i] += LMAX;
                    sumCarryArr[i] -= 1;
                }
                sumArr[i] += arr[i*blockSize + j];
            }
        }
    }
    long long a, b, c;
    long long diff; // = c - arr[b-1] (기존에서의 변화값)
    long long sum, startBlock, endBlock;
    for(long long ii=0; ii<M+K; ii++){
        scanf("%lld %lld %lld",&a,&b,&c);
        switch(a){
            case 1: // 바꾸기
                if(arr[b-1] > 0 && c < LMIN + arr[b-1]){
                    // (-) - (+) => 양수 (UNDERFLOW)
                    arr[b-1] -= LMAX;
                    sumCarryArr[(b-1)/blockSize] += 1;
                }
                if(arr[b-1] < 0 && c < LMAX + arr[b-1]){
                    // (+) - (-) => 음수 (OVERFLOW)
                    arr[b-1] += LMAX;
                    sumCarryArr[(b-1)/blockSize] -= 1;
                }
                diff = c - arr[b-1];
                arr[b-1] = c;
                if(diff > 0 && sumArr[(b-1)/blockSize] > LMAX - diff){
                    // OVERFLOW
                    sumArr[(b-1)/blockSize] -= LMAX;
                    sumCarryArr[(b-1)/blockSize] += 1;
                }
                if(diff < 0 && sumArr[(b-1)/blockSize] < LMIN - diff){
                    // UNDERFLOW
                    sumArr[(b-1)/blockSize] += LMAX;
                    sumCarryArr[(b-1)/blockSize] -= 1;
                }
                sumArr[(b-1)/blockSize] += diff;
                break;
            case 2: // 더하기
                sum = 0;
                startBlock = (long long) ceil((double)(b-1) / (double)blockSize);
                endBlock = c / blockSize - 1;
                for(long long i= b-1; i < startBlock*blockSize && i <= (c-1); i++){ // Overflow 예방이 필요함
                    if(sum > 0 && arr[i] > LMAX - sum){
                        // OVERFLOW
                        sum -= LMAX;
                        sumCarryArr[i / blockSize] += 1;
                    }
                    if(sum < 0 && arr[i] < LMIN - sum){
                        // UNDERFLOW
                        sum += LMAX;
                        sumCarryArr[i / blockSize] -= 1;
                    }
                    sum += arr[i];
                }
                for(long long i=startBlock; i <= endBlock; i++){
                    if(sum > 0 && sumArr[i] > LMAX - sum){
                        // OVERFLOW
                        sum -= LMAX;
                        sumCarryArr[i / blockSize] += 1;
                    }
                    if(sum < 0 && sumArr[i] < LMIN - sum){
                        // UNDERFLOW
                        sum += LMAX;
                        sumCarryArr[i / blockSize] -= 1;
                    }
                    sum += sumArr[i];
                }
                for(long long i=(endBlock+1)*blockSize; i <= (c-1); i++){
                    if(sum > 0 && arr[i] > LMAX - sum){
                        // OVERFLOW
                        sum -= LMAX;
                        sumCarryArr[i / blockSize] += 1;
                    }
                    if(sum < 0 && arr[i] < LMIN - sum){
                        // UNDERFLOW
                        sum += LMAX;
                        sumCarryArr[i / blockSize] -= 1;
                    }
                    sum += arr[i];
                }
                // 값 출력
                dap[answer++] = sum;
                break;
            default:
            printf("What\n");
        }
    }
    for(long long i=0; i<answer; i++)
        printf("%lld\n",dap[i]);
    return 0;
}