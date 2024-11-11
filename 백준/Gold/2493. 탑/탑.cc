#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    int tower[N];//받는 타워의 높이
    int answer[N] = {0};//출력할 답을 저장하는곳(타워의 번호)
    stack<int>num;//타워의 번호를 저장하기 위한 곳
    cin >> tower[0];
    num.push(0);
    answer[0] = -1;
    for(int i = 1; i < N; i++){
        cin >> tower[i];
        if(tower[i] <= tower[i - 1]){
            answer[i] = i - 1;
            num.push(i);
        }
        else{
            while(num.size() > 0 && tower[num.top()]< tower[i]){
                num.pop();
            }
            if(num.size() == 0){
                answer[i] = -1;
            }
            else{
                answer[i] = num.top();
            }
            num.push(i);
        }
    }
    for(int i = 0; i < N; i++){
        cout << answer[i] + 1 << " ";
    }

    return 0;
}