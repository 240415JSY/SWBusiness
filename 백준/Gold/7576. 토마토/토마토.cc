#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

queue<pair<int, int>> q;

//1은 익음. 0은 안익음, -1은 토마토 없음
int m, n, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, total = 0, day = 0; //dx, dy는 순서대로 상하좌우
int box[1001][1001], check[1001][1001]; //토마토를 담는 상자와, 토마토의 상태를 체크하여 재탐색을 방지하는 체크판

void bfs(){
    while(q.size()){
        int size = q.size();
        day++; //반복문이 반복될 때 마다 일수를 늘린다
        for(int i = 0; i < size; i++){
            int x = q.front().first; //pair<int, int>에서 앞, 즉 x좌표
            int y = q.front().second; //pair<int, int>에서 뒤, 즉 y좌표
            q.pop(); //저장해놓고 빼기. 더 이상 필요 없으므로

            for(int j = 0; j < 4; j++){
                int nx = x + dx[j]; //방금 저장한 좌표에서 x 이동
                int ny = y + dy[j]; //방금 저장한 좌표에서 y 이동
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){ //그 좌표가 박스 안 범위에 있고, 
                    if(box[nx][ny] == 0){ //해당 위치에 있는 토마토가 안 익었으면
                        box[nx][ny] = 1; //익은걸로 바꾸고
                        q.push({nx,ny}); //익은 토마토를 저장하는 큐인 q에 넣어준다.
                        total--; //안 익은 토마토 개수에서 제외한다.
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n; //상자 크기 입력 받기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> box[i][j]; //토마토 입력 받기
            if(box[i][j] == 1) {
                q.push({i, j}); //익었으니 큐에 추가함
            }
            else if(box[i][j] == 0) {
                total++; //익지 않은 토마토의 수 증가
            }
        }
    }
    if(total == 0){ //이미 모든 토마토가 익어있는 경우
        cout << 0;
        return 0;
    }

    bfs();
    if(total == 0){ //bfs를 실행한 후 모든 토마토가 익어있는 경우
        cout << day - 1;
    }
    else{
        cout << "-1";
    }
    return 0;
}