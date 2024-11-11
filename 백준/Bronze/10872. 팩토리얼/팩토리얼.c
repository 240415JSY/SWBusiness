#include <stdio.h>

int main(void){
    int x, i;
    int answer=1;
    scanf("%d", &x);
    for (i=1; i<=x; i++){
        answer=answer*i;
    }
    printf("%d", answer);

    return 0;
}