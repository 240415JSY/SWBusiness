#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> parent(1000001);
int find(int x){ //최상위 부모 탐색 함수. 재귀 활용
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unit(int x, int y){ //합집합을 만드는 함수
    x = find(x);
    y = find(y);
    parent[x] = y;
}
//유의할점: 배열 크기 설정, 메인 함수 시작 시 parent[i] = i로 초기화 하는 것

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, a, b, f;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> f >> a >> b;
        if(f == 0){
            unit(a, b);
        }
        else{
            if(find(a) == find(b)){
                cout << "yes" << "\n";
            }
            else{
                cout << "no" << "\n";
            }
        }
    }
}