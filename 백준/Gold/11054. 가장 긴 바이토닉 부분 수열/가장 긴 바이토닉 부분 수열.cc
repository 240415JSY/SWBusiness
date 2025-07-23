#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include <cmath>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int result = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> plus(n, 1);
    vector<int> minus(n, 1);
    
    // 가장 긴 바이토닉 부분 수열 길이 = 가장 긴 증가수열 길이 + 가장 긴 감소수열 - 1 <<- -1의 이유는 중간에 하나 겹치니까
    // ex) 10 20 30 20 10 -> 증가수열 길이 3, 감소수열 길이 3, 30이 겹침 == 길이 5
    // 감소수열 찾는 dp
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[i]){ // 다음에 오는게 더 작다 == 감소 수열
                minus[i] = max(minus[i], minus[j] + 1);
            }
        }
    }

    // 증가수열 찾는 dp
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){ // 앞에 오는게 더 작다 == 증가 수열
                plus[i] = max(plus[i], plus[j] + 1);
            }
        }
    }

    for(int i = 0; i < n; i++){
        result = max(result, plus[i] + minus[i] - 1);
    }

    cout << result;
    return 0;
    
}