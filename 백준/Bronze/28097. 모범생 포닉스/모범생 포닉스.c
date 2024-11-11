#include <stdio.h>
#include <string.h>

int main(void){
    int N, M;
    int sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &M);
        sum = sum + M;
    }
    printf("%d %d", (sum + 8 * (N-1)) / 24, (sum + 8 * (N-1)) % 24);
    return 0;
}