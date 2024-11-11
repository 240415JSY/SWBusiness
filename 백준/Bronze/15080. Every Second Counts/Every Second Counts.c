#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi 함수 포함

int main(void){
    int hh, mm, ss, hh2, mm2, ss2;
    scanf("%d : %d : %d", &hh, &mm, &ss);
    scanf("%d : %d : %d", &hh2, &mm2, &ss2);
    if ((hh2 * 3600 + mm2 * 60 + ss2) - (hh * 3600 + mm * 60 + ss)  < 0){
        printf("%d", ((hh2 + 24) * 3600 + mm2 * 60 + ss2) - (hh * 3600 + mm * 60 + ss));
    }
    else{
        printf("%d", (hh2 * 3600 + mm2 * 60 + ss2) - (hh * 3600 + mm * 60 + ss));
    }
    return 0;
}