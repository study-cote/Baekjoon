#include <iostream>
using std::cin;
using std::cout;

class sudoku {
	const int arr_size = 9;
	int** arr;
	bool find_answer, num;
	int row_start, col_start;

	void inputData();
	void backtracking(int, int);

public:
	sudoku() : find_answer(false) {
		arr = new int* [arr_size];
		for (int i = 0; i < arr_size; i++) {
			arr[i] = new int[arr_size];
		}
	}

	void answer();
};

void sudoku::inputData() {
	for (int i = 0; i < arr_size; i++) {
		for (int j = 0; j < arr_size; j++) {
			cin >> arr[i][j];
		}
	}
}

void sudoku::backtracking(int row, int col) {
	for (row; row < 9 && !find_answer; row++) {
		for (col; col < 9 && !find_answer; col++) {
			if (!arr[row][col]) {
				for (int i = 1; i < 10; i++) {
					num = true;
					for (int j = 0; j < 9; j++) {
						if (arr[row][j] == i) {
							num = false;
							break;
						}
						if (arr[j][col] == i) {
							num = false;
							break;
						}
					}
					row_start = row / 3 * 3;
					col_start = col / 3 * 3;
					for (int j = row_start; j < row_start + 3; j++) {
						for (int k = col_start; k < col_start + 3; k++) {
							if (arr[j][k] == i) {
								num = false;
								break;
							}
						}
					}
					if (num) {
						arr[row][col] = i;
						backtracking(row, col + 1);
						arr[row][col] = 0;
					}
				}
				return;
			}
		}
		col = 0;
	}
	if (!find_answer) {
		find_answer = true;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}

void sudoku::answer() {
	inputData();

	backtracking(0, 0);
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	sudoku temp;
	temp.answer();

	return 0;
}