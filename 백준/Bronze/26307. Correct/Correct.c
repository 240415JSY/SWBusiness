#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi 함수 포함

int main(void){
    int HH, MM;
    scanf("%d %d", &HH, &MM);
    printf("%d", (HH * 60 + MM) - 540);
    return 0;
}