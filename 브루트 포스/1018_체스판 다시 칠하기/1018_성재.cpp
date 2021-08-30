#include <iostream>
using std::cin;
using std::cout;

class chess {
	int n, m;
	char** arr;
	char color[2] = { 'B', 'W' };

public:
	void inputData();    // 데이터 입력
	void answer();       // 결과 계산 및 출력
};

void chess::inputData() {  // 데이터 입력
	cin >> n >> m;

	arr = new char*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[m];
		for (int j = 0; j < m; j++) {     // 배열 입력
			cin >> arr[i][j];
		}
	}
}

void chess::answer() {
	bool is_white = false;
	int sum, min = 65;

	for (int i = 0; i < n - 7; i++) {      // 검사 시작지점 반복문
		for (int j = 0; j < m - 7; j++) {
			sum = 0;    // w로 시작하는 체스판과의 불일치 수를 세는 변수
			for (int row = i; row < i + 8; row++) {     // 8*8 체스판 검사
				for (int col = j; col < j + 8; col++) {
					if (arr[row][col] == color[is_white]) {    // b로 시작하는 체스판과 일치하는지 검사
						sum++;   // w 시작은 자동으로 불일치
					}
					is_white = !is_white;
				}
				is_white = !is_white;
			}
			if (min > sum) {
				min = sum;
			}
			if (min > 64 - sum) {    // b로 시작하는 체스판과의 불일치 수는 w시작과 정 반대
				min = 64 - sum;
			}
			if (!min) {    // 새로 칠해야 하는 정사각형이 없는 체스판이 있을 경우 더 검사할 필요 없음
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