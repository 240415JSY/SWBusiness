#include <stdio.h>
#include <string.h>

int main(void){
    char str[1000000], c = 'A';
    int count[26] = {0};
    int found = 0, N = 0, num;
    
    scanf("%s", str);
    while(str[N]){
        if(islower(str[N])){
            str[N] = toupper(str[N]);
        }
        N++;
    }
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int num = str[i] - 'A';
        count[num]++;
    }
    
    num = count[0];

    for(int i = 1; i < 26; i++){
        if(num <= count[i]){
            num = count[i];
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if((i != j) && (count[i] != 0) && (count[i] == num && count[j] == num)){
                found = 1;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(found == 1){
            printf("?");
            break;
        }
        if(count[i] == num){
            printf("%c", i + 'A');
        }
    }
    return 0;
}