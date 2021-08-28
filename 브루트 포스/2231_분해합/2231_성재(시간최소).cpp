#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class num {
	int n;

public:
	void inputData();   // 데이터 입력
	void answer();      // 결과 계산 및 출력
};

void num::inputData() {  // 데이터 입력
	cin >> n;
}

void num::answer() {   // 결과 계산 및 출력
	int num_temp, sum;

	for (int i = 1; i < n; i++) {   // 1부터 모든 경우의 수 검사
		num_temp = i;
		sum = i;

		sum += num_temp / 100000;
		num_temp %= 100000;
		sum += num_temp / 10000;
		num_temp %= 10000;
		sum += num_temp / 1000;
		num_temp %= 1000;
		sum += num_temp / 100;
		num_temp %= 100;
		sum += num_temp / 10;
		num_temp %= 10;
		sum += num_temp;

		if (sum == n) {   // 생성자를 찾으면 종료
			cout << i;
			return;
		}
	}

	cout << 0;    // 생성자가 없으므로 0 출력
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	num temp;
	temp.inputData();
	temp.answer();

	return 0;
}