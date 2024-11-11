#include <stdio.h>
#include <string.h>

int main(void){
    int T;
    scanf("%d", &T);
    int tc[T];
    char r[T][20];
    for(int i = 0; i < T; i++){
        scanf("%d", &tc[i]);
        if(tc[i] > 4500){
            strcpy(r[i], "Round 1");
        }
        else if(tc[i] > 1000){
            strcpy(r[i], "Round 2");
        }
        else if(tc[i] > 25){
            strcpy(r[i], "Round 3");
        }
        else{
            strcpy(r[i], "World Finals");
        }
    }
    for(int i = 0; i < T; i++){
        printf("Case #%d: %s\n", i + 1, r[i]);
    }
    return 0;
}