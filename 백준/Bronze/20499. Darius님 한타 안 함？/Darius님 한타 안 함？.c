#include <stdio.h>
#include <string.h>

int K, D, A;
int main(void){
    scanf("%d/%d/%d", &K, &D, &A);
    if ((K + A < D) || D == 0){
        printf("hasu");
    }
    else{
        printf("gosu");
    }
    return 0;
}