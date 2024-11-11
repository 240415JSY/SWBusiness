#include <stdio.h>
#include <string.h>

int main(void){
    char s[1001];
    int count = 0, n = 5;
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if(n == 0){
            n = 5;
        }
        if(s[i] == 'K' && n == 5){
            count++;
            n--;
        }
        else if(s[i] == 'O' && n == 4){
            count++;
            n--;
        }
        else if(s[i] == 'R' && n == 3){
            count++;
            n--;
        }
        else if(s[i] == 'E' && n == 2){
            count++;
            n--;
        }
        else if(s[i] == 'A' && n == 1){
            count++;
            n--;
        }
    }
    printf("%d", count);
    return 0;
}