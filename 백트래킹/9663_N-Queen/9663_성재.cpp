#include <iostream>
using std::cin;
using std::cout;

class nQueen {
	int n, result, dif;
	bool** arr;
	bool is_empty;

	void inputData();         // 데이터 입력
	void func(int);   // 백트래킹 함수

public:
	nQueen() : result(0) {}   // 생성자

	void answer();   // 함수 실행 및 출력
};

void nQueen::inputData() {   // 데이터 입력
	cin >> n;

	arr = new bool* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = false;
		}
	}
}

void nQueen::func(int cur) {   // 백트래킹 함수
	if (cur < n) {   // 검사할 행이 남았을 때
		for (int i = 0; i < n; i++) {   // 각 열에 퀸이 들어갈 수 있는지 검사
			int j;
			for (j = 0; j < cur; j++) {   // 현재 행보다 앞에 행에서 퀸이 겹치는지 검사
				if (arr[j][i]) {        // 같은 열에 있을 경우
					break;
				}
				dif = cur - j;
				if (i - dif > -1 && arr[j][i - dif]) {   // 왼쪽 위 대각선에 있을 경우
					break;
				}
				if (i + dif < n && arr[j][i + dif]) {   // 오른쪽 위 대각선에 있을 경우
					break;
				}
			}
			if (j == cur) {    // 세가지 경우 모두 없었을 경우
				arr[cur][i] = true;   // 퀸 배치
				func(cur + 1);   // 다음 행 검사
				arr[cur][i] = false;  // 퀸 제거
			}
		}
	}
	else {   // 퀸이 n개 놓아졌을 경우
		result++;
	}
}

void nQueen::answer() {
	inputData();

	func(0);

	cout << result;   // 결과 값 출력
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	nQueen temp;
	temp.answer();

	return 0;
}