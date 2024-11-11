#include <stdio.h>

int main(void){
    long long a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    long long answer1 = (long long)a * b / c;
    long long answer2 = (long long)a * c / b;
    if(answer1 > answer2){
        printf("%lld", answer1);
    }
    else{
        printf("%.lld", answer2);
    }
    return 0;
}