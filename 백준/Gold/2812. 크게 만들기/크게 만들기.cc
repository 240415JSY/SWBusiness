#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k;
    string num, result;

    cin >> n >> k;
    cin >> num;

    for(auto c : num){
        // 지울 수 있는 문자가 있고, 지울 수 있는 횟수가 남아있으며, 문자열의 마지막 숫자가 추가될 문자보다 작으면 지워도 된다.
        while(!result.empty() && k > 0 && result[result.size() - 1] < c){
            // 글자 지우고 지우는 횟수 1번 감소시키기
            result.pop_back();
            k--;
        }
        // 글자 하나씩 추가
        result += c;
    }
    // 내림차순인 숫자의 경우 위 반복문을 통해 글자를 지울 수 없다. 이 경우 남은 횟수를 뒤에서부터 지우는 식으로 사용한다.
    while(k > 0){
        result.pop_back();
        k--;
    }

    cout << result;
    return 0;
}