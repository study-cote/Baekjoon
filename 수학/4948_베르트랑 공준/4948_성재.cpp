#include <iostream>
#include <cmath>
#define arr_size 246912
using std::cin;
using std::cout;

class primeFactor {
	int n, count;
	bool arr[arr_size + 1];
	void cal();      // �����佺�׳׽��� ü
	void answer();   // ����� ���

public:
	primeFactor() {       // ������
		for (int i = 2; i <= arr_size; i++) {    // �迭 �ʱ�ȭ
			arr[i] = true;
		}
	}

	void inputData();      // ������ �Է�
};

void primeFactor::cal() {       // �����佺�׳׽��� ü
	int max = (int)sqrt(arr_size);     // �ּ� �ڱ� �������� �˻��ϹǷ� ��Ʈ(n)������ ���� �տ��� �ɷ����°� ������

	for (int i = 2; i < arr_size; i++) {       // ¦���� 2�� ����� �� �ɷ����Ƿ� ���� ���
		if (2 * i > arr_size) {
			break;
		}
		arr[2 * i] = false;
	}

	int temp;
	for (int i = 3; i <= max; i++) {   // 3 �̻��� �Ҽ����� �˻�
		if (arr[i]) {     // �Ҽ��� ��츸 �˻�
			temp = i * 2;
			for (int j = i * i; j <= arr_size; j += temp) {    // �ڱ��ڽź��� ���� �Ҽ��� ���� �̹� �ɷ������Ƿ� �ڱ��ڽź��� ����, ¦���� �̹� �ɷ������Ƿ� Ȧ���� ����
				arr[j] = false;
			}
		}
	}
}

void primeFactor::answer() {   // ����� ���
	count = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
		if (arr[i]) {
			count++;
		}
	}

	cout << count << '\n';
}

void primeFactor::inputData() {     // ������ �Է�
	cal();

	cin >> n;
	while (n) {
		answer();
		cin >> n;
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	primeFactor temp;
	temp.inputData();

	return 0;
}