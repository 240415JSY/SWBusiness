#include <queue>
#include <iostream>
#include <algorithm> //문자열을 정수로 바꾸는 함수: stoi
#include <vector>
#include <cmath>
#include <string> //정수를 문자열로 바꾸는 함수: to_string
using namespace std;

long long a, b, c;

long long jegob(long long jisu){
    if(jisu == 1){
        return a % c;
    }
    //재귀를 해야함.
    long long half = jegob(jisu / 2); //t가 홀수인지 짝수인지에 따라 경우 나누기
    if(jisu % 2){
        return ((half * half) % c * a) % c;
    }
    else{
        return (half * half) % c;
    }
}
//예시: a가 10, b가 11, c가 12: 10을 11번 곱한 수를 12로 나눈 나머지, jegob(11)이면 half = jegob(5)->jegob(2)->jegob(1)
//jegob(1) = 10, jegob(2) = 4, jegob(5) = 4 

int main(){
    cin >> a >> b >> c;
    cout << jegob(b);
}