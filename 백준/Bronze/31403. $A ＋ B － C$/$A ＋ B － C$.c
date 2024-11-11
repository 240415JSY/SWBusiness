#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi 함수 포함

int A, B, C;
char sA[1000], sB[1000], AB[2000];
int main(void){
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    printf("%d\n", A + B - C);
    sprintf(AB, "%d%d", A, B);/*정수를 문자열로 바꾸는 함수 sprintf. "%d%d"의 형식으로 작성하고
    A와 B에 3, 4를 입력하면 문자열 '34'가 된다.*/
    int iAB = atoi(AB);/*문자열을 정수로 바꾸는 함수 atoi. '34'는 정수 34가 된다.*/
    printf("%d", iAB - C);
    return 0;
    }