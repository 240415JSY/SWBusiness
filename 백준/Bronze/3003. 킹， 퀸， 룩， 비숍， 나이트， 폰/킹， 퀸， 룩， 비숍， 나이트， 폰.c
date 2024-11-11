#include <stdio.h>
#include <string.h>

int K, Q, R, B, KN, P;
int main(void){
    scanf("%d %d %d %d %d %d", &K, &Q, &R, &B, &KN, &P);
    printf("%d %d %d %d %d %d", 1-K, 1-Q, 2-R, 2-B, 2-KN, 8-P);
    return 0;
}