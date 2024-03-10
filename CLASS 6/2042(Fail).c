

// 2042번 - 구간 합 구하기

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define LMAX LLONG_MAX
#define LMIN LLONG_MIN

int main(void){
    int N, M, K;
    scanf("%d %d %d",&N, &M, &K);

    int blockCount = (int) sqrt(N); // 배열을 몇 개의 블록으로 나눌 지
    int blockSize = blockCount;           // 각 블록의 사이즈는 몇으로 할 건지
    while(blockCount*blockSize < N)                // 만약 조금 모자라면 개수 +1 +1 +1...
        blockCount++;

    long long arr[N];
    long long sumArr[blockCount];
    int sumCarryArr[blockCount]; // 여기의 1 = 2^63

    long long dap[K];
    long long answer = 0;

    for(int i=0; i<N; i++)
        scanf("%lld",&arr[i]);
    for(int i=0; i<blockCount; i++){
        sumArr[i] = 0;
        sumCarryArr[i] = 0;
    }
    long long aa, bb;
    for(int ind=0; ind<N; ind++){
        int i = ind / blockSize;
        int j = ind % blockSize;
        aa = sumArr[i];
        bb = arr[ind];
        if((bb < 0 && aa < LMIN - bb) || (bb > 0 && aa > LMAX - bb)){
            // 오버플로우 또는 언더플로우
            // 부호 검사 순서 제대로!!!!
            sumCarryArr[i] += aa > 0 ? 1 : -1;
            sumArr[i] = sumArr[i] ^ (1ULL << 63);
        }
        sumArr[i] += arr[ind];
        
    }

    int a, b;
    long long c, diff, sum;
    int startBlock, endBlock, sumCarry;
    for(int ii=0; ii<M+K; ii++){
        scanf("%d %d %lld",&a,&b,&c);
        switch(a){
            case 1: // 바꾸기
                // 일단 diff를 구하고
                if((arr[b-1] > 0 && c < LMIN + arr[b-1]) || (arr[b-1] < 0 && c < LMAX + arr[b-1])){
                    // diff의 오버(언더)플로우 감지
                    sumCarryArr[(b-1)/blockSize] += arr[b-1] < 0 ? 1 : -1;
                    arr[b-1] = arr[b-1] ^ (1ULL << 63);
                }
                diff = c - arr[b-1];
                arr[b-1] = c;

                // 그리고 그 diff를 sumArr에 대입하기
                if((diff > 0 && sumArr[(b-1)/blockSize] > LMAX - diff) || (diff < 0 && sumArr[(b-1)/blockSize] < LMIN - diff)){
                    // diff 합의 오버(언더플로우)
                    sumCarryArr[(b-1)/blockSize] += diff > 0 ? 1 : -1;
                    sumArr[(b-1)/blockSize] = sumArr[(b-1)/blockSize] ^ (1ULL << 63);
                }
                sumArr[(b-1)/blockSize] += diff;
                break;
            case 2: // 더하기
                sum = 0;
                sumCarry = 0;
                startBlock = (int) ceil((double)(b-1) / (double)blockSize);
                endBlock = c / blockSize - 1;
                for(int i= b-1; i < startBlock*blockSize && i <= (c-1); i++){ // Overflow 예방이 필요함
                    if((sum > 0 && arr[i] > LMAX - sum) || (sum < 0 && arr[i] < LMIN - sum)){
                        sumCarry += sum > 0 ? 1 : -1;
                        sum = sum ^ (1ULL << 63);
                    }
                    sum += arr[i];
                }
                for(int i=startBlock; i <= endBlock; i++){
                    if((sum > 0 && sumArr[i] > LMAX - sum) || (sum < 0 && sumArr[i] < LMIN - sum)){
                        sumCarry += sum > 0 ? 1 : -1;
                        sum = sum ^ (1ULL << 63);
                    }
                    sum += sumArr[i];
                    sumCarry += sumCarryArr[i];
                }
                for(int i=(endBlock+1)*blockSize; i <= (c-1); i++){
                    if((sum > 0 && arr[i] > LMAX - sum) || (sum < 0 && arr[i] < LMIN - sum)){
                        sumCarry += sum > 0 ? 1 : -1;
                        sum = sum ^ (1ULL << 63);
                    }
                    sum += arr[i];
                }
                if(sumCarry != 0)
                    sum = sum ^ (1ULL << 63);
                // 값 출력
                dap[answer++] = sum;
                break;
            default:
            printf("What\n");
        }
    }
    for(int i=0; i<answer; i++)
        printf("%lld\n",dap[i]);
    return 0;
}