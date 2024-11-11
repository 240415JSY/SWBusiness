#include <stdio.h>

int main(void){
    int N, K, A, B, sum;
    scanf("%d %d", &N, &K);
    sum = K;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &A, &B);
        sum = sum + A - B;
    }
    printf("비와이");
    return 0;
}