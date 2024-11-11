#include <stdio.h>
#include <string.h>

int main(void){
    int N, p;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &p);
        for(int j = 0; j < p; j++){
            printf("=");
        }
        printf("\n");
    }
    return 0;
}