#include <iostream>
using std::cin;
using std::cout;

class reculsive {
	int a, b, c;
	int arr[21][21][21];

	void cal();     // 모든 값 계산
	void inputData();   // 데이터 입력
	void printData();   // 결과 출력

public:
	void func();   // 함수 실행
};

void reculsive::cal() {    // 모든 값 계산
	arr[0][0][0] = 1;
	for (int i = 0; i < 21; i++) {    // if a <= 0 or b <= 0 or c <= 0  ->  result = 0
		for (int j = 1; j < 21; j++) {
			arr[i][j][0] = 1;
			arr[0][i][j] = 1;
			arr[j][0][i] = 1;
		}
	}

	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k < 21; k++) {
				arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
			}
		}
		for (int j = i + 1; j < 21; j++) {
			for (int k = 1; k <= j; k++) {
				arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
			}
			for (int k = j + 1; k < 21; k++) {    // if a < b and b < c
				arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
			}
		}
	}
}

void reculsive::inputData() {   // 데이터 입력
	cin >> a >> b >> c;
}

void reculsive::printData() {   // 결과 출력
	cout << "w(" << a << ", " << b << ", " << c << ") = ";
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		cout << arr[20][20][20];
	}
	else {
		cout << arr[a][b][c];
	}
	cout << '\n';
}

void reculsive::func() {    // 함수 실행
	cal();

	inputData();
	while (a != -1 || b != -1 || c != -1) {
		printData();

		inputData();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	reculsive temp;
	temp.func();

	return 0;
}