#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int k;
    int size = 1, count = 0;
    cin >> k;

    while(size < k){
        size <<= 1;
    }
    cout << size;

    while(k){
        if(k < size){
            size >>= 1;
            count++;
        }
        else{
            k -= size;
        }
    }
    cout << " " << count;
    return 0;
}