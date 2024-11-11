#include <stdio.h>
#include <string.h>

int main(void){
    int S, T, D, F;
    scanf("%d %d %d", &S, &T, &D);
    printf("%d", D * T / (S * 2));
    return 0;
}