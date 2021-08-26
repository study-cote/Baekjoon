#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class movePlanet {
	int x, y, dif;
	int a;

public:
	movePlanet() {}   // ������

	void inputData();      // ������ �Է�
	void printAnswer();    // ����� ��� �� ���
};

void movePlanet::inputData() {   // ������ �Է�
	cin >> x >> y;
	dif = y - x;    // �Ÿ� ���
}

void movePlanet::printAnswer() {   // ����� ��� �� ���
	a = (int)sqrt(dif);
	
	if (dif == a * a) {
		cout << a * 2 - 1 << '\n';
	}
	else if (dif <= a * (a + 1)) {
		cout << a * 2 << '\n';
	}
	else {
		cout << a * 2 + 1 << '\n';
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int T;
	movePlanet temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		temp.inputData();         // ������ �Է�
		temp.printAnswer();       // ��� ���
	}

	return 0;
}