
#include <stdio.h>
#include "nr.h"
#include "machar.h"

int get_eps_float();
int get_eps_double();

using namespace std;

// 1234번 - 샘플 코드
int main(void){
    Machar machar;
    machar.report();
    int method_1 = 3;
    printf("Method 1: %d\n", method_1);
    int method_2_float = get_eps_float();
    int method_2_double = get_eps_double();
    printf("Method 2: %d (float), %d (double)\n", method_2_float, method_2_double);
    return 0;
    return 0;
}
/* Functions */
int get_eps_float(){
    int count=0; 
    while(1.0f + eps > 1.0f){
        eps /= 2.0f;
        count++;
    }
    return count;
}
int get_eps_double(){
    int count=0;
    double eps = 1.0;
    while(1.0 + eps > 1.0){
        eps /= 2.0;
        count++;
    }
    return count;
}