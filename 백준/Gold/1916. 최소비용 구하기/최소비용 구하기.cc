#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int n, m, start, finish, a, b, w;

//간선의 정보를 저장할 구조체
struct edge{ //인접리스트로 그래프를 구현, 우선순위큐에 정점의 정보를 저장함.
    int v; //목표 대상의 정점 번호
    int w; //가중치
};

struct cmp{ //우선순위 큐 정렬 기준: w가 작을수록 앞으로
    bool operator()(edge a, edge b){
        return a.w > b.w;
    }
};

//시작 정점에서 가까운 순서로 정점들을 정리해주는 우선순위 큐이다.
//이는 다익스트라를 돌릴 때, 다음 정점을 어디로 할지를 정해주는 역할을 한다.
priority_queue<edge, vector<edge>, cmp > pq;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m; //정점 개수, 간선 개수 입력 받기

    vector<edge> graph[n + 1]; //1번 정점부터 n번 정점까지 연결된 간선들을 저장할 인접리스트 그래프를 생성
    bool vis[n + 1] = {0, }; //방문했는지를 표시하는 배열
    vector<int> dist(n + 1, INT_MAX); //전부 초기화 된 배열을 최단경로 배열을 생성한다.

    for(int i = 0; i < m; i++){ //m개의 간선 개수만큼 정보를 입력 받는다.
        cin >> a >> b >> w; //a에서 b로 가는 가중치 w의 간선이라는 뜻
        graph[a].push_back({b, w}); //간선을 저장하는 인접리스트 그래프에 간선이 도착하는 정점과 간선의 가중치를 입력받는다.
    }
    cin >> start >> finish; //시작 정점 번호 입력 받기
    dist[start] = 0; //시작 정점에서 시작 정점으로의 최단 경로는 어차피 0이므로 0으로 설정
    pq.push({start, 0}); //우선순위 큐에 다음 탐색 대상으로 시작 정점을 넣는다.

    while(!pq.empty()){ //우선순위 큐에 숫자가 있는 동안
        int now = pq.top().v; //가중치가 제일 작은 정점의 정점 번호를 now에 저장
        pq.pop(); //해당 정점은 사용했으니 pop
        if(vis[now]){ //만약 방문한 정점이라면
            continue; //지나간다
        }
        vis[now] = true; //방문하지 않은 정점이라면 이제 방문했으니 true로 표시한다.
        for(auto i : graph[now]){ //모든 요소를 i에 가져와서 반복문 실행
            int next = i.v; //다음 정점 번호를 next에 저장
            int weight = i.w; //다음 간선의 가중치를 weight에 저장
            if(dist[next] > dist[now] + weight){ //만약 다음 정점의 최단 경로가 지금 정점의 최단 경로 + 다음 간선의 가중치보다 크다면
                dist[next] = dist[now] + weight; //최단경로를 갱신한다.
                pq.push({next, dist[next]}); //다음 탐색 대상으로 next 정점을 넣는다.
            }
        }
    }

    cout << dist[finish] << "\n";
}