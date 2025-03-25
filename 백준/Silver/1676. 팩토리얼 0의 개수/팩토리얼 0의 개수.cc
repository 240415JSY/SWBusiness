#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    cout << n / 5 + n / 25 + n / 125<< "\n";
    return 0;
}