#include <stdio.h>
#include <string.h>

int main(void){
    int N, a;
    int min = 10000000;
    int max = -1000000;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        if (a > max){
            max = a;
        }
        if(a < min){
            min = a;
        }
    }
    printf("%d %d", min, max);
    return 0;
}