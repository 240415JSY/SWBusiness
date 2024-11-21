#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
int n, m, a, b;//n: 컴퓨터의 수, m: 연결된 컴퓨터 쌍의 수, a와 b: 번호 쌍

int arr[101][101];
bool tf[101] = {0, };
void dfs(int now){ //now: 지금 위치해있는 점
    cnt++; // 컴퓨터의 개수 카운트
    for(int i = 1; i <= n; i++){
        if(arr[now][i] == 1 && tf[i] == 0){
            tf[i] = 1;
            dfs(i);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    tf[1] = {1};
    dfs(1);
    cout << cnt - 1;
    return 0;
}