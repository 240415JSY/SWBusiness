#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

// 계산 함수
long long calculate(long long a, long long b, char p){
    if(p == '+') return a + b;
    if(p == '-') return a - b;
    if(p == '*') return a * b;
    if(p == '/') return a / b;
    return 0;
}

// 곱셈, 나눗셈을 덧셈, 뺄셈보다 먼저 계산해야 함
int priority(char p){
    if(p == '+' || p == '-') return 2;
    if(p == '*' || p == '/') return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;

    // 숫자랑 문자 구분해서 보기
    deque<long long> dq_num;
    deque<char> dq_y;

    // 숫자랑 연산자 분리해야함
    string t = "";
    for(int i = 0; i < s.size(); i++){
        // 1. 첫 글자가 마이너스라면 이건 t에 넣어준다
        if(i == 0 && s[i] == '-'){
            t += s[i];
            continue;
        }
        // 2. 글자가 숫자라면 이 역시 t에 넣어준다
        if(s[i] >= '0' && s[i] <= '9'){
            t += s[i];
        }
        // 3. 글자가 문자라면(즉, 그렇지 않은 경우라면) 지금까지 t에 저장했던 것들을 dq_num에 저장, t 비우기,
        // 연산자는 dq_y에 저장을 수행한다.
        else{
            dq_num.push_back(stoll(t));
            t = "";
            dq_y.push_back(s[i]);
        }
    }
    dq_num.push_back(stoll(t));

    // 연산자 deque의 양 끝을 비교하면서 계산을 진행해야 한다
    while(!dq_y.empty()){
        // 만약 연산자가 1개밖에 없다면 바로 계산을 진행
        if(dq_y.size() == 1){
            long long s_ans = calculate(dq_num[0], dq_num[1], dq_y[0]);
            // 계산에서 쓴 것들은 pop하기
            dq_num.pop_front();
            dq_num.pop_front();
            dq_num.push_front(s_ans);
            dq_y.pop_front();
            break;
        }
        // 앞 계산과 뒷 계산
        long long f_ans = calculate(dq_num[0], dq_num[1], dq_y.front());
        long long b_ans = calculate(dq_num[dq_num.size() - 2], dq_num[dq_num.size() - 1], dq_y.back());

        bool check = false;

        if(priority(dq_y.front()) < priority(dq_y.back())) check = true;
        else if(priority(dq_y.front()) > priority(dq_y.back())) check = false;
        else{
            if(f_ans >= b_ans){
                check = true;
            }
            else{
                check = false;
            }
        }

        if(check){
            dq_num.pop_front();
            dq_num.pop_front();
            dq_num.push_front(f_ans);
            dq_y.pop_front();
        }
        else{
            dq_num.pop_back();
            dq_num.pop_back();
            dq_num.push_back(b_ans);
            dq_y.pop_back();
        }
    }

    cout << dq_num[0];
    return 0;
}