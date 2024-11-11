#include <stdio.h>


int main(){
    char taebo[1001];
    int l=0, r=0, check=0;
    scanf("%s", taebo);
    while(taebo[check]!='0'){
        if(taebo[check]=='@'){
            l++;
        }
        check++;
    }
    while(taebo[check]!='\0'){
        if(taebo[check]=='@'){
            r++;
        }
        check++;
    }
    printf("%d %d", l, r);
    return 0;
}