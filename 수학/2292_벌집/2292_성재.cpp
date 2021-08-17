#include <iostream>
using std::cin;
using std::cout;

class func {
	int data;

public:
	func(int n) : data(n) {    // 생성자

	}
	void cal();    // 결과 값 계산
};

void func::cal() {   // 결과 값 계산
	int max = 1;

	for (int count = 1; ; count++) {  // 몇 번째 원인지 찾는 변수
		if (data <= max) {
			cout << count;
			break;
		}
		max += (count * 6);
	}
}

int main(void) {
	int n;

	cin >> n;
	func temp(n);
	temp.cal();
	
	return 0;
}