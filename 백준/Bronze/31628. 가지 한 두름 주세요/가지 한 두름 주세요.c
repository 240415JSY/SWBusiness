#include <stdio.h>
#include <string.h>

int main(){
    char s[10][10][10]; //행 i, 열 j, 문자열 l;
    int line = 1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            scanf("%s", s[i][j]);//가지 색 인식
        }
    }

    for (int i = 0; i < 10; i++){
        line = 1;
        for (int j = 0; j < 10; j++){
            if (strcmp(s[i][j], s[i][0])){
                line = 0;
                break;
            }
        }
        if(line){
            printf("1");
            return 0;
        }
    }
    for (int i = 0; i < 10; i++){
        line = 1;
        for (int j = 0; j < 10; j++){
            if (strcmp(s[j][i], s[0][i])){
                line = 0;
                break;
            }
        }
        if(line){
            printf("1");
            return 0;
        }
    }
    printf("0");
}