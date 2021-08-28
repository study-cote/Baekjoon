#include <iostream>
using std::cin;
using std::cout;

class grade {
	int n;
	int* arr[3];

public:
	void inputData();   // 데이터 입력
	void answer();      // 결과 계산 및 출력
};

void grade::inputData() {   // 데이터 입력
	cin >> n;
	arr[0] = new int[n];   // 키
	arr[1] = new int[n];   // 몸무게
	arr[2] = new int[n];   // 등수

	for (int i = 0; i < n; i++) {
		cin >> arr[0][i] >> arr[1][i];   // 입력
		arr[2][i] = 1;   // 각 등수 1로 초기화
	}
}

void grade::answer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j]) {    // 본인보다 덩치가 큰 사람이 있을경우 등수 +1
				arr[2][i]++;
			}
		}

		cout << arr[2][i] << ' ';   // 출력
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	grade temp;
	temp.inputData();
	temp.answer();

	return 0;
}