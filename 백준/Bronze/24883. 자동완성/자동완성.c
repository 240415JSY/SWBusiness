#include <stdio.h>
#include <string.h>

int c;
int main(void){
    scanf("%c", &c);
    if(c == 'N' || c == 'n'){
        printf("Naver D2");
    }
    else{
        printf("Naver Whale");
    }
    return 0;
}