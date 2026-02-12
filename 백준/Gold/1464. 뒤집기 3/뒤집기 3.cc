#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//deque만의 특징!!! dq.front(), dq.back()처럼 양 끝쪽도 접근 가능하고, 동시에 dq[i]처럼 인덱스 접근도 가능하다!!!

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    string s;
    cin >> s;

    int size = s.size();

    // reverse 함수 사용
    for(int i = 1; i < s.size(); i++){
        // 맨 앞의 문자와 비교했을 때 자기가 사전순으로 더 앞에 있으면 앞으로 가야한다.
        if(s[0] >= s[i]){
            reverse(s.begin(), s.begin() + i);
            reverse(s.begin(), s.begin() + i + 1);
        }
    }
    cout << s;
}