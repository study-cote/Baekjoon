#include <iostream>
using std::cin;
using std::cout;

class dwarf {
	int arr[9];

	void sort();      // ����(bubble)
	void swap(int, int);    // �� �� ��ȯ

public:
	void inputData();   // ������ �Է�
	void answer();      // ��� ��� �� ���
};

void dwarf::sort() {    // ����(bubble)
	for (int i = 8; i; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(j, j + 1);
			}
		}
	}
}

void dwarf::swap(int a, int b) {   // �� �� ��ȯ
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void dwarf::inputData() {   // ������ �Է�
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	sort();   // �迭 �������� ����
}

void dwarf::answer() {   // ��� ��� �� ���
	int sum = 0;

	for (int i = 0; i < 9; i++) {    // ���� ���
		sum += arr[i];
	}

	for (int i = 0; i < 8; i++) {    // ���տ��� ���� ���� 100���� �˻�
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {    // �� ���� ���� �� 100�� ��� ��� �� �Լ� ����
				for (int k = 0; k < i; k++) {
					cout << arr[k] << '\n';
				}
				for (int k = i + 1; k < j; k++) {
					cout << arr[k] << '\n';
				}
				for (int k = j + 1; k < 9; k++) {
					cout << arr[k] << '\n';
				}
				return;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	dwarf temp;
	temp.inputData();
	temp.answer();

	return 0;
}