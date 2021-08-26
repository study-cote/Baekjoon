#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class circle {
	int r;

public:
	circle(int data) : r(data) {}   // 생성자

	void answer();   // 결과 계산 및 출력
};

void circle::answer() {    // 결과 계산 및 출력
	cout << std::fixed;    // 소수점 아래부터 숫자 고정
	cout.precision(4);     // 소수점 아래 4자리 고정
	cout << std::atan(1) * 4 * r * r << '\n';   // atan(1)*4 = pi
	cout << r * r * 2 << '\n';
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int r;

	cin >> r;
	circle temp(r);
	temp.answer();

	return 0;
}