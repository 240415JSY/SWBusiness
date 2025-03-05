#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, qn, p, qi, qv;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ans; //최소힙

    cin >> n;
    vector<int> list(n);
    //배열에 들어갈 수들을 입력
    for(int i = 1; i <= n; i++){
        cin >> list[i];
        ans.push({list[i], i}); //인덱스가 아닌 그곳의 값이 작은 순서로 정렬
    }

    cin >> qn;
    //1 qi qv: list에서 인덱스가 qi인 곳의 값을 qv로 바꾼다.
    //2: 최솟값의 인덱스를 출력한다.
    for(int i = 0; i < qn; i++){
        cin >> p;
        if(p == 1){
            cin >> qi >> qv;
            list[qi] = qv;
            ans.push({qv, qi});
            //이렇게 된다면 list만 갱신이 되고, ans에는 인덱스가 같지만 여러개의 값이 생김. 갱신되기 전의 것은 무시해주어야 함.
        }
        else if(p == 2){
            while(list[ans.top().second] != ans.top().first){ //갱신된 값이 아닌 오래된 값이 발견되는 동안
                ans.pop(); //필요없는 값을 pop
            }
            cout << ans.top().second << '\n';
        }
    }
    return 0;
}