#include <stdio.h>

int main(void){
    int A, B, C, N;
    scanf("%d %d %d %d", &A, &B, &C, &N);
    for (int i = 0; i <= N / A; i++) {
        for (int j = 0; j <= N / B; j++) {
            int remaining = N - (i * A + j * B);
            if (remaining >= 0 && remaining % C == 0) {
                printf("1");
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}