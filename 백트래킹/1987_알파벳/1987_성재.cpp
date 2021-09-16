#include <iostream>
using std::cin;
using std::cout;

class alphabet {
	int r, c;
	int** data;
	bool visit[26];
	int max = 0;

	void inputData();   // ������ �Է�
	void backTracking(int, int, int);   // ��Ʈ��ŷ
	void printData();   // ��� ���

public:
	~alphabet() {   // �Ҹ���
		for (int i = 0; i < r; i++) {
			delete[] data[i];
		}
		delete[] data;
	}

	void func();   // �Լ� ����
};

void alphabet::inputData() {   // ������ �Է�
	cin >> r >> c;

	char ch;
	data = new int* [r];
	for (int i = 0; i < r; i++) {
		data[i] = new int[c];
		for (int j = 0; j < c; j++) {
			cin >> ch;
			data[i][j] = ch - 'A';
		}
	}
	for (int i = 0; i < 26; i++) {
		visit[i] = false;
	}

	visit[data[0][0]] = true;
}

void alphabet::backTracking(int row, int col, int sum) {   // ��Ʈ��ŷ
	if (sum > max) {
		max = sum;
	}

	if (row > 0 && !visit[data[row - 1][col]]) {
		visit[data[row - 1][col]] = true;
		backTracking(row - 1, col, sum + 1);
		visit[data[row - 1][col]] = false;
	}
	if (row < r - 1 && !visit[data[row + 1][col]]) {
		visit[data[row + 1][col]] = true;
		backTracking(row + 1, col, sum + 1);
		visit[data[row + 1][col]] = false;
	}
	if (col > 0 && !visit[data[row][col - 1]]) {
		visit[data[row][col - 1]] = true;
		backTracking(row, col - 1, sum + 1);
		visit[data[row][col - 1]] = false;
	}
	if (col < c - 1 && !visit[data[row][col + 1]]) {
		visit[data[row][col + 1]] = true;
		backTracking(row, col + 1, sum + 1);
		visit[data[row][col + 1]] = false;
	}
}

void alphabet::printData() {   // ��� ���
	cout << max;
}

void alphabet::func() {   // �Լ� ����
	inputData();

	backTracking(0, 0, 1);

	printData();
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	alphabet temp;
	temp.func();

	return 0;
}