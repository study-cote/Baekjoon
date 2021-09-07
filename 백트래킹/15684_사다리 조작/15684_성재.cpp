#include <iostream>
using std::cin;
using std::cout;

class ladder {
	int n, m, h, min = 4;
	int** arr, ** num, * result;

	void inputData();    // 데이터 입력
	void backtracking(int, int, int);     // 백트래킹
	void swap(int&, int&);   // 데이터 교환
	void printData();    // 결과 출력

public:
	void func();   // 함수 실행 및 배열 초기화
};

void ladder::inputData() {    // 데이터 입력
	cin >> n >> m >> h;

	arr = new int* [h + 1];
	num = new int* [h + 1];
	result = new int[n + 1];
	for (int i = 1; i <= h; i++) {
		arr[i] = new int[n + 1];
		for (int j = 0; j <= n; j++) {
			arr[i][j] = 0;
		}
		num[i] = new int[n + 1];
	}
	int a, b;
	for (int i = 0; i < m; i++) {   // 입력
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		result[i] = i;
	}
}

void ladder::backtracking(int row, int col, int cur) {    // 백트래킹
	int i;
	for (i = 1; i <= n; i++) {     // 같은 번호에 가는지 체크
		if (num[h][result[i]] != i) {
			break;
		}
	}
	if (i > n) {   // 전부 같은 번호로 내려갈 때
		if (cur < min) {   // 최소값 갱신
			min = cur;
		}
		return;
	}
	if (cur >= 3) {    // 추가 가로줄이 3개를 넘지 않음
		return;
	}

	for (row; row <= h; row++) {
		for (col; col < n;col++) {
			if (!arr[row][col] && !arr[row][col - 1] && !arr[row][col + 1]) {     // 양 옆에 가로줄이 없을 때
				swap(result[num[row][col]], result[num[row][col + 1]]);
				arr[row][col] = 1;
				backtracking(row, col + 1, cur + 1);
				swap(result[num[row][col]], result[num[row][col + 1]]);
				arr[row][col] = 0;
			}
		}
		col = 0;
	}
}

void ladder::swap(int& a, int& b) {   // 데이터 교환
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void ladder::func() {  // 함수 실행 및 배열 초기화
	inputData();

	int cur;
	for (int i = 1; i <= n; i++) {
		cur = i;
		for (int j = 1; j <= h; j++) {
			if (cur > 1 && arr[j][cur - 1]) {
				cur--;
			}
			else if (cur < n && arr[j][cur]) {
				cur++;
			}
			num[j][cur] = i;
		}
	}

	backtracking(1, 1, 0);

	printData();
}

void ladder::printData() {   // 결과 출력
	if (min > 3) {    // 3개 이내로 불가능할 때
		cout << -1;
	}
	else {    // 3개 이내로 가능할 때 최소값 출력
		cout << min;
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	ladder temp;
	temp.func();

	return 0;
}