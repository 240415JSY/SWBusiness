#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> parent(300001);

int find(int x){ //최상위 부모 탐색 함수. 재귀 활용
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unit(int x, int y){ //합집합을 만드는 함수
    x = find(x);
    y = find(y);
    if(x != y){
        parent[x] = y;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, a, b;
    cin >> n;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < n - 2; i++){
        cin >> a >> b;
        unit(a, b);
    }
    int first = -1, second = -1;
    for(int i = 1; i <= n; i++){
        if(find(i)!=find(1)){
            first = 1;
            second = i;
            break;
        }
    }
    cout << first << " " << second << "\n";
}