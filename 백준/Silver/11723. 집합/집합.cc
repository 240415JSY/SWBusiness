#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int M, x;
    // 비어있는 공집합 S
    int S = 0;
    string p;

    cin >> M;
    while(M--){
        cin >> p;
        if(p == "add"){
            cin >> x;
            S = S | (1 << x);
        }
        else if(p == "remove"){
            cin >> x;
            S = S & ~(1 << x);
        }
        else if(p == "check"){
            cin >> x;
            if(S & (1 << x)){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(p == "toggle"){
            cin >> x;
            S = S ^ (1 << x);
        }
        else if(p == "all"){
            S = 0;
            S = ~S;
        }
        else if(p == "empty"){
            S = 0;
        }
    }
    return 0;
}