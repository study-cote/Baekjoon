#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class primeFactor {
	int n;

public:
	primeFactor(int key) : n(key) {}    // ������

	void printAnswer();    // ����� ��� �� ���
};

void primeFactor::printAnswer() {  // ����� ��� �� ���
	int prime = 3, max;
	max = ((int)sqrt(n)) + 1;   // ���μ��� ��Ʈ(n)�� �Ѵ� ���� �ִ� 1��

	while (!(n % 2)) {       // ���μ� �� ¦���� 2�ۿ� �����Ƿ� ���� ���
		cout << 2 << '\n';
		n /= 2;
	}
	while (n > 1 && prime < max) {     // Ȧ���� �Ҽ� ã��
		if (!(n % prime)) {
			cout << prime << '\n';
			n /= prime;
		}
		else {           // Ȧ���� ���Ƿ� +2
			prime += 2;
		}
	}
	if (n > 1) {     // ��Ʈ(n)�� �Ѵ� �Ҽ��� ���� ���
		cout << n;
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	
	cin >> n;
	primeFactor temp(n);
	temp.printAnswer();   // ��� ���

	return 0;
}