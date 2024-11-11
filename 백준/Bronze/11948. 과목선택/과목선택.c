#include <stdio.h>

int main(void){
    int s1[4], s2[2], min = 200, sum = 0, sum2;
    for(int i = 0; i < 4; i++){
        scanf("%d", &s1[i]);
        if(s1[i] <= min){
            min = s1[i];
        }
        sum = sum + s1[i];
    }
    sum = sum - min;
    for(int i = 0; i < 2; i++){
        scanf("%d", &s2[i]);
    }
    if(s2[0] <= s2[1]){
        sum2 = s2[1];
    }
    else{
        sum2 = s2[0];
    }
    printf("%d", sum + sum2);
    return 0;
}