#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Point{
    int x, y, z;
};
queue<Point> q;

// 전제: 토마토의 상태를 표시할 때, 1은 익음, 0은 안익음, -1은 토마토 없음으로 표시한다.
// 아래위좌우앞뒤
int m, n, h, dx[6] = {0, 0, -1, 1, 0, 0}, dy[6] = {0, 0, 0, 0, -1, 1}, dz[6] = {-1, 1, 0, 0, 0, 0};
int total = 0, day = 0;                       // total은 안 익은 토마토의 수, day는 토마토가 다 익는데 걸리는 일수
int box[101][101][101], check[101][101][101]; // 토마토를 담는 상자와, 토마토의 상태를 체크하여 재탐색을 방지하는 체크판

void bfs(){
    while (q.size()){
        int size = q.size();
        day++; // 반복문이 반복될 때 마다 일수를 늘린다

        for (int i = 0; i < size; i++){
            Point p = q.front();
            int x = p.x; // pair<int, int>에서 첫번째, 즉 x좌표
            int y = p.y; // pair<int, int>에서 두번째, 즉 y좌표
            int z = p.z; // pair<int, int>에서 세번째, 즉 z좌표
            q.pop();     // 저장해놓고 빼기. 더 이상 필요 없으므로

            for (int j = 0; j < 6; j++){
                int nx = x + dx[j]; // 방금 저장한 좌표에서 x 이동
                int ny = y + dy[j]; // 방금 저장한 좌표에서 y 이동
                int nz = z + dz[j]; // 방금 저장한 좌표에서 z 이동

                if (nx >= 0 && ny >= 0 && nz >= 0 && nx < m && ny < n && nz < h){ // 그 좌표가 박스 안 범위에 있고,
                    if (box[nx][ny][nz] == 0){                         // 해당 위치에 있는 토마토가 안 익었으면
                        box[nx][ny][nz] = 1;  // 익은걸로 바꾸고
                        q.push({nx, ny, nz}); // 익은 토마토를 저장하는 큐인 q에 넣어준다.
                        total--;              // 안 익은 토마토 개수에서 제외한다.
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> m >> n >> h; // 상자 크기 입력 받기
    for (int t = 0; t < h; t++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> box[j][i][t]; // 토마토 입력 받기
                if (box[j][i][t] == 1){
                    q.push({j, i, t}); // 익었으니 큐에 추가함
                }
                else if (box[j][i][t] == 0){
                    total++; // 익지 않은 토마토의 수 증가
                }
            }
        }
    }
    if (total == 0){ // 이미 모든 토마토가 익어있는 경우
        cout << 0;
        return 0;
    }

    bfs();
    if (total == 0){ // bfs를 실행한 후 모든 토마토가 익어있는 경우
        cout << day - 1;
    }
    else{
        cout << "-1";
    }
    return 0;
}