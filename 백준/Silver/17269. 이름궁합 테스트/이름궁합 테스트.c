#include <stdio.h>
int arr[5][26]= {
        {0},
        {'C', 'G', 'I', 'J', 'L', 'O', 'S', 'U', 'V', 'W', 'Z'},// 1
        {'B', 'D', 'N', 'P', 'Q', 'R', 'T', 'X', 'Y'},// 2
        {'A', 'F', 'H', 'K', 'M'},// = 3
        {'E'} // 4
    };
int findAlpha(char a){
    for(int i=1; i<5; i++){
        for(int j=0; arr[i][j]!=0; j++){
            if(arr[i][j] == a){
                return i;//획을 return 해준다
            }
        }
    }
}
int main(void){
    int N, M, t = 0, p = 0, c = 0, min;
    scanf("%d %d", &N, &M);
    int count[N + M + 1];
    if(N <= M){
        min = N;
    }
    else{
        min = M;
    }
    char A[N + 1], B[M + 1], new[N + M + 1];
    scanf("%s %s", A, B);
    for(int i = 0; i + 1 < min * 2; i = i + 2){
        new[i] = A[t];
        new[i + 1] = B[t];
        t++;
    }
    for(int i = min * 2; i < N + M; i++){
        if(N > M){
            new[i] = A[t];
            t++;
        }
        else{
            new[i] = B[t];
            t++;
        }
    }
    int r = N + M - 1;
    for(int i = 0; i < r; i++){
        count[i] = findAlpha(new[i]) + findAlpha(new[i + 1]);
    }
    r--;
    for(int i = 0; i < r && r != 1; i++){
        count[i] = count[i] + count[i + 1];
        if(count[i] >= 10){
            count[i] = count[i] - 10;
        }
        if(i + 1 == r){
            i = -1;
            r = r - 1;
        }
    }
    if(count[0] == 0){
        printf("%d%%", count[1]);
    }
    else{
        printf("%d%d%%", count[0], count[1]);
    }
    return 0;
}