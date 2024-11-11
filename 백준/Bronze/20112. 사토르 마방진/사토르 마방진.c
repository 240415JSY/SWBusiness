#include <stdio.h>
#include <string.h>

char s[105][105];
int main(void){
    int line;
    scanf("%d", &line);
    for(int i=0; i<line; i++) scanf("%s", s[i]);
        int sator = 1;
        for (int p = 0; p < line; p++){
            for (int q = 0; q < line; q++){
                if(s[p][q]!=s[q][p]){
                    sator = 0;
                    break;
                }
            }
            if(sator==0) break;
        }
        if (sator==1) printf("YES");
        else printf("NO");
        return 0;
}