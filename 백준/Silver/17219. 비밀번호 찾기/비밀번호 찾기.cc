#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include <map>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, string> memo;
    string site, pw;

    // 사이트, 비밀번호 입력받기
    for(int i = 0; i < n; i++){
        cin >> site >> pw;
        memo[site] = pw;
    }
    for(int i = 0; i < m; i++){
        cin >> site;
        cout << memo[site] << "\n";
    }
    return 0;
}