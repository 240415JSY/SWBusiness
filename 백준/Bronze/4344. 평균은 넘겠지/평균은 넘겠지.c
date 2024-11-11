#include <stdio.h>
#include <string.h>

int main(void){
    int C, N, high = 0, sum = 0;
    double average, answer;
    int score[1000];

    scanf("%d", &C);
    for(int i = 0; i < C; i++){
        scanf("%d", &N);
        for(int j = 0; j < N; j++){
            scanf("%d", &score[j]);
            sum = sum + score[j];
        }
        average = sum / N;
        for(int j = 0; j < N; j++){
            if(average < score[j]){
                high++;
            }
        }
        answer = (double)high * 100 / N;
        printf("%.3f%%\n", answer);
        sum = 0;
        average = 0;
        high = 0;
    }
    return 0;
}