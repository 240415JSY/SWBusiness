#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

vector<int> graph[2000]; //인접 리스트 하나를 만들기
vector<bool> visited(2000, 0); //방문헸는지 체크
int n, m, a, b, length = 0;
void dfs(int now) { //이때 now는 현재 노드
    if(length == 4) { //길이가 4여서 더이상 탐색할 필요가 없을 때
        return;
    }
    int size = graph[now].size(); //현재 노드와 연결된 노드의 개수
    for(int i = 0; i < size; i++) {
        if(length == 4) { //길이가 4여서 더이상 탐색할 필요가 없을 때
            return; //반복을 끝낸다
        }
        int next = graph[now][i]; //현재 노드인 now와 연결된 i번째 노드 (=다음 노드)
        if(!visited[next]) { //다음 노드가 방문하지 않은 노드라면 (bool 값이 false라면)
            visited[next] = true; //이제는 방문했다고 표시 (bool 값을을 true로 바꿔줌)
            length++; //길이를 늘려줌
            dfs(next); //재귀적으로 다음 노드를 탐색
        }
    }

    if(length == 4) { //길이가 4여서 더이상 탐색할 필요가 없을 때
        return;
    }
    length--; //탐색이 끝났으니 길이를 줄여준다
    visited[now] = false; //방문 기록을 초기화한다
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b); //a와 b를 연결
        graph[b].push_back(a); //b와 a를 연결 why? 친구 관계는 쌍방이니까
    }
    for(int i = 0; i < n; i++) {
        visited = vector<bool>(2000, 0);
        visited[i] = true; //현재 노드인 i 노드를 방문했다고 표시
        length = 0; //길이를 0으로 초기화
        dfs(i); //dfs 탐색
        if(length == 4) { //길이가 4라면면
            break; //끝낸다
        }
    }
    if(length == 4) { //길이가 4라면
        cout << 1;
    }
    else { //아니라면
        cout << 0;
    }
}