#include <iostream>
using std::cin;
using std::cout;

class algo {
	int n;
	char** arr;
	bool find_ans = false;

	void inputData();
	void backTracking(int, int, int);

public:
	void func();
};

void algo::inputData() {
	cin >> n;
	
	arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void algo::backTracking(int row, int col, int remain) {
	if (!remain) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'T') {
					for (int k = i - 1; k >= 0; k--) {
						if (arr[k][j] == 'O') {
							break;
						}
						else if (arr[k][j] == 'S') {
							return;
						}
					}
					for (int k = i + 1; k < n; k++) {
						if (arr[k][j] == 'O') {
							break;
						}
						else if (arr[k][j] == 'S') {
							return;
						}
					}
					for (int k = j - 1; k >= 0; k--) {
						if (arr[i][k] == 'O') {
							break;
						}
						else if (arr[i][k] == 'S') {
							return;
						}
					}
					for (int k = j + 1; k < n; k++) {
						if (arr[i][k] == 'O') {
							break;
						}
						else if (arr[i][k] == 'S') {
							return;
						}
					}
				}
			}
		}

		find_ans = true;

		return;
	}

	for (row; row < n && !find_ans; row++) {
		for (col; col < n && !find_ans; col++) {
			if (arr[row][col] == 'X') {
				arr[row][col] = 'O';
				backTracking(row, col + 1, remain - 1);
				arr[row][col] = 'X';
			}
		}
		col = 0;
	}
}

void algo::func() {
	inputData();

	backTracking(0, 0, 3);

	if (!find_ans) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	algo temp;
	temp.func();

	return 0;
}