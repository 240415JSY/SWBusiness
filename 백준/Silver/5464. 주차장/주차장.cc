#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    long long money[n+1];   // 주차 공간 요금
    long long weight[m+1];  // 차량 무게
    
    for(int i = 1; i <= n; i++){
        cin >> money[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> weight[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    queue<int> wait;
    vector<int> parking(m + 1, 0);
    long long ans = 0;

    for(int i = 0; i < 2 * m; i++){
        int x;
        cin >> x;

        if(x > 0){ // 들어옴
            if(!q.empty()){
                int place = q.top(); q.pop();
                parking[x] = place;
                ans += money[place] * weight[x];
            }
            else{
                wait.push(x);
            }
        }
        else{ // 나감
            x = -x;
            int place = parking[x];
            q.push(place);

            if(!wait.empty()){
                int car = wait.front();
                wait.pop();
                int s = q.top(); q.pop();
                parking[car] = s;
                ans += money[s] * weight[car];
            }
        }
    }

    cout << ans;
}