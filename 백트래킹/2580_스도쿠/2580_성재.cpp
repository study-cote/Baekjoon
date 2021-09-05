#include <iostream>
using std::cin;
using std::cout;

class sudoku {
	const int arr_size = 9;
	int board[9][9], row_num[9][10], col_num[9][10], box_num[3][3][10];
	bool find_answer;

	void inputData();    // ������ �Է�

public:
	sudoku() : find_answer(false) {   // ������
		for (int i = 0; i < arr_size; i++) {   // �迭 �ʱ�ȭ
			for (int j = 1; j < 10; j++) {
				row_num[i][j] = 0;
				col_num[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 1; k < 10; k++) {
					box_num[i][j][k] = 0;
				}
			}
		}
	}

	void answer();   // �Լ� ����
};

void sudoku::inputData() {   // ������ �Է�
	for (int i = 0; i < arr_size; i++) {
		for (int j = 0; j < arr_size; j++) {
			cin >> board[i][j];

			if (board[i][j]) {
				row_num[i][board[i][j]] = 1;    // �࿡ �ش� ���ڰ� �������� ǥ��
				col_num[j][board[i][j]] = 1;    // ���� �ش� ���ڰ� �������� ǥ��
				box_num[i / 3][j / 3][board[i][j]] = 1;   // �ڽ��� �ش� ���ڰ� �������� ǥ��
			}
		}
	}
}

void sudoku::backtracking(int row, int col) {   // ��Ʈ��ŷ
	for (row; row < arr_size; row++) {
		for (col; col < 9; col++) {
			if (!board[row][col]) {    // 0���� ǥ�õ� ��ĭ
				for (int i = 1; i < 10 && !find_answer; i++) {
					if (!row_num[row][i] && !col_num[col][i] && !box_num[row / 3][col / 3][i]) {    // 1 ~ 9 �� ��,��,�ڽ��� �������� �ʴ� ������ ���
						row_num[row][i] = 1;
						col_num[col][i] = 1;
						box_num[row / 3][col / 3][i] = 1;
						board[row][col] = i;
						backtracking(row, col + 1);    // ���� �ϳ� �Է� �� ���� ��ĭ�� ����
						row_num[row][i] = 0;
						col_num[col][i] = 0;
						box_num[row / 3][col / 3][i] = 0;
						board[row][col] = 0;
					}
				}
				return;
			}
		}
		col = 0;
	}

	find_answer = true;     // �� ã���� ��� �Լ� ���Ḧ ���� ���� ����

	for (int i = 0; i < arr_size; i++) {    // ��� ���
		for (int j = 0; j < arr_size; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void sudoku::answer() {   // �Լ� ����
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