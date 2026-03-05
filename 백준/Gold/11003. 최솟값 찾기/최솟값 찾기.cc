#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, l;

    cin >> n >> l;
    deque<pair<int, int>> dq;
    for(int i = 0; i < n; i++){
        int r;
        cin >> r;

        // 범위를 벗어나는 값은 제거
        while(!dq.empty() && dq.front().second <= i - l){
            dq.pop_front();
        }

        // back의 값이 현재의 값보다 크다면 빼준다.
        while(!dq.empty() && dq.back().first > r){
            dq.pop_back();
        }
        dq.push_back({r, i});
        cout << dq.front().first << " ";
    }
}