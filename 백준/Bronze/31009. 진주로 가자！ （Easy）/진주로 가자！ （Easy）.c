#include <stdio.h>
#include <string.h>

int main(void){
    int price[1000], N, jinjuprice = 0, count = 0;
    char tour[1000][15];//저장해야 하는 투어의 수는 1000개, 각 투어의 이름은 최대 15글자

    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%s %d", tour[i], &price[i]);
        if (strcmp(tour[i], "jinju") == 0){//tour[i]를 하게되면 tour[0][0], tour[0][1]과 같은 방식으로 단어를 저장한다.
            jinjuprice = price[i];
        }
    }
    for (int i = 0; i < N; i++){
        if (price[i] > jinjuprice){
            count++;
        }
    }
    printf("%d\n%d", jinjuprice, count);
    return 0;
}