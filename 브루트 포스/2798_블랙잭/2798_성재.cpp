#include <iostream>
using std::cin;
using std::cout;

class blackJack {
	int n, m, max, sum;
	int* arr;

public:
	~blackJack() {       // �Ҹ���
		delete[] arr;
	}

	void inputData();    // ������ �Է�
	void answer();       // ��� ��� �� ���
};

void blackJack::inputData() {   // ������ �Է�
	cin >> n >> m;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void blackJack::answer() {   // ��� ��� �� ���
	max = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum == m) {    // ���� m�� ���� ��� �ִ��̹Ƿ� ��� �� �Լ� ����
					cout << m;
					return;
				}
				if (sum < m && sum > max) {   // ���� ����� �ִ� �պ��� Ŭ ��� ����
					max = sum;
				}
			}
		}
	}
	cout << max;
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	blackJack temp;
	temp.inputData();
	temp.answer();

	return 0;
}