#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

// 유니온 파인드를 위한 구조체
struct a{
    int p; // 부모 노드 번호
    int s; // 현재 그룹 인원 수
    int c; // 현재 그룹 사탕 수
};

vector<a> kids(30001);
int dp[3001];

int find(int x){
    if(kids[x].p == x){
        return x;
    }
    return kids[x].p = find(kids[x].p);
}

void unit(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        kids[y].p = x;
        kids[x].s += kids[y].s;
        kids[x].c += kids[y].c;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    // n은 거리에 있는 아이들의 수, m은 아이들의 친구 관계 수, k는 울음소리가 공명하기 위한 최소 아이의 수
    int n, m, k;
    cin >> n >> m >> k;


    for(int i = 1; i <= n; i++){
        int candy;
        cin >> candy;
        kids[i].p = i;
        kids[i].s = 1;
        kids[i].c = candy;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        unit(a, b);
    }

    for(int i = 1; i<= n; i++){
        if(find(i) == i){
            int size = kids[i].s;
            int candy = kids[i].c;

            for(int j = k - 1; j >= size; j--){
                dp[j] = max(dp[j], dp[j - size] + candy);
            }
        }
    }
    cout << dp[k - 1] << "\n";
    return 0;
}