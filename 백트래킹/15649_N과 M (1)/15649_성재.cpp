#include <iostream>
using std::cin;
using std::cout;

class progression {
	int n, m;
	int* arr;

	void inputData();       // 데이터 입력
	void func(int);   // 백트래킹

public:
	void answer();   // 함수 실행 및 초기화
};

void progression::inputData() {  // 데이터 입력
	cin >> n >> m;
	arr = new int[n];
}

void progression::func(int remain) {   // 백트래킹
	if (remain) {
		for (int i = 0; i < n; i++) {    // 가능한 경우의 수에 대해 표기 후 다음 레벨로 내려가 함수 실행
			if (!arr[i]) {
				arr[i] = remain;
				func(remain - 1);
				arr[i] = 0;
			}
		}
	}
	else {   // 출력
		remain = m;
		for (; remain; remain--) {
			for (int i = 0; i < n; i++) {
				if (arr[i] == remain) {
					cout << i + 1 << ' ';
					break;
				}
			}
		}
		cout << '\n';
	}
}

void progression::answer() {    // 함수 실행 및 초기화
	inputData();
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	func(m);
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	progression temp;
	temp.answer();

	return 0;
}