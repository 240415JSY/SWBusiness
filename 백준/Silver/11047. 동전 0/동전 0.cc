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
    int n, k, count = 0;
    cin >> n >> k;
    vector<int> coin(n);
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    //개수의 최솟값을 구해야 하니 가치가 가장 큰 동전부터 활용해보자
    for(int i = n - 1; i >= 0; i--){
        count += k / coin[i];
        k = k % coin[i]; 
    }
    cout << count;
    return 0;
}