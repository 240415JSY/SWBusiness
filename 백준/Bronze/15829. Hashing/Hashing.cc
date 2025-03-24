#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int l;
    long long count = 1, ans = 0;
    int r = 31, m = 1234567891;
    cin >> l;
    string w;
    cin >> w;
    for(int i = 0; i < l; i++){
        int trans = w[i] - 'a' + 1; //몇 번째 알파벳인가
        ans = (ans + trans * count) % m;
        count = count * r % m;
    }
    cout << ans << "\n";
    return 0;
}