#include <stdio.h>

int main() {
    long long K, N;
    scanf("%lld %lld", &K, &N);

    if (N == 1) {
        printf("-1\n");
    } else {
        long long X = (K * N + (N - 2)) / (N - 1); // 올림 연산을 직접 구현
        printf("%lld\n", X);
    }

    return 0;
}
