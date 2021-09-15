#include <iostream>
using std::cin;
using std::cout;

class sort {
	void exchange(int&, int&);   // 데이터 교환
	int partition(int*, int, int);    // 퀵소트 pivot 기준 분리

public:
	void quickSort(int*, int, int);   // 퀵소트
};

void sort::exchange(int& a, int& b) {   // 데이터 교환
	int temp;

	temp = a;
	a = b;
	b = temp;
}

int sort::partition(int* S, int low, int high) {   // 퀵소트 pivot 기준 분리
	int i, j;
	int pivotitem;

	pivotitem = S[low];
	j = low;
	for (i = low + 1; i <= high; i++) {
		if (S[i] < pivotitem) {
			j++;
			exchange(S[i], S[j]);
		}
	}

	exchange(S[low], S[j]);

	return j;
}

void sort::quickSort(int* S, int low, int high) {   // 퀵소트
	if (low < high) {
		int pivotPoint;

		pivotPoint = partition(S, low, high);
		quickSort(S, low, pivotPoint);
		quickSort(S, pivotPoint + 1, high);
	}
}

class algo {
	int n, m;
	int* data, * print;
	bool* visit;
	sort quick;

	void inputData();   // 데이터 입력
	void backTracking(int);   // 백트래킹
	void printData();   // 결과 출력

public:
	~algo() {   // 소멸자
		delete[] data;
		delete[] visit;
		delete[] print;
	}

	void func();    // 함수 실행
};

void algo::inputData() {   // 데이터 입력
	cin >> n >> m;
	
	data = new int[n];
	print = new int[m];
	visit = new bool[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
		visit[i] = false;
	}

	quick.quickSort(data, 0, n - 1);   // 입력값 정렬
}

void algo::backTracking(int remain) {   // 백트래킹
	if (!remain) {
		printData();

		return;
	}

	int trail = 0;
	for (int i = 0; i < n; i++) {
		if (!visit[i] && data[i] != trail) {
			trail = data[i];
			print[remain - 1] = data[i];
			visit[i] = true;
			backTracking(remain - 1);
			visit[i] = false;
		}
	}
}

void algo::printData() {   // 결과 출력
	for (int i = m - 1; i >= 0; i--) {
		cout << print[i] << ' ';
	}
	cout << '\n';
}

void algo::func() {   // 함수 실행
	inputData();

	backTracking(m);
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	algo temp;
	temp.func();

	return 0;
}