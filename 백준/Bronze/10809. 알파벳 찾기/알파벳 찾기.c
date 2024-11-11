#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi 함수 포함

int length;
char S[100];
int a[26];

int main(void){
    for (int i = 0; i < 26; i++){
        a[i] = -1;
    }
    scanf("%s", S);
    length = strlen(S);
    for (int i = 0; i < length; i++){
        int position = S[i] - 'a'; //해당 문자의 위치 기록하기
        if (a[position] == -1){
            a[position] = i;
        }
    }
    for (int i = 0; i < 26; i++){
        printf("%d ", a[i]);
    }
}