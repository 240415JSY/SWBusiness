#include <stdio.h>

int main(void){
    int n, a, b;
    scanf("%d", &n);
    a = n / 4;
    for (b = 1; b<= a; b++){
        printf("long ");
    }
    printf("int");
    return 0;
}