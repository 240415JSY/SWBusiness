#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<long long> liq(n);

    for(int i = 0; i < n; i++){
        cin >> liq[i];
    }

    sort(liq.begin(), liq.end());

    int left, right;
    int front, back, index;
    long long min = 3000000000;
    long long sum = 0;

    for(int i = 0; i < n; i++){
        left = i + 1;
        right = n - 1;

        while(right > left){
            sum = liq[i] + liq[left] + liq[right];
            if(sum >= 0){
                if(min > sum){
                    min = sum;
                    index = liq[i];
                    front = liq[left];
                    back = liq[right];
                }
            }
            else{
                if(min > -sum){
                    min = -sum;
                    index = liq[i];
                    front = liq[left];
                    back = liq[right];
                }
            }
            if(sum < 0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout << index << " " << front << " " << back;
    return 0;
}