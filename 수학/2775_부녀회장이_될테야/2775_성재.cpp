#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

class apart {
	int k, n;
	long long int answer;

public:
	void inputData();
	void printAnswer();
};

void apart::inputData() {
	cin >> k >> n;
}

void apart::printAnswer() {
	int a, b;

	a = k + n;
	b = k + 1;
	if (a - b < b) {
		b = a - b;
	}
	answer = 1;
	for (int i = 0; i < b; i++) {
		answer *= a--;
	}
	for (int i = 0; i < b; i++) {
		answer /= (b - i);
	}
	cout << answer << '\n';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;

	apart temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		temp.inputData();
		temp.printAnswer();
	}

	return 0;
}