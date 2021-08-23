#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class primeFactor {
	const int arr_size = 10000;
	int T, n;
	bool* arr;

	void cal();          // 에라토스테네스의 체
	void printAnswer();  // 결과 출력

public:
	primeFactor(int data) : T(data) {   // 생성자
		arr = new bool[arr_size];
		for (int i = 2; i < arr_size; i++) {   // 배열 초기화
			arr[i] = true;
		}
	}
	~primeFactor() {   // 소멸자
		delete[] arr;
	}

	void inputData();   // 데이터 입력
};

void primeFactor::cal() {          // 에라토스테네스의 체
	int max = (int)sqrt(arr_size);     // 최소 자기 제곱으로 검사하므로 루트(n)이후의 값은 앞에서 걸러지는게 전부임

	for (int i = 4; i < arr_size; i += 2) {       // 짝수는 2의 배수로 다 걸러지므로 따로 계산
		arr[i] = false;
	}

	int temp;
	for (int i = 3; i <= max; i++) {   // 3 이상의 소수부터 검사
		if (arr[i]) {     // 소수일 경우만 검사
			temp = i * 2;
			for (int j = i * i; j < arr_size; j += temp) {    // 자기자신보다 적은 소수의 곱은 이미 걸러졌으므로 자기자신부터 시작, 짝수는 이미 걸러졌으므로 홀수의 곱만
				arr[j] = false;
			}
		}
	}
}

void primeFactor::printAnswer() {     // 결과 출력
	for (int i = n / 2; i > 1; i--) {
		if (arr[i] && arr[n - i]) {
			cout << i << ' ' << n - i << '\n';
			break;
		}
	}
}

void primeFactor::inputData() {   // 데이터 입력
	cal();

	for (int i = 0; i < T; i++) {
		cin >> n;
		printAnswer();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int T;

	cin >> T;
	primeFactor temp(T);
	temp.inputData();

	return 0;
}