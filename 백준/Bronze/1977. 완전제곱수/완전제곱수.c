#include <stdio.h>

int main(void){
    int M, N, min = 10000000;
    int sum = 0, found = 0;
    scanf("%d\n%d", &M, &N);
    int rootM = sqrt(M);
    int rootN = sqrt(N);
    for(int i = rootM; i <= rootN; i++){
        if ((M <= i * i) && (i * i <= N)){
            if (min > i * i){
                min = i * i;
            }
            sum = sum + i * i;
            found = 1;
        }
    }
    if(found == 1){
        printf("%d\n%d", sum, min);
    }
    else{
        printf("-1");
    }
    return 0;
}