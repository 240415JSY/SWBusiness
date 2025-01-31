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
    int n; //계단의 개수
    cin >> n;
    //1. 계단은 1 or 2로 오를 수 있음 2. 3개의 계단을 연속으로 올라갈 수는 없음 3. 마지막 계단은 반드시 밟을 것
    vector<int> S(n + 1, 0); //해당 칸의 점수를 저장할 배열
    vector<int> maxS(n + 1, 0); // 최댓값을 저장할 배열
    
    for(int i = 1; i <= n; i++){
        cin >> S[i];
        maxS[i] = S[i];
    }
    maxS[2] = S[1] + S[2];
    for(int i = 3; i <= n; i++){
        //n = 1이면 1, 2면 1 1 or 2, 3이면 1 2 or 2 1, 4면 1 1 2, 1 2 1, 2 2, 2 1 1
        maxS[i] = max(maxS[i - 2], maxS[i - 3] + S[i - 1]) + S[i];
        //maxS[i - 2]는 i - 2번째 계단에 도착할 때 얻을 수 있는 최댓값을 유지한 것. 여기서 한번에 두계단을 오름
        //한 계단씩 오르는 것은 규칙상 불가함.
        //maxS[i - 3] + S[i - 1]은 i - 3번째 계단에 도착할 때 얻을 수 있는 최댓값을 유지한 것.
        //여기서 i - 1번째 계단을 오르고 i번째 계단을 밞음.
    }

    cout << maxS[n] << endl;
    return 0;
}