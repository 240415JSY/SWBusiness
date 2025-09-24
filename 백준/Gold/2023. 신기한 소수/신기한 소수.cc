#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;

int n;
vector<int> number;
vector<bool> check;

void amazingN(int s, int depth){
    for(int i = 2; i < sqrt(s); i++){
        if(s % i == 0){
            return;
        }
    }
    if(depth == n){
        cout << s << "\n";
    }
    else{
        s = s * 10;
        amazingN(s + 1, depth + 1);
        amazingN(s + 3, depth + 1);
        amazingN(s + 7, depth + 1);
        amazingN(s + 9, depth + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    amazingN(2, 1);
    amazingN(3, 1);
    amazingN(5, 1);
    amazingN(7, 1);
}