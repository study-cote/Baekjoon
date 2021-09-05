#include <iostream>
using std::cin;
using std::cout;

class sudoku {
	const int arr_size = 9;
	int board[9][9], row_num[9][10], col_num[9][10], box_num[3][3][10];
	bool find_answer;

	void inputData();    // 데이터 입력
	void backtracking(int, int);   // 백트래킹

public:
	sudoku() : find_answer(false) {   // 생성자
		for (int i = 0; i < arr_size; i++) {   // 배열 초기화
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

	void answer();   // 함수 실행
};

void sudoku::inputData() {   // 데이터 입력
	for (int i = 0; i < arr_size; i++) {
		for (int j = 0; j < arr_size; j++) {
			cin >> board[i][j];

			if (board[i][j]) {
				row_num[i][board[i][j]] = 1;    // 행에 해당 숫자가 존재함을 표시
				col_num[j][board[i][j]] = 1;    // 열에 해당 숫자가 존재함을 표시
				box_num[i / 3][j / 3][board[i][j]] = 1;   // 박스에 해당 숫자가 존재함을 표시
			}
		}
	}
}

void sudoku::backtracking(int row, int col) {   // 백트래킹
	for (row; row < arr_size; row++) {
		for (col; col < 9; col++) {
			if (!board[row][col]) {    // 0으로 표시된 빈칸
				for (int i = 1; i < 10 && !find_answer; i++) {
					if (!row_num[row][i] && !col_num[col][i] && !box_num[row / 3][col / 3][i]) {    // 1 ~ 9 중 행,열,박스에 존재하지 않는 숫자일 경우
						row_num[row][i] = 1;
						col_num[col][i] = 1;
						box_num[row / 3][col / 3][i] = 1;
						board[row][col] = i;
						backtracking(row, col + 1);    // 숫자 하나 입력 후 다음 빈칸에 진행
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

	find_answer = true;     // 답 찾았을 경우 함수 종료를 위한 조건 갱신

	for (int i = 0; i < arr_size; i++) {    // 결과 출력
		for (int j = 0; j < arr_size; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void sudoku::answer() {   // 함수 실행
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