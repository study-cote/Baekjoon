#include <iostream>
using std::cin;
using std::cout;

class findFrac {
	int x, count, sum;

public:
	findFrac(int n) : x(n), count(1), sum(1) {   // 생성자, n은 입력값
		
	}
	void answer();  // 결과값 구하는 함수
};

void findFrac::answer() {  // 결과값 구하는 함수
	for (;;count++) {   // count와 sum의 값은 생성자에서 1로 초기화 됨
		sum += count;
		if (x < sum) {
			break;
		}
	}

	if (count % 2) {     // 홀수 번째 대각선일 경우
		cout << sum - x << '/' << count + 1 - (sum - x);
	}
	else {   // 짝수 번째 대각선일 경우
		cout << count + 1 - (sum - x) << '/' << sum - x;
	}
}

int main(void) {
	int x;

	cin >> x;
	findFrac temp(x);
	temp.answer();

	return 0;
}