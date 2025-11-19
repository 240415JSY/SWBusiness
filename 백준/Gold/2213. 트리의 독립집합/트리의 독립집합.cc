// 트리이고 루트가 있으면? 트리 dp를 할 수 있다?
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
const int MAX = 10001;

vector<int> graph[MAX];
int tree[MAX];
int visited[MAX];
int dp[MAX][2];
int n, m;
vector<int> answer;

void dfs(int now)
{
    visited[now] = 1;
    dp[now][0] = 0;
    dp[now][1] = tree[now];

    for (auto i : graph[now])
    {
        if (visited[i])
        {
            continue;
        }
        dfs(i);
        dp[now][1] += dp[i][0];
        dp[now][0] += max(dp[i][0], dp[i][1]);
    }
}

void route(int now, int select)
{
    visited[now] = 1;
    int check = 0;
    // 독립 집합인 경우만 저장하기
    if(!select && dp[now][1] > dp[now][0]){
        check = 1;
        answer.push_back(now);
    }

    for(auto i : graph[now]){
        if(!visited[i]){
            route(i, check);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";

    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    route(1, 0);
    sort(answer.begin(), answer.end());
    for(auto i : answer){
        cout << i << " ";
    }
    return 0;
}