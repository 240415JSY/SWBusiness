#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, t, p;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end()); //이진 탐색을 활용하기 위한 정렬
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> p;
        cout << binary_search(a.begin(), a.end(), p) << "\n";
    }
    return 0;
}