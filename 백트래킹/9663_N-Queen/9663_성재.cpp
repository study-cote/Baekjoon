#include <iostream>
using std::cin;
using std::cout;

class nQueen {
	int n, result, dif;
	bool** arr;
	bool is_empty;

	void inputData();         // ������ �Է�
	void func(int);   // ��Ʈ��ŷ �Լ�

public:
	nQueen() : result(0) {}   // ������

	void answer();   // �Լ� ���� �� ���
};

void nQueen::inputData() {   // ������ �Է�
	cin >> n;

	arr = new bool* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = false;
		}
	}
}

void nQueen::func(int cur) {   // ��Ʈ��ŷ �Լ�
	if (cur < n) {   // �˻��� ���� ������ ��
		for (int i = 0; i < n; i++) {   // �� ���� ���� �� �� �ִ��� �˻�
			int j;
			for (j = 0; j < cur; j++) {   // ���� �ຸ�� �տ� �࿡�� ���� ��ġ���� �˻�
				if (arr[j][i]) {        // ���� ���� ���� ���
					break;
				}
				dif = cur - j;
				if (i - dif > -1 && arr[j][i - dif]) {   // ���� �� �밢���� ���� ���
					break;
				}
				if (i + dif < n && arr[j][i + dif]) {   // ������ �� �밢���� ���� ���
					break;
				}
			}
			if (j == cur) {    // ������ ��� ��� ������ ���
				arr[cur][i] = true;   // �� ��ġ
				func(cur + 1);   // ���� �� �˻�
				arr[cur][i] = false;  // �� ����
			}
		}
	}
	else {   // ���� n�� �������� ���
		result++;
	}
}

void nQueen::answer() {
	inputData();

	func(0);

	cout << result;   // ��� �� ���
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	nQueen temp;
	temp.answer();

	return 0;
}