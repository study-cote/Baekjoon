#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class movePlanet {
	int x, y, dif;
	int a;

public:
	movePlanet() {}   // 생성자

	void inputData();      // 데이터 입력
	void printAnswer();    // 결과값 계산 및 출력
};

void movePlanet::inputData() {   // 데이터 입력
	cin >> x >> y;
	dif = y - x;    // 거리 계산
}

void movePlanet::printAnswer() {   // 결과값 계산 및 출력
	a = (int)sqrt(dif);
	
	if (dif == a * a) {
		cout << a * 2 - 1 << '\n';
	}
	else if (dif <= a * (a + 1)) {
		cout << a * 2 << '\n';
	}
	else {
		cout << a * 2 + 1 << '\n';
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int T;
	movePlanet temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		temp.inputData();         // 데이터 입력
		temp.printAnswer();       // 결과 출력
	}

	return 0;
}