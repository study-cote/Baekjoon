#include <iostream>
using std::cin;
using std::cout;

class progression {
	int n, m;

	void inputData();       // ������ �Է�
	void func(int*, int);   // ��Ʈ��ŷ

public:
	void answer();   // �Լ� ���� �� �ʱ�ȭ
};

void progression::inputData() {  // ������ �Է�
	cin >> n >> m;
}

void progression::func(int* arr, int cur) {   // ��Ʈ��ŷ
	if (cur < m) {
		for (int i = 0; i < n; i++) {    // ������ ����� ���� ���� ǥ�� �� ���� ������ ������ �Լ� ����
			arr[cur] = i + 1;
			func(arr, cur + 1);
		}
	}
	else {   // ���
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
}

void progression::answer() {    // �Լ� ���� �� �ʱ�ȭ
	inputData();
	int* arr = new int[m];
	func(arr, 0);
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	progression temp;
	temp.answer();

	return 0;
}