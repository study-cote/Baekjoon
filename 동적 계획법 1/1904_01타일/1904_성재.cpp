#include <iostream>
using std::cin;
using std::cout;

class tile {
	int n;
	int a, b, c;

	void inputData();   // 데이터 입력
	void cal();   // 계산
	void printData();   // 결과 출력

public:
	void func();   // 함수 실행
};

void tile::inputData() {   // 데이터 입력
	cin >> n;
}

void tile::cal() {   // 계산
	a = 1;
	b = 2;

	for (int i = 1; i < n; i++) {
		c = (a + b) % 15746;
		a = b;
		b = c;
	}

}

void tile::printData() {   // 결과 출력
	cout << a;
}

void tile::func() {   // 함수 실행
	inputData();

	cal();
	
	printData();
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	tile temp;
	temp.func();

	return 0;
}