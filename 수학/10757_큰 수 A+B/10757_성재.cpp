#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;

class plus {
	string a, b, c;
	int sum, up;

public:
	plus() : sum(0), up(0) {}      // 생성자

	void inputData();     // 데이터 입력
	void printAnswer();   // 결과값 계산 및 출력
};

void plus::inputData() {    // 데이터 입력
	cin >> a >> b;
}

void plus::printAnswer() {             // 결과값 계산 및 출력
	if (a.length() > b.length()) {       // a, b 중에 더 긴 string의 길이로 c 크기 결정
		c.reserve(a.length() + 1);
	}
	else {
		c.reserve(b.length() + 1);
	}

	while (!a.empty() && !b.empty()) {         // a, b의 젤 뒷자리 부터 더하기
		sum = (a.back() - '0') + (b.back() - '0') + up;   // a + b + 올림수
		up = sum / 10;     // 올림수
		c.push_back(sum % 10 + '0');   // 올리고 남은 나머지
		a.pop_back();
		b.pop_back();
	}
	while (!a.empty()) {     // a 앞자리 남았을 경우
		sum = a.back() + up - '0';
		up = sum / 10;
		c.push_back(sum % 10 + '0');
		a.pop_back();
	}
	while (!b.empty()) {     // b 앞자리 남았을 경우
		sum = b.back() + up - '0';
		up = sum / 10;
		c.push_back(sum % 10 + '0');
		b.pop_back();
	}
	if (up) {      // 다 더하고 올림수 남았을 경우
		c.push_back('1');
	}

	std::reverse(c.begin(), c.end());    // c가 낮은자리부터 앞에 들어있으므로 문자열 뒤집기
	cout << c;
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	plus temp;
	temp.inputData();     // 데이터 입력
	temp.printAnswer();   // 결과 출력

	return 0;
}