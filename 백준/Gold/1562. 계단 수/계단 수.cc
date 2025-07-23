#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int dp[101][10][1024], n, answer = 0;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    // 한 자리
    for(int i = 1; i<= 9; i++){
        dp[1][i][1 << i] = 1;
    }

    cin >> n;
    // 나머지 자릿수(n의 자릿수까지) 1000000000
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < 1024; j++){
            dp[i][0][j | 1] = (dp[i][0][j | 1] + dp[i - 1][1][j]) % 1000000000; // 0으로 끝나는 경우들
            dp[i][9][j | (1 << 9)] = (dp[i][9][j | (1 << 9)] + dp[i - 1][8][j]) % 1000000000; //9로 끝나는 경우들
        }

        for(int j = 1; j <= 8; j++){
            for(int k = 1; k < 1024; k++){
                dp[i][j][k|1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k] +dp[i - 1][j + 1][k]) % 1000000000;
            }
        }
    }
    for(int i = 0; i <= 9; i++){
        answer = (answer + dp[n][i][1023]) % 1000000000;
    }
    cout << answer;
}