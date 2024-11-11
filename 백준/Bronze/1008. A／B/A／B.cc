#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	double A,B;
	scanf("%lf %lf", &A, &B);
	printf("%.9lf", A / B);
	return 0;
}