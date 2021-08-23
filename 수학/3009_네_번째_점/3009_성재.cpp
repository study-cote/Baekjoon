#include <iostream>
using std::cin;
using std::cout;

class square {
	int x[3], y[3];

public:
	void inputData();    // ������ �Է�
	void answer();       // ��� ��� �� ���
};

void square::inputData() {   // ������ �Է�
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
}

void square::answer() {   // ��� ��� �� ���
	int a, b;

	if (x[0] == x[1]) {
		a = x[2];
		if (y[0] == y[2]) {
			b = y[1];
		}
		else {
			b = y[0];
		}
	}
	else {
		if (y[0] == y[1]) {
			b = y[2];
			if (x[0] == x[2]) {
				a = x[1];
			}
			else {
				a = x[0];
			}
		}
		else {
			if (y[0] == y[2]) {
				a = x[0];
				b = y[1];
			}
			else {
				a = x[1];
				b = y[0];
			}
		}
	}

	cout << a << ' ' << b;
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	square temp;
	temp.inputData();
	temp.answer();

	return 0;
}