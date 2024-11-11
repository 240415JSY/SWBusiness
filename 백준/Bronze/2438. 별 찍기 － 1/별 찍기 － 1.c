#include <stdio.h>

int main(void){
    int n, line, dot;
    scanf("%d", &n);
    for (line = 1; line <= n; line++){
        for (dot = 1; dot <= line; dot++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}