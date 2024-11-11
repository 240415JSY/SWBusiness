#include <stdio.h>
#include <string.h>

int main(void){
    int V, A = 0, B = 0;
    scanf("%d", &V);
    char win[V];
    scanf("%s", win);
    for(int i = 0; i < V; i++){
        if(win[i] == 'A'){
            A++;
        }
        else{
            B++;
        }
    }
    if(A > B){
        printf("A");
    }
    else if(B > A){
        printf("B");
    }
    else{
        printf("Tie");
    }
    return 0;
}