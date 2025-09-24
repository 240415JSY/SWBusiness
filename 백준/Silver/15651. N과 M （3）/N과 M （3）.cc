#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;


int n, m;
vector<int> number;
vector<bool> check;

void backTracking(int length){
    if(length < m){
        for(int i = 1; i <= n; i++){
            number.push_back(i);
            check[i] = true;
            int next = length + 1;
            backTracking(next);
            check[i] = false;
            number.pop_back();
        }
    }
    else{
        for(int i = 0; i < number.size(); i++){
            cout << number[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    check = vector<bool> (n + 1, 0);
    backTracking(0);
}