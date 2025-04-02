#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n, num, now = 1;
    cin >> n;
    stack<int> s;
    vector<char> ans;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        while(now <= num){//현재 넣은 숫자가 pop해야 하는 숫자보다 작거나 같으면
            s.push(now++); //스택에 계속해서 push한다. 현재 숫자는 1씩 늘려간다.
            ans.push_back('+'); //push를 했으므로 답에는 +를 push한다.
        }
        
        if(s.top() == num){ //만약 stack 제일 위에 있는 숫자가 pop 해야하는 숫자인 num과 같으면
            s.pop(); //pop을 하고
            ans.push_back('-'); //pop을 했으므로 답에는 -를 push 한다.
        }
        else{ //불가능하다면
            cout << "NO" << "\n"; //no를 출력한다.
            return 0;
        }
    }
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n"; //최종적으로 답을 출력한다.
    }  
    return 0;
}