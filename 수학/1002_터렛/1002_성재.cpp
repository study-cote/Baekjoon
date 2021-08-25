#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class turret {
	int T, x1, y1, r1, x2, y2, r2;
	double r3;

	void inputData();       // ������ �Է�
	void swap(int&, int&);  // ���� 2�� ��ȯ

public:
	void answer();          // ��� ��� �� ���
};

void turret::inputData() {   // ������ �Է�
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
}

void turret::swap(int& a, int& b) {   // ���� 2�� ��ȯ
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void turret::answer() {   // ��� ��� �� ���
	cin >> T;

	for (int i = 0; i < T; i++) {
		inputData();   // ������ �Է�

		r3 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));   // �� �� ���� �Ÿ� ���
		if (r1 > r2) {     // ���Ǹ� ���� r2�� ū ���� ����
			swap(r1, r2);
		}

		if (x1 == x2 && y1 == y2 && r1 == r2) {   // ���� �߽�, �������� ���� ���
			cout << -1 << '\n';
		}
		else if (r3 > r1 + r2) {   // �� ���� �Ÿ��� �������� �պ��� ū ���
			cout << 0 << '\n';
		}
		else if (r3 == r1 + r2) {  // �� ���� �Ÿ��� �������� �հ� ���� ���
			cout << 1 << '\n';
		}
		else if (r2 == r1 + r3) {  // ���� ���� ū ���� ���ο��� �� ���� �´��� ���
			cout << 1 << '\n';
		}
		else if (r2 > r1 + r3) {   // ���� ���� ū ���� ���ο� ���� ���
			cout << 0 << '\n';
		}
		else {    // �� ���� �� ������ ������ ���
			cout << 2 << '\n';
		}
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	turret temp;
	temp.answer();

	return 0;
}