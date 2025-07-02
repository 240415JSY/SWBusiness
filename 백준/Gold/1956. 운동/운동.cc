#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int v, e, a, b, c;
vector<vector<int>> g(401, vector<int> (401, 10000000));

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        g[a][b] = c;
    }

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            for(int k = 1; k <= v; k++){
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }

    int ans = 10000000;
    for(int i = 1; i <= v; i++){
        if(g[i][i] != ans){
            ans = min(ans, g[i][i]);
        }
    }

    if(ans == 10000000){
        cout << -1 << "\n";
    }
    else{
        cout << ans << "\n";
    }
    
    return 0;
}