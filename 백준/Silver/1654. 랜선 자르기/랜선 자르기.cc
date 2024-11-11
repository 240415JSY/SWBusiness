#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long K, N, min = 1, max = 0, mid, answer = 0;

    cin >> K >> N;
    vector<int> s(K, 0);
    for(int i = 0; i < K; i++){
        cin >> s[i];
        if(max < s[i]){
            max = s[i];
        }
    }

    while(min <= max){
        mid = (min + max) / 2;
        long long sum = 0;
        for(int i = 0; i < K; i++){
            sum += s[i] / mid;
        }

        if(sum >= N){
            answer = sum;
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }
    cout << max;
}