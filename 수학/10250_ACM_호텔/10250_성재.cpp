#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;
using std::ios_base;

class hotel {
	int h, w, n;

public:
	void inputData();    // ������ �Է�
	void printAnswer();  // ����� ��� �� ���
};

void hotel::inputData() {  // ������ �Է�
	cin >> h >> w >> n;
}

void hotel::printAnswer() {   // ����� ��� �� ���
	if (n % h) {            // ���� ���
		cout << n % h;
	}
	else {
		cout << h;
	}
	cout.width(2);         // ȣ�� ��½� 2�ڸ� Ȯ��
	cout << (int)ceil((double)n / h);   // �Ҽ��� �Ʒ� �ø�
	cout << '\n';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	hotel temp;
	cin >> T;
	cout.fill('0');      // ȣ�� ��� �� �� �ڸ��� 0 ä������
	for (int i = 0; i < T; i++) {
		temp.inputData();    // h, w, n �Է�
		temp.printAnswer();  // ��� ���
	}

	return 0;
}