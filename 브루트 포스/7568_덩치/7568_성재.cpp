#include <iostream>
using std::cin;
using std::cout;

class grade {
	int n;
	int* arr[3];

public:
	void inputData();   // ������ �Է�
	void answer();      // ��� ��� �� ���
};

void grade::inputData() {   // ������ �Է�
	cin >> n;
	arr[0] = new int[n];   // Ű
	arr[1] = new int[n];   // ������
	arr[2] = new int[n];   // ���

	for (int i = 0; i < n; i++) {
		cin >> arr[0][i] >> arr[1][i];   // �Է�
		arr[2][i] = 1;   // �� ��� 1�� �ʱ�ȭ
	}
}

void grade::answer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j]) {    // ���κ��� ��ġ�� ū ����� ������� ��� +1
				arr[2][i]++;
			}
		}

		cout << arr[2][i] << ' ';   // ���
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	grade temp;
	temp.inputData();
	temp.answer();

	return 0;
}