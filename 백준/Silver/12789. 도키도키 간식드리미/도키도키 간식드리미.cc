#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> waiting(N); // 인원수만큼의 배열을 생성. 각자 어떤 번호표를 가지고 있는지 저장
    for (int i = 0; i < N; i++) {
        cin >> waiting[i];
    }

    stack<int> buffer;
    int check = 1; // 번호표 순서대로 간식을 받을 번호

    for (int i = 0; i < N; i++) {
        if (waiting[i] == check) {
            check++;
        } else {
            buffer.push(waiting[i]);
        }

        // 스택에서 처리 가능한 번호를 반복적으로 처리
        while (!buffer.empty() && buffer.top() == check) {
            buffer.pop();
            check++;
        }
    }

    // 최종 조건 검증
    if (check == N + 1) {
        cout << "Nice" << endl;
    } else {
        cout << "Sad" << endl;
    }

    return 0;
}