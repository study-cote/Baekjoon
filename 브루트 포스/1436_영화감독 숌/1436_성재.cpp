#include <iostream>
using std::cin;
using std::cout;

class movie {
	int n;

public:
	void inputData();    // 데이터 입력
	void answer();       // 결과 계산 및 출력
};

void movie::inputData() {    // 데이터 입력
	cin >> n;
}

void movie::answer() {   // 결과 계산 및 출력
	int i, count, num, temp;

	for (i = 666; n; i++) {
		count = 0, num = i, temp = 100000000;
		
		while (num) {
			if (num / temp == 6) {   // 제일 큰 자리수가 6일 경우
				count++;   // 연속된 6 개수 증가
			}
			else {   // 한번이라도 끊길 경우 초기화
				count = 0;
			}
			if (count > 2) {   // 연속된 6이 3개 이상일 경우
				n--;   // 찾아야 할 종말의 숫자 개수 감소
				break;
			}

			num %= temp;
			temp /= 10;
		}
	}

	cout << i - 1;    // for문 종료 직전 i가 증가하므로 -1이 결과값
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	movie temp;
	temp.inputData();
	temp.answer();

	return 0;
}