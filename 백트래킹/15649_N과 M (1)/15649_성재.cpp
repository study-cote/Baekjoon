#include <iostream>
using std::cin;
using std::cout;

class progression {
	int n, m;
	int* arr;

	void inputData();       // ������ �Է�
	void func(int);   // ��Ʈ��ŷ

public:
	void answer();   // �Լ� ���� �� �ʱ�ȭ
};

void progression::inputData() {  // ������ �Է�
	cin >> n >> m;
	arr = new int[n];
}

void progression::func(int remain) {   // ��Ʈ��ŷ
	if (remain) {
		for (int i = 0; i < n; i++) {    // ������ ����� ���� ���� ǥ�� �� ���� ������ ������ �Լ� ����
			if (!arr[i]) {
				arr[i] = remain;
				func(remain - 1);
				arr[i] = 0;
			}
		}
	}
	else {   // ���
		remain = m;
		for (; remain; remain--) {
			for (int i = 0; i < n; i++) {
				if (arr[i] == remain) {
					cout << i + 1 << ' ';
					break;
				}
			}
		}
		cout << '\n';
	}
}

void progression::answer() {    // �Լ� ���� �� �ʱ�ȭ
	inputData();
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	func(m);
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	progression temp;
	temp.answer();

	return 0;
}