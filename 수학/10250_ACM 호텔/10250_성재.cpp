#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;
using std::ios_base;

class hotel {
	int h, w, n;

public:
	void inputData();    // 데이터 입력
	void printAnswer();  // 결과값 계산 및 출력
};

void hotel::inputData() {  // 데이터 입력
	cin >> h >> w >> n;
}

void hotel::printAnswer() {   // 결과값 계산 및 출력
	if (n % h) {            // 층수 계산
		cout << n % h;
	}
	else {
		cout << h;
	}
	cout.width(2);         // 호수 출력시 2자리 확보
	cout << (int)ceil((double)n / h);   // 소수점 아래 올림
	cout << '\n';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	hotel temp;
	cin >> T;
	cout.fill('0');      // 호수 출력 시 빈 자리에 0 채워넣음
	for (int i = 0; i < T; i++) {
		temp.inputData();    // h, w, n 입력
		temp.printAnswer();  // 결과 출력
	}

	return 0;
}