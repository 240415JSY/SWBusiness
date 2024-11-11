#include <stdio.h>

int main(void){
    int N, M, box[1000], book[1000], storage1 = 0, storage2 = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &box[i]);
        storage1 = storage1 + box[i];
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &book[i]);
        storage2 = storage2 + book[i];
    }
    int answer = storage1 - storage2;
    printf("%d", answer);
    return 0;
}