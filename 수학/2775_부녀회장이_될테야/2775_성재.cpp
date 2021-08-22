#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::ios_base;

class apart {
	int k, n;
	double answer;

public:
	void inputData();         // 데이터 입력
	void printAnswer();       // 결과값 계산 및 출력
};

void apart::inputData() {
	cin >> k >> n;
}

void apart::printAnswer() {
	int a, b;

	a = k + n;
	b = k + 1;
	if (a - b < b) {
		b = a - b;
	}
	answer = 1;
	for (int i = 0; i < b; i++) {
		answer *= a--;
		answer /= (b - i);
	}

	cout << (int)ceil(answer) << '\n';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;

	apart temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		temp.inputData();
		temp.printAnswer();
	}

	return 0;
}