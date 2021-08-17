#include <iostream>
using std::cin;
using std::cout;

class func {
	int data;

public:
	func(int n) : data(n) {

	}
	void cal();
};

void func::cal() {
	int max = 1;

	for (int count = 1; ; count++) {
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