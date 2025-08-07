#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    bool check[1000001] = {1, 1, };

    int m, n;
    cin >> m >> n;
    for(int i = 2; i * i <= n; i++){
        if(check[i]){
            continue;
        }
        for(int j = i * i; j <= n; j = j + i){
            check[j] = 1;
        }
    }
    for(int i = m; i <= n; i++){
        if(!check[i]){
            cout << i << "\n";
        }
    }
    return 0;
}