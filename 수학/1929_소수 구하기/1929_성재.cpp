#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class eratos {
	int m, n;
	bool* arr;

public:
	eratos(int a, int b) : m(a), n(b) {       // 생성자
		arr = new bool[n + 1];
		arr[1] = false;      // 1은 소수가 아님
		for (int i = 2; i <= n; i++) {   // 배열 초기화
			arr[i] = true;
		}
	}
	~eratos() {          // 소멸자
		delete[] arr;
	}

	void printAnswer();   // 결과값 계산 및 출력
};

void eratos::printAnswer() {   // 결과값 계산 및 출력
	int max = (int)sqrt(n);     // 최소 자기 제곱으로 검사하므로 루트(n)이후의 값은 앞에서 걸러지는게 전부임

	for (int i = 2; i < n; i++) {       // 짝수는 2의 배수로 다 걸러지므로 따로 계산
		if (2 * i > n) {
			break;
		}
		arr[2 * i] = false;
	}

	for (int i = 3; i <= max; i++) {   // 3 이상의 소수부터 검사
		if (arr[i]) {     // 소수일 경우만 검사
			for (int j = i; j < n; j += 2) {    // 자기자신보다 적은 소수의 곱은 이미 걸러졌으므로 자기자신부터 시작, 짝수는 이미 걸러졌으므로 홀수의 곱만
				if (i * j > n) {
					break;
				}
				arr[i * j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {   // 소수 출력
		if (arr[i]) {
			cout << i << '\n';
		}
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int m, n;

	cin >> m >> n;
	eratos temp(m, n);
	temp.printAnswer();    // 결과 출력

	return 0;
}