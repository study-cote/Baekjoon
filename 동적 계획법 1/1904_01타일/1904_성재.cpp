#include <iostream>
using std::cin;
using std::cout;

class tile {
	int n;
	int a, b, c;

	void inputData();   // ������ �Է�
	void cal();   // ���
	void printData();   // ��� ���

public:
	void func();   // �Լ� ����
};

void tile::inputData() {   // ������ �Է�
	cin >> n;
}

void tile::cal() {   // ���
	a = 1;
	b = 2;

	for (int i = 1; i < n; i++) {
		c = (a + b) % 15746;
		a = b;
		b = c;
	}

}

void tile::printData() {   // ��� ���
	cout << a;
}

void tile::func() {   // �Լ� ����
	inputData();

	cal();
	
	printData();
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	tile temp;
	temp.func();

	return 0;
}