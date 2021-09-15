#include <iostream>
using std::cin;
using std::cout;

class lotto {
	int n;
	int arr[13][2];

	void inputData();   // ������ �Է�
	void backTracking(int, int);   // ��Ʈ��ŷ
	void printData();   // ��� ���

public:
	void func();   // �Լ� ����
};

void lotto::inputData() {   // ������ �Է�
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0];
		arr[i][1] = 0;
	}
}

void lotto::backTracking(int cur, int remain) {   // ��Ʈ��ŷ
	if (!remain) {
		printData();

		return;
	}

	for (cur; cur <= n - remain; cur++) {
		arr[cur][1] = 1;
		backTracking(cur + 1, remain - 1);
		arr[cur][1] = 0;
	}
}

void lotto::printData() {   // ��� ���
	for (int i = 0; i < n; i++) {
		if (arr[i][1]) {
			cout << arr[i][0] << ' ';
		}
	}
	cout << '\n';
}

void lotto::func() {   // �Լ� ����
	inputData();
	while (n) {
		backTracking(0, 6);

		cout << '\n';

		inputData();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	lotto temp;
	temp.func();

	return 0;
}