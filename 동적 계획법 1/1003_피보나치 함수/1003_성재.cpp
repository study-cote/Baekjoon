#include <iostream>
using std::cin;
using std::cout;

class fibonacci {
	int T;
	int n;
	int arr[41][2];

	void cal();    // �̸� fibonacci ���
	void inputData();  // ������ �Է�
	void printData();  // ��� ���

public:
	void func();  // �Լ� ����
};

void fibonacci::cal() {   // �̸� fibonacci ���
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}
}

void fibonacci::inputData() {   // ������ �Է�
	cin >> n;
}

void fibonacci::printData() {   // ��� ���
	cout << arr[n][0] << ' ' << arr[n][1] << '\n';
}

void fibonacci::func() {   // �Լ� ����
	cin >> T;

	cal();

	for (int i = 0; i < T; i++) {
		inputData();

		printData();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	fibonacci temp;
	temp.func();

	return 0;
}