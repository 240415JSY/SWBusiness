#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, counts;
vector<int> answer;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
int map[25][25];
queue<pair<int, int>> q;
vector<vector<bool>> check(25, vector<bool> (25, 0));

void bfs(){
    while(q.size()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n){
                continue;
            }
            if(check[ny][nx]){
                continue;
            }
            if(map[ny][nx] == 0){
                continue;
            }
            check[ny][nx] = true;
            q.push({ny, nx});
            counts++;
        }
    }
    answer.push_back(counts);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            map[i][j] = s[j] - '0';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && !check[i][j]){
                q.push({i, j});
                check[i][j] = true;
                counts = 1;
                bfs();
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n";
    }
}