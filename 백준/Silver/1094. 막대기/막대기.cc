#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int x, count = 0;
    cin >> x;

    while(x > 0){
        if(x & 1){
            count++;
        }
        x >>= 1;
    }

    cout << count << '\n';
    return 0;
}