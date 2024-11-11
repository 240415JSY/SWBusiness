#include <stdio.h>
#include <string.h>
int i, p;
char s[101];
int main(void){
    gets(s);
    p = strlen(s);
    for (i=0; i<p; i++){
        if (s[i]<91){
            printf("%c", s[i]+32);
        }
        else{
            printf("%c", s[i]-32);
        }
    }
}