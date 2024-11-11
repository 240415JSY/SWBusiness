#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a, i, twin;
int sum = 0;
int triple = 0;
int main(void) {
	scanf("%d", &a);
	for (i = 1; i <= a; i++) {
		sum += i;
	}
	printf("%d\n", sum);
	twin = sum * sum;
	printf("%d\n", twin);
	for (i = 1; i <= a; i++) {
		triple += i*i*i;
	}
	printf("%d\n", triple);
}