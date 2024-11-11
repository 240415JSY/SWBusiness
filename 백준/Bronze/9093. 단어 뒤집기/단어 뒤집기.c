#include <stdio.h>
#include <string.h>

int main(void){
    int T;
    char s[1002];
    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; i++){
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        if (s[len - 1] == '\n'){
            s[len - 1] = '\0';
        }

        char *word = strtok(s, " ");
        while (word != NULL){
            int wordlen = strlen(word);
            for (int j = wordlen - 1; j >= 0; j--){
                printf("%c", word[j]);
            }
            word = strtok(NULL, " ");
            if (word != NULL){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}