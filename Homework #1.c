
#include <stdio.h>

int get_eps();

// 1234번 - 샘플 코드
int main(void){
    int method_1 = 3;
    printf("Method 1: %d\n", method_1);
    int method_2 = get_eps();
    printf("Method 2: %d\n", method_2);
    return 0;
}
/* Functions */
int get_eps(){
    int count=0;
    double eps = 1;
    while((double)1 + eps > (double)1){
        eps /= 2;
        count++;
    }
    return count;
}