#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(201);

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

// 두 집합을 합치기
void unit(int x, int y){
    x = find(x);
    y = find(y);
    if (x != y){
        parent[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int connect;
            cin >> connect;
            if (connect == 1) {
                unit(i, j);
            }
        }
    }

    vector<int> road(m);
    for (int i = 0; i < m; i++) {
        cin >> road[i];
    }

    int root = find(road[0]);
    for (int i = 1; i < m; i++) {
        if (find(road[i]) != root) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}