#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//dp: 배열을 만들고, 초기화를 하고, 코드 짜기 like f(i) = f(i-1) + f(i-2)

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n;
    cin >> n;
    //1. n이 3으로 떨어지면 나눌 수 있음 2. n이 2로 떨어지면 나눌 수 있음 3. 그냥 1을 뺄 수 있음
    vector<int> minX(3 * n + 1, 0); // 횟수를 저장할 배열. 처음에는 0에서 시작
    
    for(int i = 1; i <= n; i++){
        if(minX[2 * i] == 0 || minX[2 * i] > minX[i] + 1){ //만약 방문하지 않은 숫자이거나 최단거리의 갱신이 가능할 경우
            minX[2 * i] = minX[i] + 1;
        }
        if(minX[3 * i] == 0 || minX[3 * i] > minX[i] + 1){
            minX[3 * i] = minX[i] + 1;
        }
        if(minX[i + 1] == 0 || minX[i + 1] > minX[i] + 1){
            minX[i + 1] = minX[i] + 1;
        }
    }

    cout << minX[n] << endl;
    return 0;
}