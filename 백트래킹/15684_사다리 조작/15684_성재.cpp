#include <iostream>
using std::cin;
using std::cout;

class ladder {
	int n, m, h, min = 4;
	int** arr, ** num, * result;

	void inputData();    // ������ �Է�
	void backtracking(int, int, int);     // ��Ʈ��ŷ
	void swap(int&, int&);   // ������ ��ȯ
	void printData();    // ��� ���

public:
	void func();   // �Լ� ���� �� �迭 �ʱ�ȭ
};

void ladder::inputData() {    // ������ �Է�
	cin >> n >> m >> h;

	arr = new int* [h + 1];
	num = new int* [h + 1];
	result = new int[n + 1];
	for (int i = 1; i <= h; i++) {
		arr[i] = new int[n + 1];
		for (int j = 0; j <= n; j++) {
			arr[i][j] = 0;
		}
		num[i] = new int[n + 1];
	}
	int a, b;
	for (int i = 0; i < m; i++) {   // �Է�
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		result[i] = i;
	}
}

void ladder::backtracking(int row, int col, int cur) {    // ��Ʈ��ŷ
	int i;
	for (i = 1; i <= n; i++) {     // ���� ��ȣ�� ������ üũ
		if (num[h][result[i]] != i) {
			break;
		}
	}
	if (i > n) {   // ���� ���� ��ȣ�� ������ ��
		if (cur < min) {   // �ּҰ� ����
			min = cur;
		}
		return;
	}
	if (cur >= 3) {    // �߰� �������� 3���� ���� ����
		return;
	}

	for (row; row <= h; row++) {
		for (col; col < n;col++) {
			if (!arr[row][col] && !arr[row][col - 1] && !arr[row][col + 1]) {     // �� ���� �������� ���� ��
				swap(result[num[row][col]], result[num[row][col + 1]]);
				arr[row][col] = 1;
				backtracking(row, col + 1, cur + 1);
				swap(result[num[row][col]], result[num[row][col + 1]]);
				arr[row][col] = 0;
			}
		}
		col = 0;
	}
}

void ladder::swap(int& a, int& b) {   // ������ ��ȯ
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void ladder::func() {  // �Լ� ���� �� �迭 �ʱ�ȭ
	inputData();

	int cur;
	for (int i = 1; i <= n; i++) {
		cur = i;
		for (int j = 1; j <= h; j++) {
			if (cur > 1 && arr[j][cur - 1]) {
				cur--;
			}
			else if (cur < n && arr[j][cur]) {
				cur++;
			}
			num[j][cur] = i;
		}
	}

	backtracking(1, 1, 0);

	printData();
}

void ladder::printData() {   // ��� ���
	if (min > 3) {    // 3�� �̳��� �Ұ����� ��
		cout << -1;
	}
	else {    // 3�� �̳��� ������ �� �ּҰ� ���
		cout << min;
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	ladder temp;
	temp.func();

	return 0;
}