#include <iostream>
#include <vector>
using namespace std;

int n, m; //1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열
vector<int> number; //수열 저장
vector<bool> check; //중복인지 아닌지 확인하기 위한 check

void backtracking(int length){
    if(length < m){ //길이가 m보다 작을 때에만 실행하기
        for(int i = 1; i <= n; i++){
            if(check[i]){ //만약 이미 저장된 자연수라면(=중복이라면)
                continue; //새로 저장 안함
            }
            //저장되어 있지 않은 자연수라면
            number.push_back(i); //저장해 주고
            check[i] = true; //수열에 저장했다고 표시
            int next = length + 1;
            backtracking(next); //재귀
            //재귀가 끝났으면 
            check[i] = false;
            number.pop_back();
        }
    }
    else{
        for(int i = 0; i < number.size(); i++){
            cout << number[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    // 방문했는지 체크하는거 0으로 초기화 해주기
    check = vector<bool> (n + 1, 0);
    backtracking(0); //재귀하기
}