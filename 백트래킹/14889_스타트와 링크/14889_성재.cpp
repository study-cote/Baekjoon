#include <iostream>
using std::cin;
using std::cout;

class startlink {
	int n, half_n, min = 1000000000;
	int* visit1, * visit2, ** arr;

	void inputData();    // 데이터 입력
	void backtracking(int, int);    // 백트래킹
	void printData();    // 결과 출력

public:
	~startlink() {   // 소멸자
		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
		delete[] visit1;
		delete[] visit2;
	}

	void func();    // 함수 실행
};

void startlink::inputData() {   // 데이터 입력
	cin >> n;
	half_n = n / 2;
	visit1 = new int[half_n];
	visit2 = new int[half_n];
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {  // 입력
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < n; i++) {   // 한쪽으로 데이터 합침
		for (int j = 0; j < i; j++) {
			arr[i][j] += arr[j][i];
		}
	}
}

void startlink::backtracking(int cur, int count) {   // 백트래킹
	if (count == half_n) {
		for (int i = cur; i < n; i++) {    // 선택안된 나머지 채움
			visit2[i - count] = i;
		}

		int sum1 = 0, sum2 = 0;
		for (int i = 1; i < half_n; i++) {    // 합 계산
			for (int j = 0; j < i; j++) {
				sum1 += arr[visit1[i]][visit1[j]];
				sum2 += arr[visit2[i]][visit2[j]];
			}
		}

		if (sum1 < sum2) {    // 차이값 최소 계산
			if (sum2 - sum1 < min) {
				min = sum2 - sum1;
			}
		}
		else if (sum1 - sum2 < min) {
			min = sum1 - sum2;
		}

		return;
	}

	for (int i = cur; i < half_n + 1 + count; i++) {    // 방문 백트래킹
		visit1[count] = i;
		backtracking(i + 1, count + 1);
		if (i - count < half_n) {
			visit2[i - count] = i;
		}
	}
}

void startlink::printData() {   // 결과 출력
	cout << min;
}

void startlink::func() {   // 함수 실행
	inputData();
	backtracking(0, 0);
	printData();
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	startlink temp;
	temp.func();
	
	return 0;
}