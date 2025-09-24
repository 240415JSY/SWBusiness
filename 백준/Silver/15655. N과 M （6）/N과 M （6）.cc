#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, m, t;
vector<int> number;
vector<bool> check;
vector<int> list;
void backTracking(int length){
    if(length < m){
        for(int i = 1; i <= n; i++){
            if(check[i]){
                continue;
            }
            if(number.size() && number.back() >= list[i - 1]){
                continue;
            }
            number.push_back(list[i - 1]);
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
    
    for(int i = 0; i < n; i++){ 
        cin >> t;
        list.push_back(t);
    }
    check = vector<bool> (n + 1, 0);
    sort(list.begin(), list.end());
    backTracking(0);
}