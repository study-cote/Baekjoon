#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class snail {
	int a, b, v;

public:
	snail(int x, int y, int z) :a(x), b(y), v(z) {  // ������

	}

	void answer(); // �� ���
};

void snail::answer() { // �� ���
	cout << (int)ceil((double)(v - b) / (a - b));   // �Ҽ��� �Ʒ� �ø�
}

int main(void) {
	int a, b, v;

	cin >> a >> b >> v; // �Է�
	snail temp(a, b, v); // ��ü ����
	temp.answer(); // �� ��� �Լ� ȣ��

	return 0;
}