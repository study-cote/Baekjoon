#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;

class hotel {
	int h, w, n;

public:
	void inputData();
	void printAnswer();
};

void hotel::inputData() {
	cin >> h >> w >> n;
}

void hotel::printAnswer() {
	if (n % h) {
		cout << n % h;
	}
	else {
		cout << h;
	}
	cout.width(2);
	cout << (int)ceil((double)n / h);
	cout << '\n';
}

int main(void) {
	int T;

	hotel temp;
	cin >> T;
	cout.fill('0');
	for (int i = 0; i < T; i++) {
		temp.inputData();
		temp.printAnswer();
	}

	return 0;
}