#include <stdio.h>
#include <string.h>

int main(void){
    int T, i, l;
    char string[1001];
    scanf("%d", &T);
    for(i=0; i<T; i++){
        scanf("%s\n", string);
        l = strlen(string);
        printf("%c%c\n", string[0], string[l-1]);
    }
    return 0;

}