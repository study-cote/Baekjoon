#include <iostream>
using std::cin;
using std::cout;

class func {
	int a, b, c;

public:
	void input();
	void cal();
};

void func::input() {
	cin >> a >> b >> c;
}

void func::cal() {
	if (b < c) {
		cout << a / (c - b) + 1;
	}
	else {
		cout << -1;
	}
}

int main(void) {
	func temp;

	temp.input();
	temp.cal();

	return 0;
}