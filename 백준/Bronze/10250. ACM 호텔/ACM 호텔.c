#include <stdio.h>

int main(void){
    int i, t, h, w, n, first, last;
    scanf("%d", &t);
    for(i=1; i<= t; i++){
        scanf("%d %d %d", &h, &w, &n);
        if (n % h == 0){
            first = h;
        }
        else{
            first = n % h;
                }
        last = ((n-1)/h)+1;
        if (last<=9){
         printf("%d0%d\n", first, last);
        }
        else{
            printf("%d%d\n", first, last);
        }
    }
}