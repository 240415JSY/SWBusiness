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
    int n, m, num;
    cin >> n;
    vector<int> card(n);
    for(int i = 0; i < n; i++){
        cin >> card[i];
    }

    sort(card.begin(), card.end());

    cin >> m;
    vector<int> answer(m);
    for(int i = 0; i < m; i++){
        cin >> num;
        int left = 0, right = n;
        while(left < right){
            int mid = (left + right) / 2;
            if(card[mid] >= num){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        int low = left;

        left = 0, right = n;
        while(left < right){
            int mid = (left + right) / 2;
            if(card[mid] > num){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        int up = left;
        answer[i] = up - low;
    }
    for(int i = 0; i < m; i++){
        cout << answer[i] <<" ";
    }
    return 0;
}