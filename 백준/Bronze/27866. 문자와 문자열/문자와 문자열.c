    #include <stdio.h>

    int main(void){
        int number;
        char s[1001];
        scanf("%s\n", s);
        scanf("%d", &number);
        printf("%c", s[number-1]);
        return 0;
    }