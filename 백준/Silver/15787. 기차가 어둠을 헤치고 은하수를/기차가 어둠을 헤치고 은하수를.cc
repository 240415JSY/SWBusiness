#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    int answer = 0;
    int filter = (1 << 20) - 1;

    cin >> n >> m;
    vector<int> train(n + 1, 0);

    for(int i = 0; i < m; i++){
        int p, in_i, in_x;
        cin >> p;

        if(p == 1){
            cin >> in_i >> in_x;
            train[in_i] |= (1 << in_x - 1);
        }
        else if(p == 2){
            cin >> in_i >> in_x;
            train[in_i] &= ~(1 << in_x - 1);
        }
        else if(p == 3){
            cin >> in_i;
            train[in_i] <<= 1;
            train[in_i] &= (1 << 20) - 1;
        }
        else if(p == 4){
            cin >> in_i;
            train[in_i] >>= 1;
        }
        train[in_i] &= filter;
    }

    vector<bool> check(1 << 20, 0);
    for(int i = 1; i <= n; i++){
        if(!check[train[i]]){
            check[train[i]] = 1;
            answer++;
        }
    }
    cout << answer;
}