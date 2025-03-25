#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

string checkFB(int a){
    if(a % 3 == 0 && a % 5 == 0){
        return "FizzBuzz";
    }
    if(a % 3 == 0){
        return "Fizz";
    }
    if(a % 5 == 0){
        return "Buzz";
    }
    return to_string(a);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector<string> sen(3);
    for(int i = 0; i < 3; i++){
        cin >> sen[i]; //무자열 3개를 저장한다.
    }
    int checknum = 1; //숫자인지 체크하기위한 변수 설정
    for(int i = 0; i < 3; i++){
        if(!isdigit(sen[i][0])){ //만약 세 문자열 중 하나라도 문자라면
            checknum = 0; //checknum을 0으로 바꾸고
            break; //반복을 멈춘다.
        }
    }
    if(checknum || isdigit(sen[2][0])){ //즉 세 문자열이 모두 숫자라면
        int num = stoi(sen[2]); //마지막 문자열을 숫자로 바꾼 후
        cout << checkFB(num + 1) << "\n"; //해당 숫자 + 1에 대한 checkFB를 진행하고 출력한다.
    }
    else{ //그게 아니라면
        if(isdigit(sen[0][0])){ //만약 첫 문자열이 정수라면
            cout << checkFB(stoi(sen[0]) + 3) << "\n"; //해장 숫자 + 3에 대한 checkFB를 진행하고 출력한다.
        }
        else if(isdigit(sen[1][0])){
            cout << checkFB(stoi(sen[1]) + 2) << "\n";
        }
    }
    return 0;
}