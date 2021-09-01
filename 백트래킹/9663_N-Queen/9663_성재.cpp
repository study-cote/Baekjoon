#include <iostream>
using std::cin;
using std::cout;

class nQueen {
	int n, result, dif;
	bool is_empty;

	void inputData();         // ������ �Է�
	void func(bool**, int);   // ��Ʈ��ŷ �Լ�

public:
	nQueen() : result(0) {}   // ������

	void answer();   // �Լ� ���� �� ���
};

void nQueen::inputData() {   // ������ �Է�
	cin >> n;
}

void nQueen::func(bool** arr, int cur) {   // ��Ʈ��ŷ �Լ�
	if (cur < n) {   // �˻��� ���� ������ ��
		for (int i = 0; i < n; i++) {   // �� ���� ���� �� �� �ִ��� �˻�
			is_empty = true;
			for (int j = 0; j < cur; j++) {   // ���� �ຸ�� �տ� �࿡�� ���� ��ġ���� �˻�
				if (arr[j][i]) {        // ���� ���� ���� ���
					is_empty = false;
					break;
				}
				dif = cur - j;
				if (i - dif > -1 && arr[j][i - dif]) {   // ���� �� �밢���� ���� ���
					is_empty = false;
					break;
				}
				if (i + dif < n && arr[j][i + dif]) {   // ������ �� �밢���� ���� ���
					is_empty = false;
					break;
				}
			}
			if (is_empty) {    // ������ ��� ��� ������ ���
				arr[cur][i] = true;   // �� ��ġ
				func(arr, cur + 1);   // ���� �� �˻�
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

	bool** arr;
	arr = new bool*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = false;
		}
	}

	func(arr, 0);

	cout << result;   // ��� �� ���
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	nQueen temp;
	temp.answer();

	return 0;
}