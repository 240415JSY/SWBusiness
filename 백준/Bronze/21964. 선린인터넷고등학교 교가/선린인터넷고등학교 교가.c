#include <stdio.h>
#include <string.h>

int main(void){
    int N;
    scanf("%d", &N);
    char S[N];
    scanf("%s", S);
    for(int i = N - 5; i < N; i++){
        printf("%c", S[i]);
    }
    return 0;
}