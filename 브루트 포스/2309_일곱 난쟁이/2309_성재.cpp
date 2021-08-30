#include <iostream>
using std::cin;
using std::cout;

class dwarf {
	int arr[9];

	void sort();      // 정렬(bubble)
	void swap(int, int);    // 두 수 교환

public:
	void inputData();   // 데이터 입력
	void answer();      // 결과 계산 및 출력
};

void dwarf::sort() {    // 정렬(bubble)
	for (int i = 8; i; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(j, j + 1);
			}
		}
	}
}

void dwarf::swap(int a, int b) {   // 두 수 교환
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void dwarf::inputData() {   // 데이터 입력
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	sort();   // 배열 오름차순 정렬
}

void dwarf::answer() {   // 결과 계산 및 출력
	int sum = 0;

	for (int i = 0; i < 9; i++) {    // 총합 계산
		sum += arr[i];
	}

	for (int i = 0; i < 8; i++) {    // 총합에서 둘을 빼서 100인지 검사
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {    // 두 수를 뺐을 때 100일 경우 출력 및 함수 종료
				for (int k = 0; k < i; k++) {
					cout << arr[k] << '\n';
				}
				for (int k = i + 1; k < j; k++) {
					cout << arr[k] << '\n';
				}
				for (int k = j + 1; k < 9; k++) {
					cout << arr[k] << '\n';
				}
				return;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	dwarf temp;
	temp.inputData();
	temp.answer();

	return 0;
}