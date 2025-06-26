#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t, n, k, x, y, w;
    int result = 0;
    int ind[1001] = {0,}; // 진입 차수
    int time[1001] = {0,}; // 작업에 걸리는 시간
    int minT[1001] = {0,}; // 해당 작업까지 하는 데 걸리는 최소 시간간
    vector<int> g[1001]; // 인접 리스트로 구현할 작업 그래프
    queue<int> q; // 진입 차수 == 0을 넣을 큐
    cin >> t;
    while(t--){
        cin >> n >> k;
        
        for(int i = 1; i <= n; i++){
            cin >> time[i];
        }

        for(int i = 0; i < k; i++){
            cin >> x >> y;
            g[x].push_back(y);
            ind[y]++;
        }

        cin >> w;

        for(int i = 1; i <= n; i++){
            if(ind[i] == 0){
                q.push(i);
                minT[i] = time[i];
            }
        }

        while(q.size()){
            int now = q.front();
            q.pop();

            for(auto j : g[now]){
                ind[j]--;
                minT[j] = max(minT[j], minT[now] + time[j]);
                if(ind[j] == 0){
                    q.push(j);
                }
            }
        }
        cout << minT[w] << "\n";
        for(int i = 1; i <= n; i++){
            minT[i] = 0;
            ind[i] = 0;
            g[i].clear();
        }
    }
    return 0;
}