#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class circle {
	int r;

public:
	circle(int data) : r(data) {}   // ������

	void answer();   // ��� ��� �� ���
};

void circle::answer() {    // ��� ��� �� ���
	cout << std::fixed;    // �Ҽ��� �Ʒ����� ���� ����
	cout.precision(4);     // �Ҽ��� �Ʒ� 4�ڸ� ����
	cout << std::atan(1) * 4 * r * r << '\n';   // atan(1)*4 = pi
	cout << r * r * 2 << '\n';
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int r;

	cin >> r;
	circle temp(r);
	temp.answer();

	return 0;
}