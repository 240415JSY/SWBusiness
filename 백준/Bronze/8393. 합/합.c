#include <stdio.h>
int main(void){
    int n, m;
    int p = 0;
    scanf("%d", &n);
    for (m = 1; m <= n; m++){
        p = m + p;
    }
    printf("%d", p);
}