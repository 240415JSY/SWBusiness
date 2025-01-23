#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

queue<pair<int, int>> q;

//1은 익음. 0은 안익음, -1은 토마토 없음음
int m, n, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, total = 0, day = 0;
int box[1001][1001], check[1001][1001];

void bfs(){
    while(q.size()){
        int size = q.size();
        day++;
        for(int i = 0; i < size; i++){
            int x = q.front().first; //pair<int, int>에서 앞, 즉 x좌표
            int y = q.front().second; //pair<int, int>에서 뒤, 즉 y좌표
            q.pop();

            for(int j = 0; j < 4; j++){
                int nx = x + dx[j]; // 새로운 x좌표
                int ny = y + dy[j]; // 새로운 y좌표
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(box[nx][ny] == 0){
                        box[nx][ny] = 1;    
                        q.push({nx,ny});
                        total--;
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) {
                q.push({i, j}); //익었으니 큐에 추가함
            }
            else if(box[i][j] == 0) {
                total++; //익지 않은 토마토의의 수 증가
            }
        }
    }
    if(total == 0){ //이미 모든 토마토가 익어있는 경우
        cout << 0;
        return 0;
    }

    bfs();
    if(total == 0){ //이미 모든 토마토가 익어있는 경우
        cout << day - 1;
    }
    else{
        cout << "-1";
    }
    return 0;
}