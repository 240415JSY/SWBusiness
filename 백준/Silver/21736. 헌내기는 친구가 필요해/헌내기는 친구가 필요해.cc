#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, m, answer = 0;   
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
char map[600][600];
queue<pair<int, int>> q;
vector<vector<bool>> check(600, vector<bool> (600, 0));

void bfs(){
    while(q.size()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];   // 다음 칸
            // 1. 구역을 벗어나는 경우
            if(ny < 0 || nx < 0 || ny >= n || nx >= m){
                continue;
            }
            // 2. 이미 확인한 칸일 경우
            if(check[ny][nx]){
                continue;
            }
            // 3. 다음 탐색한 칸이 벽인 경우
            if(map[ny][nx] == 'X'){
                continue;
            }
            // 다음 칸에 사람이 있을 경우 answer++
            if(map[ny][nx] == 'P'){
                answer++;
            }
            // 그 모든 조건에 해당하지 않는 경우 다음 칸을 확인한 칸으로 변경한 후, bfs를 진행하는 큐에 넣기
            check[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    int sy, sx;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            map[i][j] = s[j];
            if(s[j] == 'I'){
                sy = i;
                sx = j;
            }
        } 
    }
    q.push({sy, sx});
    check[sy][sx] = true;
    bfs();

    if(answer == 0){
        cout << "TT\n";
    }
    else{
        cout << answer << "\n";
    }

    return 0;
}