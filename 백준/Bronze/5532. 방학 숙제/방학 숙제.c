#include <stdio.h>

int main(void){
    int L, A, B, C, D, a_count, b_count;
    scanf("%d\n%d\n%d\n%d\n%d", &L, &A, &B, &C, &D);
    a_count = A / C;
    if(A % C != 0){
        a_count++;
    }
    b_count = B / D;
    if(B % D != 0){
        b_count++;
    }
    if(a_count >= b_count){
        printf("%d", L - a_count);
    }
    else{
        printf("%d", L - b_count);
    }
    return 0;
}