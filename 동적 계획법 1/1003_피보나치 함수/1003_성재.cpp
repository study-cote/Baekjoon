#include <iostream>
using std::cin;
using std::cout;

class fibonacci {
	int T;
	int n;
	int arr[41][2];

	void cal();    // 미리 fibonacci 계산
	void inputData();  // 데이터 입력
	void printData();  // 결과 출력

public:
	void func();  // 함수 실행
};

void fibonacci::cal() {   // 미리 fibonacci 계산
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}
}

void fibonacci::inputData() {   // 데이터 입력
	cin >> n;
}

void fibonacci::printData() {   // 결과 출력
	cout << arr[n][0] << ' ' << arr[n][1] << '\n';
}

void fibonacci::func() {   // 함수 실행
	cin >> T;

	cal();

	for (int i = 0; i < T; i++) {
		inputData();

		printData();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	fibonacci temp;
	temp.func();

	return 0;
}