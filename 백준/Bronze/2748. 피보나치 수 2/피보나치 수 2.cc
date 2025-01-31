#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//배열 하나를 만들기


int main(){
    int n;
    cin >> n;
    long long dp[91] = {0, 1};
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}