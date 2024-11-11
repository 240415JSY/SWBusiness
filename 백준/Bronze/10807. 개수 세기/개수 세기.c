#include <stdio.h>

int main(void){
    int N, i, v;
    int count = 0;
    int c[100];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &v);
    for (i = 0; i < N; i++){
        if (c[i] == v){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}