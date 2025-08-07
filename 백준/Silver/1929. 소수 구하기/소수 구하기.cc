#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int m, n;
    cin >> m >> n; //두 수 m과 n을 입력받는다.
    vector<int> count(n + 1, 1); //크기가 n인 배열을 생성하고, 모두 1로 초기화
    count[1] = 0;
    for(int i = m; i <= n; i++){ //m부터 n까지 탐색
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){ //1을 제외한 약수가 있다면
                count[i] = 0;
                break;
            }
        }
    }
    for(int i = m; i <= n; i++){
        if(count[i] == 1){
            cout << i << "\n";
        }
    }
    return 0;
}