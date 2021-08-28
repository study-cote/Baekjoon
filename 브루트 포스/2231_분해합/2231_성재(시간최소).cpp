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
	int num_temp, sum;

	for (int i = 1; i < n; i++) {   // 1���� ��� ����� �� �˻�
		num_temp = i;
		sum = i;

		sum += num_temp / 100000;
		num_temp %= 100000;
		sum += num_temp / 10000;
		num_temp %= 10000;
		sum += num_temp / 1000;
		num_temp %= 1000;
		sum += num_temp / 100;
		num_temp %= 100;
		sum += num_temp / 10;
		num_temp %= 10;
		sum += num_temp;

		if (sum == n) {   // �����ڸ� ã���� ����
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