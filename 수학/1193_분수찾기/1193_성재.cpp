#include <iostream>
using std::cin;
using std::cout;

class findFrac {
	int data, count, sum;

public:
	findFrac(int n) : data(n), count(1), sum(1) {   // ������
		
	}
	void answer();  // ����� ���ϴ� �Լ�
};

void findFrac::answer() {  // ����� ���ϴ� �Լ�
	for (;;count++) {      // �� ��° �밢������ ����
		sum += count;
		if (data < sum) {
			break;
		}
	}

	if (count % 2) {     // Ȧ�� ��° �밢���� ���
		cout << sum - data << '/' << count + 1 - (sum - data);
	}
	else {   // ¦�� ��° �밢���� ���
		cout << count + 1 - (sum - data) << '/' << sum - data;
	}
}

int main(void) {
	int num;

	cin >> num;
	findFrac temp(num);
	temp.answer();

	return 0;
}