#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N, k;
    scanf("%d %d", &N, &k);
    long long start = 1;
    long long end = k;
    long long mid = 1;
    long long count = 0;

    while (start <= end) {
        mid = (start+end) / 2;
        count = 0;

        for (int i = 1; i <= N; i++) {
            count += MIN(mid / i, N);
        }

        if (count >= k)
            end = mid - 1;
        else
            start = mid + 1;
    }

    printf("%lld", start);
    return 0;
}
