#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, d, r;

    // 최대 경로를 저장할 변수
    long long ans = -10000000000000000;

    // n은 징검다리의 번호, d는 징검다리 번호의 차이가 넘으면 안되는 값(한번에 이동할 수 있는 최대 거리)
    cin >> n >> d;

    // 우선순위큐 pq의 first는 해당 징검다리까지 왔을 때의 최대 점수, second는 징검다리의 번호
    priority_queue<pair<long long, int>> pq;

    for(int i = 0; i < n ; i++){
        // r은 현재 징검다리의 점수(입력받는 값에 이전 경로의 점수를 더한다.)
        cin >> r;

        // d칸 이상 떨어진 징검다리들의 정보는 필요 없기 때문에 빼도 된다.
        while(!pq.empty() && pq.top().second < i - d){
            pq.pop();
        }

        // 
        if(pq.size()){
            r += pq.top().first;
        }

        if(r > 0){
            pq.push({r, i});
        }

        ans = max(ans, r);
    }
    cout << ans;
}