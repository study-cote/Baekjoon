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
	int num_temp, num_temp2, sum;

	for (int i = 1; i < n; i++) {   // 1부터 모든 경우의 수 검사
		num_temp = i;
		num_temp2 = (int)pow(10, (int)log10(i));
		sum = 0;

		while (num_temp) {   // 각 자리수 합 계산
			sum += num_temp / num_temp2;
			num_temp %= num_temp2;
			num_temp2 /= 10;
		}

		if (sum + i == n) {   // 각 자리수 합 + 현재 검사하는 수가 n과 같으면 생성자이므로 출력 및 함수 종료
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