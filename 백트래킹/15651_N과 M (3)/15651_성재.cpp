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
	arr = new int[m];
}

void progression::func(int cur) {   // 백트래킹
	if (cur < m) {
		for (int i = 0; i < n; i++) {    // 가능한 경우의 수에 대해 표기 후 다음 레벨로 내려가 함수 실행
			arr[cur] = i + 1;
			func(cur + 1);
		}
	}
	else {   // 출력
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
}

void progression::answer() {    // 함수 실행 및 초기화
	inputData();
	func(0);
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	progression temp;
	temp.answer();

	return 0;
}