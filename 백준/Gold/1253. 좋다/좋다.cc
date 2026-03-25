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

    vector<int> a(n);
    for(int i= 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    int front, back;
    int answer = 0;
    int min = 2000000000;

    for(int i = 0; i < n; i++){
        int left = 0, right = n - 1;

        while(right > left){
            if(left == i){
                left++;
                continue;
            }
            if(right == i){
                right--;
                continue;
            }

            int sum = a[left] + a[right];
            if(sum == a[i]){
                answer++;
                break;
            }
            else if(sum < a[i]){
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout << answer;
}