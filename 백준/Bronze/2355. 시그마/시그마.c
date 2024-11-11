#include <stdio.h>

int main(void){
    long long a, b, n, answer, sum = 0;
    scanf("%lld %lld", &a, &b);
    if(b >= a){
        n = b - a + 1;
        answer = n * (a + b) / 2;
    }
    else if(b < a){
        n = a - b + 1;
        answer = n * (a + b) / 2;
    }
    printf("%lld", answer);
    return 0;
}