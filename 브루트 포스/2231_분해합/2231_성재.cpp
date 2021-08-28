#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class num {
	int n;

public:
	void inputData();   // ������ �Է�
	void answer();      // ��� ��� �� ���
};

void num::inputData() {  // ������ �Է�
	cin >> n;
}

void num::answer() {   // ��� ��� �� ���
	int num_temp, num_temp2, sum;

	for (int i = 1; i < n; i++) {   // 1���� ��� ����� �� �˻�
		num_temp = i;
		num_temp2 = (int)pow(10, (int)log10(i));
		sum = 0;

		while (num_temp) {   // �� �ڸ��� �� ���
			sum += num_temp / num_temp2;
			num_temp %= num_temp2;
			num_temp2 /= 10;
		}

		if (sum + i == n) {   // �� �ڸ��� �� + ���� �˻��ϴ� ���� n�� ������ �������̹Ƿ� ��� �� �Լ� ����
			cout << i;
			return;
		}
	}

	cout << 0;    // �����ڰ� �����Ƿ� 0 ���
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	num temp;
	temp.inputData();
	temp.answer();

	return 0;
}