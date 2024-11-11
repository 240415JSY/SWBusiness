#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct p{
    int x;
    int y;
};

bool cmp(p a, p b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    vector<p> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < N; i++){
        cout << a[i].x << " " << a[i].y << "\n";
    }
}