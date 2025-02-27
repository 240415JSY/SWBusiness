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
    int n, x;
    priority_queue<int, vector<int>, greater<int>> ans; //최소 힙
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans.push(x);
    }
    while(!ans.empty()){
        cout << ans.top() << '\n';
        ans.pop();
    }
    return 0;
}