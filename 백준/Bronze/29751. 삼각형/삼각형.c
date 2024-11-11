#include <stdio.h>
#include <string.h>

int main(void){
    int W, H;
    scanf("%d %d", &W, &H);
    double place = (double)W * H / 2;
    printf("%.1f", place);
    return 0;
}