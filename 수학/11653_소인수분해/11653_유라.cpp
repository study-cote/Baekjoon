#include <iostream>
using namespace std;

int main() {
    int n, i=2;
    cin >> n;

    while(n>1) { // 1 출력하지 않기 위해 조건 설정
        if (n%i==0) { // 나눠지는 소수 찾기
            cout << i << endl; // 출력
            n = n/i;
            i = 2; // 나눠진 수의 소수를 다시 찾기 위해 초기화
        }
        else i++;
    }

    return 0;
}