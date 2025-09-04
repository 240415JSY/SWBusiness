#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <set>
#include <iterator>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        multiset<int> q;

        for(int i = 0; i < k; i++){
            char math;
            int n;
            cin >> math >> n;

            // 정수 삽입하기
            if(math == 'I'){
                q.insert(n);
            }
            else if(math == 'D'){
                // D는 큐에서 값을 제거하는 문자이므로, 비어있다면 넘어가야 한다.
                if(q.empty()){
                    continue;
                }
                // 최댓값 지우기
                if(n == 1){
                    auto it = --q.end();
                    q.erase(it);
                }
                // 최솟값 지우기
                else{
                    auto it = q.begin();
                    q.erase(it);
                }
            }
        }
        if(q.empty()){
            cout << "EMPTY\n";
        }
        else{
            cout << *(--q.end()) << " " << *(q.begin()) << " ";
        }
    }
}