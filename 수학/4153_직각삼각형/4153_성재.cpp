#include <iostream>
using std::cin;
using std::cout;

class triangle {
	int a, b, c;

	void inputData();            // 데이터 입력
	void swap(int& a, int& b);   // 숫자 2개 교환

public:
	void answer();               // 결과 계산 및 출력
};

void triangle::inputData() {  // 데이터 입력
	cin >> a >> b >> c;

	if (a > c) {
		if (a > b) {      // a가 제일 큰 수
			swap(a, c);
		}
		else {          // b가 제일 큰 수
			swap(b, c);
		}
	}
	else if (b > c) {   // b가 제일 큰 수
		swap(b, c);
	}   // else 는 c가 이미 제일 큰 수이기 때문에 바꾸지 않음
}

void triangle::swap(int& a, int& b) {   // 숫자 2개 교환
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void triangle::answer() {   // 결과 계산 및 출력
	inputData();
	while (a) {   // 0 0 0 입력 시 종료
		if (a * a + b * b == c * c) {   // 직각삼각형
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
		inputData();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	triangle temp;
	temp.answer();

	return 0;
}