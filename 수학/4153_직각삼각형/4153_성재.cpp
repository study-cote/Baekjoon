#include <iostream>
using std::cin;
using std::cout;

class triangle {
	int a, b, c;

	void inputData();            // ������ �Է�
	void swap(int& a, int& b);   // ���� 2�� ��ȯ

public:
	void answer();               // ��� ��� �� ���
};

void triangle::inputData() {  // ������ �Է�
	cin >> a >> b >> c;

	if (a > c) {
		if (a > b) {      // a�� ���� ū ��
			swap(a, c);
		}
		else {          // b�� ���� ū ��
			swap(b, c);
		}
	}
	else if (b > c) {   // b�� ���� ū ��
		swap(b, c);
	}   // else �� c�� �̹� ���� ū ���̱� ������ �ٲ��� ����
}

void triangle::swap(int& a, int& b) {   // ���� 2�� ��ȯ
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void triangle::answer() {   // ��� ��� �� ���
	inputData();
	while (a) {   // 0 0 0 �Է� �� ����
		if (a * a + b * b == c * c) {   // �����ﰢ��
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
		inputData();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	triangle temp;
	temp.answer();

	return 0;
}