#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(1000001, -1);
vector<int> length(1000001, 0);

int find(int x) {
    if (parent[x] == -1) {
        parent[x] = x;
        length[x] = 1;
        return x;
    }
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unit(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (length[x] < length[y]) {
            parent[x] = y;
            length[y] += length[x];
        } else {
            parent[y] = x;
            length[x] += length[y];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        char c;
        int a, b;
        cin >> c >> a;

        if (c == 'I') {
            cin >> b;
            find(a); // 초기화 및 find 호출
            find(b); // 초기화 및 find 호출
            unit(a, b);
        } else {
            int root_a = find(a);
            cout << length[root_a] << "\n";
        }
    }

    return 0;
}