#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<long long> arr;
vector<long long> tree;

// 트리를 만드는 함수 init
long long init(int st, int ed, int node)
{
    if (st == ed)
    {
        return tree[node] = arr[st];
    }

    return tree[node] = init(st, (st + ed) / 2, node * 2) + init((st + ed) / 2 + 1, ed, node * 2 + 1);
}

// 노드에 저장된 숫자를 갱신하는 함수 update
void update(int st, int ed, int node, int index, long long diff)
{
    // 현재 노드가 범위 밖에 있는 경우
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

// 구간합을 구하는 함수 sum
long long sum(int st, int ed, int node, int left, int right)
{
    // 현재 노드가 범위 밖에 있는 경우
    if (right < st || left > ed)
    {
        return 0;
    }

    // 구하려는 구간에 st~ed가 완벽하게 들어가는 경우
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

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    init(1, N, 1);

    int a, b;
    long long c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, N, 1, b, diff);
        }
        else
        {
            cout << sum(1, N, 1, b, c) << "\n";
        }
    }

    return 0;
}