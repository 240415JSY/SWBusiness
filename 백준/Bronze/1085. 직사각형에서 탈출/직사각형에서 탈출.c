#include <stdio.h>

int main(void){
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int num1 = w - x;
    int num2 = h - y;
    int answer = x;
    if (y <= answer){
        answer = y;
    }
    if (num1 <= answer){
        answer = num1;
    }
    if (num2 <= answer){
        answer = num2;
    }
    printf("%d", answer);
    return 0;
}