// 트리이고 루트가 있으면? 트리 dp를 할 수 있다?
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
const int MAX = 100001;

vector<int> graph[MAX];
int good[MAX];
int n, m;

void dfs(int now){
    for(auto i : graph[now]){
        good[i] += good[now];
        dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    vector<int> node(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> node[i];
        if(node[i] != -1){
            graph[node[i]].push_back(i);
        }
    }

    for(int i = 0; i < m; i++){
        int nodeNum, num;
        cin >> nodeNum >> num;
        good[nodeNum] += num;
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << good[i] << " ";
    }

    return 0;
}