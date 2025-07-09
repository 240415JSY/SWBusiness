#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));

    // 인접 행렬 입력
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> g[i][j];

    // 플로이드-워셜 알고리즘
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (g[i][k] && g[k][j]) {
                    g[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}