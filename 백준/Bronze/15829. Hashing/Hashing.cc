#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int l;
    long long count = 1, sum = 0, ans = 0;
    cin >> l;
    string w;
    cin >> w;
    for(int i = 0; i < l; i++){
        int trans = w[i] - 96; //몇 번째 알파벳인가
        if(i == 0){ //만약 0번째 자리수라면
            count = 1; //31의 0승이므로 1
        }
        else{ //아니라면
            for(int j = 1; j <= i; j++){ //i번째 자리인만큼 31을 곱해야 한다.
                count *= 31;
            }
        }
        ans = count * trans; //그렇게 나온 count와 trans를 곱해주고
        sum += ans; // 총 합에 더한다.
        count = 1;
    }
    cout << sum % 1234567891 << "\n";
    return 0;
}