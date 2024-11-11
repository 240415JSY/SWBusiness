#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, k, tx, ty, tmp;
    char c;

    cin >> n >> k;

    int map[101][101] = {0, };// 0: 없음, 1: 사과, 2: 뱀

    for(int i = 0; i < k; i++){
        cin >> ty >> tx;//x = 열, y = 행
        map[ty][tx] = 1;//사과 위치 표시
    }

    queue<int> bodyX;//뱀이 위치한 x좌표
    queue<int> bodyY;//뱀이 위치한 y좌표
    int direction = 0;//0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위
    int headX = 1, headY = 1;
    int nextX[4] = {1, 0, -1, 0}, nextY[4] = {0, 1, 0, -1};

    bodyX.push(1);
    bodyY.push(1);
    map[1][1] = 2;//뱀 위치 표시

    int l, time = 0;
    cin >> l;
    queue<int>turnTime;
    queue<char>turnDirection;
    for(int i = 0; i < l; i++){
        cin >> tmp >> c;
        turnTime.push(tmp);
        turnDirection.push(c);
    }

    while(1){
        int nx = headX + nextX[direction];//다음에 뱀이 이동할 x좌표
        int ny = headY + nextY[direction];//다음에 뱀이 이동할 y좌표
        time++;

        if(nx < 1 || ny < 1 || nx > n || ny > n){//벽에 부딪히면
            break;
        }
        else if(map[ny][nx] == 2){//자기 몸에 부딪히면
            break;
        }
        else if(map[ny][nx] == 0){//사과가 없으면
            headX = nx;
            headY = ny;//머리 좌표 미리 이동
            bodyX.push(nx);
            bodyY.push(ny);//머리 좌표 큐에 넣기
            map[ny][nx] = 2;//머리 좌표에 뱀 표시
            //머리가 이동 -> 꼬리쪽 삭제
            map[bodyY.front()][bodyX.front()] = 0;//꼬리 좌표 삭제
            bodyX.pop();//꼬리 좌표 큐에서 삭제
            bodyY.pop();
        }
        else{
            headX = nx;
            headY = ny;
            bodyX.push(nx);
            bodyY.push(ny);
            map[ny][nx] = 2;
            //사과가 있어 꼬리 삭제 안함
        }

        if(time == turnTime.front()){//방향 전환할 시간이면
            if(turnDirection.front() == 'L'){//왼쪽으로 90도 회전
                direction = (direction + 3) % 4;
            }
            else{//오른쪽으로 90도 회전
                direction = (direction + 1) % 4;
            }
            turnTime.pop();
            turnDirection.pop();
        }   
    }

    cout << time;
    return 0;
}