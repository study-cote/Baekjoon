#include <iostream>
using std::cin;
using std::cout;

class findFrac {
	int x, count, sum;

public:
	findFrac(int n) : x(n), count(1), sum(1) {   // ������, n�� �Է°�
		
	}
	void answer();  // ����� ���ϴ� �Լ�
};

void findFrac::answer() {  // ����� ���ϴ� �Լ�
	for (;;count++) {   // count�� sum�� ���� �����ڿ��� 1�� �ʱ�ȭ ��
		sum += count;
		if (x < sum) {
			break;
		}
	}

	if (count % 2) {     // Ȧ�� ��° �밢���� ���
		cout << sum - x << '/' << count + 1 - (sum - x);
	}
	else {   // ¦�� ��° �밢���� ���
		cout << count + 1 - (sum - x) << '/' << sum - x;
	}
}

int main(void) {
	int x;

	cin >> x;
	findFrac temp(x);
	temp.answer();

	return 0;
}