#include <stdio.h>
#include <string.h>

int main(void){
    int A, B;
    scanf("%d", &B);
    A = B - (B / 11);
    printf("%d", A);
    return 0;
}