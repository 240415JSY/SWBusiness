#include <stdio.h>

int main(void){
    int s[5], sum = 0, average;
    for(int i = 0; i < 5; i++){
        scanf("%d", &s[i]);
        if(s[i] < 40){
            s[i] = 40;
        }
        sum = sum + s[i];
    }
    average = sum / 5;
    printf("%d", average);
}