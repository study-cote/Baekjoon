#include <iostream>
using std::cin;
using std::cout;

class sugar {
	int n, count;
	
public:
	sugar(int data) : n(data) {}    // 생성자
	
	void printAnswer();    // 결과값 계산 및 출력
};

void sugar::printAnswer() {
	switch (n) {
	case 4:          // 3과 5 조합으로 n을 만들 수 없음
		cout << -1;
		break;
	case 7:
		cout << -1;
		break;
	default:         // 3과 5 조합으로 n 만들어질때
		switch (n % 3) {       // 15a + 3b형태로 변환하기 위해 +@ 값 따로 저장
		case 1:             // 15a + 10 + 3b
			n -= 10;
			count = 2;
			break;
		case 2:             // 15a + 5 + 3b
			n -= 5;
			count = 1;
			break;
		default:            // 15a + 3b
			count = 0;
		}
		cout << (n / 15) * 3 + (n % 15) / 3 + count;      // 15a + 3b + @
	}
	
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, count = 0;
	cin >> n;
	sugar temp(n);
	temp.printAnswer();     // 결과 출력

	return 0;
}