#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<long long> arr;
vector<long long> tree;

long long init(int st, int ed, int node)
{
    if (st == ed)
    {
        return tree[node] = arr[st];
    }
    return tree[node] = init(st, (st + ed) / 2, node * 2) + init((st + ed) / 2 + 1, ed, node * 2 + 1);
}

void update(int st, int ed, int node, int index, long long diff)
{
    if (index < st || index > ed)
    {
        return;
    }
    tree[node] += diff;
    if (st != ed)
    {
        update(st, (st + ed) / 2, node * 2, index, diff);
        update((st + ed) / 2 + 1, ed, node * 2 + 1, index, diff);
    }
}

long long sum(int st, int ed, int node, int left, int right)
{
    if (left > ed || right < st)
    {
        return 0;
    }

    if (left <= st && right >= ed)
    {
        return tree[node];
    }
    return sum(st, (st + ed) / 2, node * 2, left, right) + sum((st + ed) / 2 + 1, ed, node * 2 + 1, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    arr.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    init(1, N, 1);

    long long x, y, a, b;
    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y >> a >> b;
        int t;

        if(x > y){
            t = y;
            y = x;
            x = t;
        }

        cout << sum(1, N, 1, x, y) << "\n";
        long long diff = b - arr[a];
        arr[a] = b;
        update(1, N, 1, a, diff);
    }

    return 0;
}