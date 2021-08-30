#include <iostream>
using namespace std;

int* arr; // 분해합 저장할 배열

void decomposition_sum(int n) {
    for (int i=1; i<=n; i++) {
        int sum=i, tmp = i; // i 더하기

        while(tmp>0) { // 계속 분해가 가능한지 확인
            sum += tmp%10; // i를 이루는 각 자리 수의 합 더하기
            tmp /= 10; // 다음 자리로 이동
        }
        
        arr[i-1] = sum; // 배열에 분해합 저장하기
    }

    int min = 0; // 생성자가 없을 경우 0
    for (int i=1; i<=n; i++) {
        if (arr[i] == n) { // 분해합의 생성자 찾았을 경우
            min = i+1; // min에 저장
            break; // 가장 작은 생성자 찾는게 목적이므로 break
        }
    }

    cout << min; // 생성자 출력

    return;
}

int main() {
    int n;
    cin >> n;

    arr = (int *)malloc(sizeof(int) * n); // 보통 생성자는 입력보다 작은 수이므로 입력만큼의 크기를 가진 배열 할당

    decomposition_sum(n); // 분해합 구하고, 생성자 출력하는 함수

    return 0;
}