#include <stdio.h>

int main(void){
    int a, b, A, B;
    scanf("%d\n", &a);
    for (b = 1; b <= a; b++){
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", b, A + B);
    }
    return 0;
}