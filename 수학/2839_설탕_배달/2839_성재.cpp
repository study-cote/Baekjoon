#include <iostream>
using std::cin;
using std::cout;

class sugar {
	int n, count;
	
public:
	sugar(int data) : n(data) {}    // ������
	
	void printAnswer();    // ����� ��� �� ���
};

void sugar::printAnswer() {
	switch (n) {
	case 4:          // 3�� 5 �������� n�� ���� �� ����
		cout << -1;
		break;
	case 7:
		cout << -1;
		break;
	default:         // 3�� 5 �������� n ���������
		switch (n % 3) {       // 15a + 3b���·� ��ȯ�ϱ� ���� +@ �� ���� ����
		case 1:             // 15a + 10 + 3b
			n -= 10;
			count = 2;
			break;
		case 2:             // 15a + 5 + 3b
			n -= 5;
			count = 1;
			break;
		default:            // 15a + 3b
			count = 0;
		}
		cout << (n / 15) * 3 + (n % 15) / 3 + count;      // 15a + 3b + @
	}
	
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, count = 0;
	cin >> n;
	sugar temp(n);
	temp.printAnswer();     // ��� ���

	return 0;
}