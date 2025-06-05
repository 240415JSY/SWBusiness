#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int p[10001];
int n, m, a, b, c, ans = 0;

int find(int x){
    if(p[x] == x){
        return x;
    }
    return p[x] = find(p[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    p[x] = y;
}

struct edge{
    int s;
    int e;
    int w;
};

struct cmp{
    bool operator()(edge a, edge b){
        return a.w > b.w;
    }
};
priority_queue<edge, vector<edge>, cmp> pq;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        pq.push({a, b, c});
    }

    while(pq.size()){
        int s = pq.top().s;
        int e = pq.top().e;
        int w = pq.top().w;
        pq.pop();
        if(find(s) == find(e)){
            continue;
        }
        uni(s, e);
        ans += w;
    }
    cout << ans;
}