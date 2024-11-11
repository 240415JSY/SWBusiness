#include <stdio.h>

int main(void){
    int N, M, hmax = 0, vmax = 0;
    scanf("%d %d", &N, &M);
    int helmet[N], vest[M];
    for(int i = 0; i < N; i++){
        scanf("%d", &helmet[i]);
        if(helmet[i] >= hmax){
            hmax = helmet[i];
        }
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &vest[i]);
        if(vest[i] >= vmax){
            vmax = vest[i];
        }
    }
    printf("%d", hmax + vmax);
    return 0;
}