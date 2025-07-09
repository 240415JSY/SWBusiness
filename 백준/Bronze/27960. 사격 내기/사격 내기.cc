#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a, b, c;
    cin >> a >> b;
    c = a ^ b;
    cout << c << "\n";

    return 0;
}