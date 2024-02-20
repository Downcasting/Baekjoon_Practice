#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(i,k) for(int i=0; i<k; i++)
#define MAX(a,b) a>b?a:b

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

double recursive(int index, int bitmask);
double triangle(int a, int b, int c);

double** dp;
int* fences;
int N;
int main(void){
    scanf("%d",&N);
    fences = (int*) malloc(N*sizeof(int));
    dp = (double**) malloc(N*sizeof(double*));
    f(i,N){
        dp[i] = (double*) malloc((1<<N)*sizeof(double));
        scanf("%d",&fences[i]);
        f(j,1<<N)
            dp[i][j] = -1;
    }
    qsort(fences, N, sizeof(int), compare);
    double finalSize = recursive(0, 0);
    printf("%.10f",finalSize);
    return 0;
}
double recursive(int index, int bitmask){
    if(index == N || index > N/3+1)
        return 0;
    if(dp[index][bitmask] != -1)
        return dp[index][bitmask];
    double maxArea = recursive(index+1,bitmask);
    f(i,N){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(!(bitmask & ((1<<i)|(1<<j)|(1<<k))) && (fences[i]+fences[j] > fences[k])){
                    double area = triangle(fences[i],fences[j],fences[k]);
                    int newBitmask = bitmask | (1 << i) | (1 << j) | (1 << k);
                    maxArea = MAX(maxArea, area+recursive(index+1,newBitmask));
                }
            }
        }
    }
    dp[index][bitmask] = maxArea;
    return maxArea;
}
double triangle(int a, int b, int c){
    double S = (a+b+c) / (double)2;
    return sqrt(S*(S-(double)a)*(S-(double)b)*(S-(double)c));
}