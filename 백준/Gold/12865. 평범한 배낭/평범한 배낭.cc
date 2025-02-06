#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//dp: 배열을 만들고, 초기화를 하고, 코드 짜기 like f(i) = f(i-1) + f(i-2)

int n, k, w[101], v[101];
//n: 물건의 개수, k = 가방에 넣을 수 있는 무게, w = 각 물건의 무게, v = 각 물건의 가치
int dp[101][1000001] = {};
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    //1번 물건부터 넣어보기
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j < w[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}