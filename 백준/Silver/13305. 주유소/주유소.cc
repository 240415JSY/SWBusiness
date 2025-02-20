#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, sum = 0, now = 0, after = 0, ans = 0; //now, after, sum 참고
    cin >> n;
    vector<long long> price(n, 0);
    vector<long long> dis(n, 0);
    for(int i = 0; i < n - 1; i++){
        cin >> dis[i];
    }
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    while(after < n){
        //만약 이번 지역의 기름값이 다음 지역보다 싸다면, 가야하는 거리만 증가시키면 된다.
        if(price[now] <= price[after]){
            sum += dis[after++]; //거리를 증가시켜준 후, 다음에는 그 다음 지역까지의 거리를 더해야 하니 after를 증가시킨다.
        }
        else{//이번 지역의 기름값이 다음 지역보다 비싸다면,
            ans += sum * price[now]; //이번 지역까지는 지금까지 누적해 온 거리만큼의 기름이 들어가야 하고
            now = after; //현재 지역을 갱신시킨 후
            sum = 0; //누적 거리를 초기화시켜야 한다.
        }
    }
    ans += sum * price[now]; //마지막에 sum에 남아있는 값을 최종적으로 더해준다.
    cout << ans;
    return 0;
}