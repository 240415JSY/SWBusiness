#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//dp: 배열을 만들고, 초기화를 하고, 코드 짜기 like f(i) = f(i-1) + f(i-2)

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector<int>P(n + 1, 0); //주어지는 P를 저장
    vector<int>maxP(n + 1, 0); //최댓값을 저장

    for(int i = 1; i <= n; i++){
        cin >> P[i];
        maxP[i] = P[i]; //초기화
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i / 2; j++){
            maxP[i] = max(maxP[i], maxP[i - j] + maxP[j]);
        }
    }
    cout << maxP[n];
}