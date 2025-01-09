//백트래킹
#include <iostream>
#include <algorithm> //문자열을 정수로 바꾸는 함수: stoi
#include <vector>
#include <cmath>
#include <string> //정수를 문자열로 바꾸는 함수: to_string
using namespace std;

int n; //n자리 수
vector<int> number; //수열 저장
vector<bool> check; //중복인지 아닌지 확인하기 위한 check

//신기할 소수일 조건: 가장 앞의 자리가 2 or 3 or 5 or 7
void amazingN(string s){
    int number = stoi(s);

    //소수가 아니려면? 1과 자기 자신을 제외한 다른 수로 나누어 떨어지는 경우가 있으면.
    //sqrt: 제곱근 함수. 제곱근까지만 나누어서 나누어 떨어지는지 확인하면 소수인지 알 수 있다. number = a * b이기 때문문
    for(int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            return;
        }
    }

    if(s.size() == n){
        cout << s << "\n";
    }
    else{ //n자리 수가 아니라면 재귀를 해야함. 끝자리는 2의 배수가 될 수 없고, 0이나 5면 5로 나누어 떨어지므로 안된다.
        amazingN(s + "1");
        amazingN(s + "3");
        amazingN(s + "7");
        amazingN(s + "9");
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    amazingN("2");
    amazingN("3");
    amazingN("5");
    amazingN("7");
}