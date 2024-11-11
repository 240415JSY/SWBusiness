#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi 함수 포함

int numbers[10];
int others[41];
int count = 0;

int main(void){
    for (int i = 0; i < 10; i++){
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 10; i++){
        int other = numbers[i]%42;
        if(others[other] == 0){
            others[other] = 1;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}