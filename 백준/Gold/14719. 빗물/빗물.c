#include <stdio.h>

int main(void){
    int H, W, left_max = 0, right_max = 0, min, rain, sum = 0;
    scanf("%d %d", &H, &W);
    int s[W];
    for(int i = 0; i < W; i++){
        scanf("%d", &s[i]);
    }
    for(int i = 1; i < W - 1; i++){
        for(int j = i - 1; j >= 0; j--){
            if(s[j] >= left_max){
                left_max = s[j];
            }
        }
        for(int t = i + 1; t < W; t++){
            if(s[t] >= right_max){
                right_max = s[t];
            }
        }
        if(left_max >= right_max){
            min = right_max;
        }
        else{
            min = left_max;
        }
        rain = min - s[i];
        if(rain < 0){
            rain = 0;
        }
        sum = sum + rain;
        left_max = 0;
        right_max = 0;
    }
    printf("%d", sum);
}