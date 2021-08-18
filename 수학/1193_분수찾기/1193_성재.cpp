#include <iostream>
using std::cin;
using std::cout;

class findFrac {
	int data, count, sum;

public:
	findFrac(int n) : data(n), count(1), sum(1) {   // 생성자
		
	}
	void answer();  // 결과값 구하는 함수
};

void findFrac::answer() {  // 결과값 구하는 함수
	for (;;count++) {      // 몇 번째 대각선인지 구함
		sum += count;
		if (data < sum) {
			break;
		}
	}

	if (count % 2) {     // 홀수 번째 대각선일 경우
		cout << sum - data << '/' << count + 1 - (sum - data);
	}
	else {   // 짝수 번째 대각선일 경우
		cout << count + 1 - (sum - data) << '/' << sum - data;
	}
}

int main(void) {
	int num;

	cin >> num;
	findFrac temp(num);
	temp.answer();

	return 0;
}