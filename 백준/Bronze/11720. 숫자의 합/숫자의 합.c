#include <stdio.h>

    int main(void){
        int n, i;
        int sum=0;
        char s[101];
        scanf("%d\n %s", &n, s);
        for (i=0; i<n; i++){
            sum+=s[i]-'0';
        }
        printf("%d", sum);
        return 0;
    }
