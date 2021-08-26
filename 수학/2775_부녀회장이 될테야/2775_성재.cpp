#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class apart {
	int k, n;
	long double answer;

public:
	void inputData();         // ������ �Է�
	void printAnswer();       // ����� ��� �� ���
};

void apart::inputData() {   // ������ �Է�
	cin >> k >> n;
}

void apart::printAnswer() {  // ����� ��� �� ���
	int a, b;

	a = k + n;            // (k+n)C(k+1)�� ���� �̿��ؼ� ����ȭ
	b = k + 1;
	if (a - b < b) {
		b = a - b;
	}
	answer = 1;
	for (int i = 0; i < b; i++) {     // aCb ���(combination ���)
		answer *= a--;
		answer /= (b - i);
	}

	cout << (int)ceil(answer) << '\n';    // �Ҽ��� �Ʒ� �ҽǵǴ� �� �ø�
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int T;

	apart temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		temp.inputData();    // ������ �Է�
		temp.printAnswer();  // ��� ���
	}

	return 0;
}