#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    stack<int> a;
    string answer;
    for(int i = 0; i < N; i++){
        cin >> answer;

        if(answer == "push"){
            int num;
            cin >> num;
            a.push(num);
        }

        else if(answer == "pop"){
            if(a.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << a.top() << '\n';
                a.pop();
            }
        }

        else if(answer == "size"){
            cout << a.size() << '\n';
        }
        
        else if(answer == "empty"){
            if(a.empty()){
                cout << "1" << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }

        else if(answer == "top"){
            if(a.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << a.top() << '\n';
            }
        }
    }
    return 0;
}