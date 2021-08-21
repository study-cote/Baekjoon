#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class snail {
	int a, b, v;

public:
	snail(int x, int y, int z) :a(x), b(y), v(z) {  // 생성자

	}

	void answer(); // 답 출력
};

void snail::answer() { // 답 출력
	cout << (int)ceil((double)(v - b) / (a - b));   // 소수점 아래 올림
}

int main(void) {
	int a, b, v;

	cin >> a >> b >> v; // 입력
	snail temp(a, b, v); // 객체 생성
	temp.answer(); // 답 출력 함수 호출

	return 0;
}