#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    int answer = 0;

    cin >> n;
    vector<int> man(n), woman(n);
    vector<int> sMan, bMan;
    vector<int> sWoman, bWoman;

    for(int i = 0; i < n; i++){
        cin >> man[i];
    }
    for(int i = 0; i < n; i++){
        cin >> woman[i];
    }

    for(int i = 0; i < n; i++){
        if(man[i] < 0){
            sMan.push_back(-man[i]);
        }
        else{
            bMan.push_back(man[i]);
        }
    }
    for(int i = 0; i < n; i++){
        if(woman[i] < 0){
            sWoman.push_back(-woman[i]);
        }
        else{
            bWoman.push_back(woman[i]);
        }
    }
    sort(sMan.begin(), sMan.end());
    sort(bMan.begin(), bMan.end());
    sort(sWoman.begin(), sWoman.end());
    sort(bWoman.begin(), bWoman.end());

    // man index, woman index
    int mi = 0, wi = 0;
    while(mi < bMan.size() && wi <sWoman.size()){
        if(bMan[mi] < sWoman[wi]){
            answer++;
            mi++;
            wi++;
        }
        else{
            wi++;
        }
    }

    mi = 0, wi = 0;
    while(mi < sMan.size() && wi <bWoman.size()){
        if(sMan[mi] > bWoman[wi]){
            answer++;
            mi++;
            wi++;
        }
        else{
            mi++;
        }
    }
    cout << answer;
}