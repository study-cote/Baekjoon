#include <iostream>
using std::cin;
using std::cout;

class robot {
	int n;
	bool** arr;
	long double probability[4];
	long double sum = 0;

	void inputData();    // 데이터 입력
	void backtracking(int, int, int, long double);  // 백트래킹
	void printData();    // 결과 출력

public:
	~robot() {   // 소멸자
		for (int i = 0; i < n * 2 + 1; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	void func();   // 함수 호출
};

void robot::inputData() {   // 데이터 입력
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

void robot::backtracking(int row, int col, int remain, long double cur) {   // 백트래킹
	if (!remain) {
		sum += cur;
		return;
	}

	if (!arr[row][col + 1]) {    // 동
		arr[row][col + 1] = true;
		backtracking(row, col + 1, remain - 1, cur * probability[0]);
		arr[row][col + 1] = false;
	}
	if (!arr[row][col - 1]) {    // 서
		arr[row][col - 1] = true;
		backtracking(row, col - 1, remain - 1, cur * probability[1]);
		arr[row][col - 1] = false;
	}
	if (!arr[row - 1][col]) {    // 남
		arr[row - 1][col] = true;
		backtracking(row - 1, col, remain - 1, cur * probability[2]);
		arr[row - 1][col] = false;
	}
	if (!arr[row + 1][col]) {    // 북
		arr[row + 1][col] = true;
		backtracking(row + 1, col, remain - 1, cur * probability[3]);
		arr[row + 1][col] = false;
	}
}

void robot::printData() {   // 결과 출력
	cout << std::fixed;
	cout.precision(9);
	cout << sum;
}

void robot::func() {  // 함수 호출
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