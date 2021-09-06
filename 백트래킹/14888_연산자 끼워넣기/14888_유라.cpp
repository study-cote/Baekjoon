#include <iostream>
#define MAX 11
using namespace std;

int sequence[MAX];
int op[4];
int n, max_value = -1000000001, min_value = 1000000001; // 최소 최대값 -10억, 10억으로 맞추기

void operation(int res, int idx) {
    if (idx == n) { // 계산 끝날 때
        if (res < min_value) // 최소값 찾기
            min_value = res;
        if (res > max_value) // 최대값 찾기
            max_value = res;
        return;
    }

    else {
        for (int i=0; i<4; i++) {
            if (op[i] > 0) {
                op[i]--;
                if (i==0) // 더하기
                    operation(res+sequence[idx], idx+1);
                else if (i==1) // 빼기
                    operation(res-sequence[idx], idx+1);
                else if (i==2) // 곱하기
                    operation(res*sequence[idx], idx+1);
                else // 나누기
                    operation(res/sequence[idx], idx+1);
                op[i]++; // 초기화
            }
        }
    }
    return;
}

int main() {
    cin >> n;

    // 수열 입력
    for (int i=0; i<n; i++) {
        cin >> sequence[i];
    }

    // 연산자 개수 입력
    for (int i=0; i<4; i++) {
        cin >> op[i];
    }
    
    operation(sequence[0], 1); // 초기 결과값은 수열 첫번째 요소, 인덱스는 1

    cout << max_value << "\n" << min_value; // 결과 출력

    return 0;
}