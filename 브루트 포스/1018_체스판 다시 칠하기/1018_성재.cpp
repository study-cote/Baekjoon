#include <iostream>
using std::cin;
using std::cout;

class chess {
	int n, m;
	char** arr;
	char color[2] = { 'B', 'W' };

public:
	void inputData();    // ������ �Է�
	void answer();       // ��� ��� �� ���
};

void chess::inputData() {  // ������ �Է�
	cin >> n >> m;

	arr = new char*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[m];
		for (int j = 0; j < m; j++) {     // �迭 �Է�
			cin >> arr[i][j];
		}
	}
}

void chess::answer() {
	bool is_white = false;
	int sum, min = 65;

	for (int i = 0; i < n - 7; i++) {      // �˻� �������� �ݺ���
		for (int j = 0; j < m - 7; j++) {
			sum = 0;    // w�� �����ϴ� ü���ǰ��� ����ġ ���� ���� ����
			for (int row = i; row < i + 8; row++) {     // 8*8 ü���� �˻�
				for (int col = j; col < j + 8; col++) {
					if (arr[row][col] == color[is_white]) {    // b�� �����ϴ� ü���ǰ� ��ġ�ϴ��� �˻�
						sum++;   // w ������ �ڵ����� ����ġ
					}
					is_white = !is_white;
				}
				is_white = !is_white;
			}
			if (min > sum) {
				min = sum;
			}
			if (min > 64 - sum) {    // b�� �����ϴ� ü���ǰ��� ����ġ ���� w���۰� �� �ݴ�
				min = 64 - sum;
			}
			if (!min) {    // ���� ĥ�ؾ� �ϴ� ���簢���� ���� ü������ ���� ��� �� �˻��� �ʿ� ����
				cout << 0;
				return;
			}
		}
	}

	cout << min;
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	chess temp;
	temp.inputData();
	temp.answer();

	return 0;
}