int main(void){
    int T, R;
    char S[20];
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %s", &R, S);
        int length = strlen(S);
        for(int number = 0; number < length; number++){
            for(int j = 0; j < R; j++){
                printf("%c", S[number]);
            }
        }
        printf("\n");
    }
    return 0;
}