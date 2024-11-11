#include <stdio.h>

int main(void){
    int L, P;
    int s[5], a[5];
    scanf("%d %d", &L, &P);
    for(int i = 0; i < 5; i++){
        scanf("%d", &s[i]);
        a[i] = s[i] - (L * P);
    }
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}