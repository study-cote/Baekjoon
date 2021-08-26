#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class apart {
	int k, n;
	long double answer;

public:
	void inputData();         // 데이터 입력
	void printAnswer();       // 결과값 계산 및 출력
};

void apart::inputData() {   // 데이터 입력
	cin >> k >> n;
}

void apart::printAnswer() {  // 결과값 계산 및 출력
	int a, b;

	a = k + n;            // (k+n)C(k+1)를 변수 이용해서 간략화
	b = k + 1;
	if (a - b < b) {
		b = a - b;
	}
	answer = 1;
	for (int i = 0; i < b; i++) {     // aCb 계산(combination 계산)
		answer *= a--;
		answer /= (b - i);
	}

	cout << (int)ceil(answer) << '\n';    // 소수점 아래 소실되는 값 올림
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int T;

	apart temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		temp.inputData();    // 데이터 입력
		temp.printAnswer();  // 결과 출력
	}

	return 0;
}