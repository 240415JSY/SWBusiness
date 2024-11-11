#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N, M;

    cin >> N;
    vector<int> N_num(N, 0);
    for(int i = 0; i < N; i++){
        cin >> N_num[i];
    }

    cin >> M;
    vector<int> M_num(M, 0);
    for(int i = 0; i < M;i++){
        cin >> M_num[i];
    }
    
    sort(N_num.begin(), N_num.end());

    int left = 0, right = N, mid;
    vector<int> answer(M, 0);
    for(int i = 0; i < M; i++){
        left = 0;
        right = N - 1;
        while(left <= right){
            mid = (left + right) / 2;
            if(N_num[mid] == M_num[i]){
                break;
            }
            else if(N_num[mid] < M_num[i]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(N_num[mid] == M_num[i]){
            answer[i] = 1;
        }
    }
    for(int i = 0; i < M; i++){
        cout << answer[i] << " ";
    }
    return 0;
}