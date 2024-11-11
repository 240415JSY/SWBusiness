#include <stdio.h>

int main(void){
    int receipt_p, receipt_n, line, p, n;
    int sum = 0;
    scanf("%d\n %d", &receipt_p, &receipt_n);
    for (line = 1; line <= receipt_n; line++){
        scanf("%d %d", &p, &n);
        sum = sum + (p * n);
    }
    (sum == receipt_p) ? printf("Yes") : printf("No");
    return 0;
}