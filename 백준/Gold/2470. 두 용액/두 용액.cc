#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;//전체 용액의 수 N
    vector<int> a(N);//vector a에 N개의 정수를 입력받음-vector는 배열
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());//정렬(오름차순)
    int left = 0, right = N - 1;
    int min = 2000000000;
    int front, back;
    while(left < right){
        int sum = a[left] + a[right];
        if(sum >= 0){
            if(min > sum){
                min = sum;
                front = a[left];
                back = a[right];
            }
        }
        else{
            if(min > -sum){
                min = -sum;
                front = a[left];
                back = a[right];
            }
        }

        if(sum < 0){
            left++;
        }
        else{
            right--;
        }
    }
    cout << front << " " << back;
    return 0;
}