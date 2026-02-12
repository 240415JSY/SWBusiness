#include<iostream>
#include<algorithm>
#include<string>
#include<deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    string s;
    cin >> s;

    deque<char> dq;

    // dq에 첫 글자 넣어주기
    dq.push_back(s[0]);

    for(int i = 1; i < s.size(); i++){
        if(dq.front() >= s[i]){
            dq.push_front(s[i]);
        }
        else{
            dq.push_back(s[i]);
        }
    }

    for(auto c : dq){
        cout << c;
    }

    return 0;
}