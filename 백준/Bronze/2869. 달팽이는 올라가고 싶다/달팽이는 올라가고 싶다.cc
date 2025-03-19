#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a, b, v, i = 1, answer = 0;
    cin >> a >> b >> v;
    if((v - a) % (a - b) == 0){
        answer = (v - a) / (a - b) + 1;
    }
    else{
        answer = (v - a) / (a - b) + 2;
    }
    cout << answer << "\n";
    return 0;
}