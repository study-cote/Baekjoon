#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class primeFactor {
	int n;

public:
	primeFactor(int key) : n(key) {}    // 생성자

	void printAnswer();    // 결과값 계산 및 출력
};

void primeFactor::printAnswer() {  // 결과값 계산 및 출력
	int prime = 3, max;
	max = ((int)sqrt(n)) + 1;   // 소인수가 루트(n)을 넘는 것은 최대 1개

	while (!(n % 2)) {       // 소인수 중 짝수는 2밖에 없으므로 따로 계산
		cout << 2 << '\n';
		n /= 2;
	}
	while (n > 1 && prime < max) {     // 홀수인 소수 찾기
		if (!(n % prime)) {
			cout << prime << '\n';
			n /= prime;
		}
		else {           // 홀수만 보므로 +2
			prime += 2;
		}
	}
	if (n > 1) {     // 루트(n)을 넘는 소수가 있을 경우
		cout << n;
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	
	cin >> n;
	primeFactor temp(n);
	temp.printAnswer();   // 결과 출력

	return 0;
}