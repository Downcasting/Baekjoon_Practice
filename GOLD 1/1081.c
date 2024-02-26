
// 1081번 - 합

#include <stdio.h>
#include <math.h>

void recursive(int input, int digit, long long* array){
    int numPow = (int)round(pow(10,digit));
    int currentNum = ((input - (input%numPow))/numPow) % 10;
    if((int) floor(log10(input)) > digit){
        array[0] += (input - input%(numPow*10)) / 10 - numPow;
        for(int i=1; i<10; i++)
            array[i] += (input - input%(numPow*10)) / 10;
    }
    for(int i=0; i<currentNum; i++)
        array[i] += (digit == (int) floor(log10(input)) && !i) ? 0 : numPow;
    array[currentNum] += 1 + floor(input % numPow);
    if(digit)
        recursive(input, digit-1, array);
    return;
}
int main(){
    int pages1, pages2;
    scanf("%d %d",&pages1, &pages2);
    long long num[10] = {0,};
    long long sum = 0;
    if(pages1 == 0 || pages1 == 1){
        //num[pages1] += 1;
    }
    else{
        int length1 = (int) floor(log10(pages1-1));
        recursive(pages1-1,length1,num);
    }
    for(int i=0; i<10; i++)
        num[i] *= -1;
    if(pages2 != 0){
        int length2 = (int) floor(log10(pages2));
        
        recursive(pages2,length2,num);
    }
    for(int i=1; i<10; i++)
       sum += num[i]*i;
    printf("%lld",sum);
    return 0;
}