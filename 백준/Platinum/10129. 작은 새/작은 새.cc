#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n, q, k;

    cin >> n;

    // d: 나무의 높이
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> d[i];
    }

    cin >> q;

    while (q > 0){
        cin >> k;

        vector<int> dp(n + 1, 0);
        deque<int> dq; // 인덱스를 저장하는 덱
        
        // 초기 시작점 설정
        dq.push_back(1);
        dp[1] = 0;

        for (int i = 2; i <= n; i++){
            // k를 벗어나면 제거
            while (!dq.empty() && dq.front() < i - k){
                dq.pop_front();
            }

            // 최적의 위치(덱의 가장 앞)에서 점프
            int best = dq.front();
            dp[i] = dp[best] + (d[best] <= d[i]);

            // 새로 들어갈 i가 더 유리하면 제거
            while (!dq.empty()){
                int back = dq.back();
                
                // 피로도가 더 작거나, 피로도가 같으면서 나무가 더 높거나 같은 경우
                if (dp[i] < dp[back] || (dp[i] == dp[back] && d[i] >= d[back])){
                    dq.pop_back();
                }
                else{
                    break;
                }
            }
            dq.push_back(i);
        }
        cout << dp[n] << "\n";
        q--;
    }
    return 0;
}