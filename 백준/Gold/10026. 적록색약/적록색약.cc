#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, color, ansX = 0, ansO = 0;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
int mapX[100][100], mapO[100][100];
queue<pair<int, int>> q;
vector<vector<bool>> check(100, vector<bool> (100, 0));

// 적록색약이 없는 사람의 지도에서 같은 색깔 구역 구분
void bfsX(){
    while(q.size()){
        int y = q.front().first, x = q.front().second;  // 저쟝해놓고
        q.pop(); // 빼기
        for(int i = 0; i < 4; i++){
            int nextY = y + dy[i], nextX = x + dx[i];   // 다음 칸
            // 1. 구역을 벗어나는 경우
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n){
                continue;
            }
            // 2. 이미 확인한 칸일 경우
            if(check[nextY][nextX]){
                continue;
            }
            // 3. 다음 칸의 색이 현재 칸의 색과 다른 경우
            if(mapX[nextY][nextX] != color){
                continue;
            }
            // 그 모든 조건에 해당하지 않는 경우 다음 칸을 확인한 칸으로 변경한 후, bfs를 진행하는 큐에 넣기
            check[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
}

// 적록색약이 있는 사람의 지도에서 같은 색깔 구역 구분
void bfsO(){
    while(q.size()){
        int y = q.front().first, x = q.front().second;  // 저쟝해놓고
        q.pop(); // 빼기
        for(int i = 0; i < 4; i++){
            int nextY = y + dy[i], nextX = x + dx[i];   // 다음 칸
            // 1. 구역을 벗어나는 경우
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n){
                continue;
            }
            // 2. 이미 확인한 칸일 경우
            if(check[nextY][nextX]){
                continue;
            }
            // 3. 다음 칸의 색이 현재 칸의 색과 다른 경우
            if(mapO[nextY][nextX] != color){
                continue;
            }
            // 그 모든 조건에 해당하지 않는 경우 다음 칸을 확인한 칸으로 변경한 후, bfs를 진행하는 큐에 넣기
            check[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            // 빨간 그룹
            if(s[j] == 'R'){
                mapX[i][j] = 0;
                mapO[i][j] = 0;
            }
            // 초록 그룹
            else if(s[j] == 'G'){
                mapX[i][j] = 1;
                mapO[i][j] = 0;
            }
            // 기타 그룹
            else{
                mapX[i][j] = 2;
                mapO[i][j] = 2;
            }
        }
    }
    // 적록색약 X ver. bfs;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!check[i][j]){
                color = mapX[i][j];
                q.push({i, j});
                check[i][j] = true;
                bfsX();
                ansX++;
            }
        }
    }

    check = vector<vector<bool>> (100, vector<bool> (100, 0));
    // 적록색약 O ver. bfs;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!check[i][j]){
                color = mapO[i][j];
                q.push({i, j});
                check[i][j] = true;
                bfsO();
                ansO++;
            }
        }
    }
    cout << ansX << " " << ansO;
}