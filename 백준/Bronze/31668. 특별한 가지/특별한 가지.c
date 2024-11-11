#include <stdio.h>

int main(void){
    int N, M, K;
    scanf("%d\n%d\n%d", &N, &M, &K);
    int answer = M * K / N;
    printf("%d", answer);
    return 0;
}