#include <stdio.h>
#include <math.h>


int main(void){
    long long Place;
    double length;
    scanf("%lld", &Place);
    length = sqrt((double)(Place));
    printf("%.6f", length * 4);
    return 0;
}