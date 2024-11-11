#include <stdio.h>
#include <string.h>

int a, b, c, d, e, f, g, h, i, 
    j, k, l, m, n, o, p, q, r,
    s, t, u, v, w, x, y, z;
int num, length;
char string[101];
int arr[26] = {0,};
int main(void){
    gets(string);
    length = strlen(string);
    for (num = 0; num<=length; num++){
        for(i = 0; i<26; i++){
            if (string[num] == i + 'a'){
               arr[i] += 1;
            }
        }
    }
    for (p = 0; p < 26; p++){
        printf("%d ", arr[p]);
    }
}