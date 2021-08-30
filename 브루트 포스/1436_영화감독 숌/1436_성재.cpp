#include <iostream>
using std::cin;
using std::cout;

class movie {
	int n;

public:
	void inputData();    // ������ �Է�
	void answer();       // ��� ��� �� ���
};

void movie::inputData() {    // ������ �Է�
	cin >> n;
}

void movie::answer() {   // ��� ��� �� ���
	int i, count, num, temp;

	for (i = 666; n; i++) {
		count = 0, num = i, temp = 100000000;
		
		while (num) {
			if (num / temp == 6) {   // ���� ū �ڸ����� 6�� ���
				count++;   // ���ӵ� 6 ���� ����
			}
			else {   // �ѹ��̶� ���� ��� �ʱ�ȭ
				count = 0;
			}
			if (count > 2) {   // ���ӵ� 6�� 3�� �̻��� ���
				n--;   // ã�ƾ� �� ������ ���� ���� ����
				break;
			}

			num %= temp;
			temp /= 10;
		}
	}

	cout << i - 1;    // for�� ���� ���� i�� �����ϹǷ� -1�� �����
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	movie temp;
	temp.inputData();
	temp.answer();

	return 0;
}