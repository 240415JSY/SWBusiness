#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2100000000
using namespace std;

// 순서대로 도시 개수, 버스 노선 개수
int N, M;  // 도시 수, 버스 노선 수
long long dist[501];  // 거리 배열
bool cycle = false;   // 음수 사이클 여부

struct edge {
    int start;
    int end;
    int cost;
};

vector<edge> edges;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }

    // 배열은 모두 최대로 초기화
    fill(dist, dist + N + 1, INF);
    dist[1] = 0; // 시작점은 1번 도시이므로 0

    // 벨만-포드 알고리즘 시행
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int now = edges[j].start;
            int next = edges[j].end;
            int cost = edges[j].cost;
            
            // 지금 정점까지의 최단 거리가 갱신된 적 있고 새로 계산한 최단거리(지금 정점까지의 최단거리 + 다음 정점까지의 거리)가
            // 기존에 저장한 최단 거리(시작 정점에서 다음 정점까지의 최단거리리)보다 더 짧으면
            if (dist[now] != INF && dist[next] > dist[now] + cost) {
                // 최단 거리 갱신해주기
                dist[next] = dist[now] + cost;
            }
        }
    }

    // 음수 사이클 확인하기. 위의 벨만포드를 시행했는데도 더 갱신이 이루어진다면 그 그래프는 음수 사이클을 가지고 있는 것이다.
    for (int j = 0; j < edges.size(); j++) {
        int now = edges[j].start;
        int next = edges[j].end;
        int cost = edges[j].cost;

        if (dist[now] != INF && dist[next] > dist[now] + cost) {
            cycle = true;
            break;
        }
    }

    // 결과 출력. 만약 음수 사이클이 있다면 -1 출력
    if (cycle) {
        cout << -1 << '\n';
    }
    // 아니라면 값 출력
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }
    return 0;
}