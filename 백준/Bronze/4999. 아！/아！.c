#include <stdio.h>
#include <string.h>

char a[999], b[999];
int main(void){
    scanf("%s", a);
    scanf("%s", b);
    int al = strlen(a);
    int bl = strlen(b);
    if(al >= bl){
    printf("go");
    }
    else{
    printf("no");
    }
    return 0;
}