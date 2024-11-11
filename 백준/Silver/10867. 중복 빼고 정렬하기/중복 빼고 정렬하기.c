#include <stdio.h>

int main(void) {
    int N, p = 1, t;
    scanf("%d", &N);
    int s[N + 1], a[2001];
    for(int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }
    a[0] = s[0];
    for(int i = 1; i < N; i++) {
        int c = 1;  // 여기서 c를 초기화해야 합니다.
        for(int j = 0; j < p; j++) {  // j를 0부터 p까지 돌려서 중복 체크
            if(s[i] == a[j]) {
                c = 0;
                break;
            }
        }
        if(c == 1) {
            a[p] = s[i];
            p++;
        }
    }
    for(int i = 0; i < p - 1; i++) {  // 정렬 범위 수정
        for(int j = 0; j < p - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for(int i = 0; i < p; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}