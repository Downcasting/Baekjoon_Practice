#include <stdio.h>
#include <math.h>
void recursive(int input, int digit, int* array){
    int numPow = (int)round(pow(10,digit));
    int currentNum = ((input - (input%numPow))/numPow) % 10;
    if(floor(log10(input)) > digit){
        array[0] += (input - input%(numPow*10)) / 10 - numPow;
        for(int i=1; i<10; i++) array[i] += (input - input%(numPow*10)) / 10;
    }
    for(int i=0; i<currentNum; i++) array[i] += (digit == floor(log10(input)) && !i) ? 0 : numPow;
    array[currentNum] += 1 + floor(input % numPow);
    if(digit) recursive(input, digit-1, array);
    return;
}
int main(){
    int pages;
    scanf("%d",&pages);
    int length = floor(log10(pages));
    int num[10] = {0,};
    recursive(pages,length,num);
    for(int i=0; i<10; i++)
        printf("%d ",num[i]);
    return 0;
}