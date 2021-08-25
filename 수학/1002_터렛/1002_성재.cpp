#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class turret {
	int T, x1, y1, r1, x2, y2, r2;
	double r3;

	void inputData();       // 데이터 입력
	void swap(int&, int&);  // 숫자 2개 교환

public:
	void answer();          // 결과 계산 및 출력
};

void turret::inputData() {   // 데이터 입력
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
}

void turret::swap(int& a, int& b) {   // 숫자 2개 교환
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void turret::answer() {   // 결과 계산 및 출력
	cin >> T;

	for (int i = 0; i < T; i++) {
		inputData();   // 데이터 입력

		r3 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));   // 두 점 사이 거리 계산
		if (r1 > r2) {     // 편의를 위해 r2를 큰 수로 변경
			swap(r1, r2);
		}

		if (x1 == x2 && y1 == y2 && r1 == r2) {   // 원의 중심, 반지름이 같은 경우
			cout << -1 << '\n';
		}
		else if (r3 > r1 + r2) {   // 두 원의 거리가 반지름의 합보다 큰 경우
			cout << 0 << '\n';
		}
		else if (r3 == r1 + r2) {  // 두 원의 거리가 반지름의 합과 같은 경우
			cout << 1 << '\n';
		}
		else if (r2 == r1 + r3) {  // 작은 원이 큰 원의 내부에서 한 점과 맞닿을 경우
			cout << 1 << '\n';
		}
		else if (r2 > r1 + r3) {   // 작은 원이 큰 원의 내부에 있을 경우
			cout << 0 << '\n';
		}
		else {    // 두 원이 두 점에서 만나는 경우
			cout << 2 << '\n';
		}
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	turret temp;
	temp.answer();

	return 0;
}