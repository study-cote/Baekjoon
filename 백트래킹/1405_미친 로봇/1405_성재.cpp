#include <iostream>
using std::cin;
using std::cout;

class robot {
	int n;
	bool** arr;
	long double probability[4];
	long double sum = 0;

	void inputData();    // ������ �Է�
	void backtracking(int, int, int, long double);  // ��Ʈ��ŷ
	void printData();    // ��� ���

public:
	~robot() {   // �Ҹ���
		for (int i = 0; i < n * 2 + 1; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	void func();   // �Լ� ȣ��
};

void robot::inputData() {   // ������ �Է�
	cin >> n;

	arr = new bool* [n * 2 + 1];
	for (int i = 0; i < n * 2 + 1; i++) {
		arr[i] = new bool[n * 2 + 1];
		for (int j = 0; j < n * 2 + 1; j++) {
			arr[i][j] = false;
		}
	}
	arr[n][n] = 1;

	int temp;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		probability[i] = (long double)temp / 100;
	}
}

void robot::backtracking(int row, int col, int remain, long double cur) {   // ��Ʈ��ŷ
	if (!remain) {
		sum += cur;
		return;
	}

	if (!arr[row][col + 1]) {    // ��
		arr[row][col + 1] = true;
		backtracking(row, col + 1, remain - 1, cur * probability[0]);
		arr[row][col + 1] = false;
	}
	if (!arr[row][col - 1]) {    // ��
		arr[row][col - 1] = true;
		backtracking(row, col - 1, remain - 1, cur * probability[1]);
		arr[row][col - 1] = false;
	}
	if (!arr[row - 1][col]) {    // ��
		arr[row - 1][col] = true;
		backtracking(row - 1, col, remain - 1, cur * probability[2]);
		arr[row - 1][col] = false;
	}
	if (!arr[row + 1][col]) {    // ��
		arr[row + 1][col] = true;
		backtracking(row + 1, col, remain - 1, cur * probability[3]);
		arr[row + 1][col] = false;
	}
}

void robot::printData() {   // ��� ���
	cout << std::fixed;
	cout.precision(9);
	cout << sum;
}

void robot::func() {  // �Լ� ȣ��
	inputData();

	backtracking(n, n, n, 1);

	printData();
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	robot temp;
	temp.func();

	return 0;
}