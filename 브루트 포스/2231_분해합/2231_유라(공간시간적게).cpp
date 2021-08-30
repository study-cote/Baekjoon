#include <iostream>
using namespace std;

void decomposition_sum(int n) {
    for (int i=0; i<n; i++) {
        int sum = i, tmp = i;

        while(tmp>0) { // 계속 분해가 가능한지 확인
            sum += tmp%10; // i를 이루는 각 자리 수의 합 더하기
            tmp /= 10; // 다음 자리로 이동
        }

        if (sum==n) {
            cout << i; // 생성자 찾았을 경우 출력하고 함수 종료
            return;
        }
    }
    cout << 0; // 생성자 없었을 경우 0 출력
    return;
}

int main() {
    int n;
    cin >> n;

    decomposition_sum(n); // 분해합 구하고, 생성자 출력하는 함수

    return 0;
}