
#include <stdio.h>

int get_eps_float();
int get_eps_double();

// 1234번 - 샘플 코드
int main(void){
    int method_1 = 3;
    printf("Method 1: %d\n", method_1);
    int method_2_float = get_eps_float();
    int method_2_double = get_eps_double();
    printf("Method 2: %d(float), %d(double)\n", method_2_float, method_2_double);
    return 0;
}
/* Functions */
int get_eps_float(){
    int count=0;
    float eps = 1;
    while((float)1 + eps > (float)1){
        eps /= 2;
        count++;
    }
    return count;
}
int get_eps_double(){
    int count=0;
    double eps = 1;
    while((double)1 + eps > (double)1){
        eps /= 2;
        count++;
    }
    return count;
}