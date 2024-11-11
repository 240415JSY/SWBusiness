#include <stdio.h>

int main(void){
    int num[28];
    int num1[30] = {0};
    for (int i = 0; i < 28; i++){
        scanf("%d", &num[i]);
        num1[num[i] - 1] = 1;
    }
    for (int i = 0; i < 30; i++){
        if(num1[i] == 0){
            printf("%d\n", i + 1);
        }
    }
    return 0;
}