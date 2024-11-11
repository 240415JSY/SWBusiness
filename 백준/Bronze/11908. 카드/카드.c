#include <stdio.h>

int main(void){
    int N, card[2222], max = 0, sum = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &card[i]);
        if(card[i] >= max){
            max = card[i];
        }
        sum = sum + card[i];
    }
    int answer = sum - max;
    printf("%d", answer);
    return 0;
}