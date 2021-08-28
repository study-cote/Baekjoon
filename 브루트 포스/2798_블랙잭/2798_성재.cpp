#include <iostream>
using std::cin;
using std::cout;

class blackJack {
	int n, m, max, sum;
	int* arr;

public:
	~blackJack() {       // 소멸자
		delete[] arr;
	}

	void inputData();    // 데이터 입력
	void answer();       // 결과 계산 및 출력
};

void blackJack::inputData() {   // 데이터 입력
	cin >> n >> m;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void blackJack::answer() {   // 결과 계산 및 출력
	max = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum == m) {    // 합이 m과 같을 경우 최대이므로 출력 후 함수 종료
					cout << m;
					return;
				}
				if (sum < m && sum > max) {   // 합이 저장된 최대 합보다 클 경우 갱신
					max = sum;
				}
			}
		}
	}
	cout << max;
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	blackJack temp;
	temp.inputData();
	temp.answer();

	return 0;
}