#include <stdio.h>

int main(void){
    int n, i, line;
    int sum=0;
    int s[9]={0};
    for(i=0; i<9; i++){
        scanf("%d", &n);
        s[i]=n; 
        if(s[i]>sum){
            sum = s[i];
            line = i+1;
        }
    }
    printf("%d\n%d", sum, line);
}