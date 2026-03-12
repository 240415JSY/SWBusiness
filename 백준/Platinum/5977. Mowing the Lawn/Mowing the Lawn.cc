#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k;
    
    cin >> n >> k;

    vector<long long> a(n+1, 0);   // 소의 가치
    vector<long long> sum(n+1, 0); // 누적합 저장
    vector<long long> dp(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    deque<pair<long long, int>> dq;
    dq.push_back({0, 0});

    for(int i = 1; i <= n; i++){
        while(!dq.empty() && dq.front().second < i - k){
            dq.pop_front();
        }

        dp[i] = sum[i] + dq.front().first;

        // 선택을 하지 않는 경우
        dp[i] = max(dp[i], dp[i - 1]);

        // 선택을 하는 경우
        long long r = dp[i - 1] - sum[i];

        while(!dq.empty() && dq.back().first <= r){
            dq.pop_back();
        }

        dq.push_back({r, i});
    }

    cout << dp[n];
}