#include <iostream>
using std::cin;
using std::cout;

class func {
	int a, b, c;

public:
	void input();    // ������ �Է�
	void cal();      // ����� ���
};

void func::input() {   // ������ �Է�
	cin >> a >> b >> c;
}

void func::cal() {   // ��� �� ���
	if (b < c) {    // �Ǹź���� ������뺸�� �������� ���
		cout << a / (c - b) + 1;    // ������ �߻��ؾ� �ϹǷ� +1
	}
	else {    // �Ǹź���� ������뺸�� �������� ������ �߻��� �� ����
		cout << -1;
	}
}

int main(void) {
	func temp;

	temp.input();
	temp.cal();

	return 0;
}