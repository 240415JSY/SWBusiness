#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // 전체 문자열, 폭발 문자열
    string s, bomb;
    cin >> s >> bomb;
    // stack처럼 사용할 문자열
    string result;

    // 폭발 문자열의 길이와 마지막 문자 저장(폭발 문자열은 같은 문자열을 포함하지 않으니 마지막을 저장해도 문제 없다)
    int bomblen = bomb.size();
    
    for(auto c : s){
        result += c;

        // 쌓인 문자열의 길이가 폭발 문자열의 길이보다 길어져 검사를 할 수 있게 되고, 방금 넣은 문자가 폭발문자열의 마지막 문자와 같다면
        if(result.size() >= bomblen && c == bomb[bomblen - 1]){
            bool isBomb = true;
            for(int i = 1; i <= bomblen; i++){
                // 뒤에서부터 비교했을 때 폭발 문자열과 하나라도 다른 부분이 있다면 폭발이 불가능하다.
                if(result[result.size() - i] != bomb[bomblen - i]){
                    isBomb = false;
                }
            }
            // 폭발이 가능하면 폭발 문자열을 result 문자열에서 지운다.
            if(isBomb){
                result.erase(result.size() - bomb.size());
            }
        }
    }

    if(result.size()){
        cout << result;
    }
    else{
        cout << "FRULA";
    }
}