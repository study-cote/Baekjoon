#include <iostream>
using std::cin;
using std::cout;

class func {
	int a, b, c;

public:
	void input();    // 데이터 입력
	void cal();      // 결과값 계산
};

void func::input() {   // 데이터 입력
	cin >> a >> b >> c;
}

void func::cal() {   // 결과 값 계산
	if (b < c) {    // 판매비용이 가변비용보다 높을때만 계산
		cout << a / (c - b) + 1;    // 이익이 발생해야 하므로 +1
	}
	else {    // 판매비용이 가변비용보다 낮을때는 이익이 발생할 수 없음
		cout << -1;
	}
}

int main(void) {
	func temp;

	temp.input();
	temp.cal();

	return 0;
}