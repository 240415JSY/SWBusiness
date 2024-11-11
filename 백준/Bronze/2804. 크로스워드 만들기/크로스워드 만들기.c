#include <stdio.h>
#include <string.h>

int main() {
    char A[31], B[31];
    scanf("%s %s", A, B);

    int lenA = strlen(A);
    int lenB = strlen(B);
    int crossA = -1, crossB = -1;

    // 교차점을 찾는 루프
    for (int i = 0; i < lenA; i++) {
        for (int j = 0; j < lenB; j++) {
            if (A[i] == B[j]) {
                crossA = i;
                crossB = j;
                break;
            }
        }
        if (crossA != -1) break; // 교차점을 찾으면 루프 종료
    }

    // 출력 부분
    for (int i = 0; i < lenB; i++) {
        for (int j = 0; j < lenA; j++) {
            if (i == crossB) {
                printf("%c", A[j]); // B의 교차점에 해당하는 A 출력
            } else if (j == crossA) {
                printf("%c", B[i]); // A의 교차점에 해당하는 B 출력
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}