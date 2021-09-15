#include <iostream>
using std::cin;
using std::cout;

class sort {
	void exchange(int&, int&);   // ������ ��ȯ
	int partition(int*, int, int);    // ����Ʈ pivot ���� �и�

public:
	void quickSort(int*, int, int);   // ����Ʈ
};

void sort::exchange(int& a, int& b) {   // ������ ��ȯ
	int temp;

	temp = a;
	a = b;
	b = temp;
}

int sort::partition(int* S, int low, int high) {   // ����Ʈ pivot ���� �и�
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

void sort::quickSort(int* S, int low, int high) {   // ����Ʈ
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

	void inputData();   // ������ �Է�
	void backTracking(int);   // ��Ʈ��ŷ
	void printData();   // ��� ���

public:
	~algo() {   // �Ҹ���
		delete[] data;
		delete[] visit;
		delete[] print;
	}

	void func();    // �Լ� ����
};

void algo::inputData() {   // ������ �Է�
	cin >> n >> m;
	
	data = new int[n];
	print = new int[m];
	visit = new bool[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
		visit[i] = false;
	}

	quick.quickSort(data, 0, n - 1);   // �Է°� ����
}

void algo::backTracking(int remain) {   // ��Ʈ��ŷ
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

void algo::printData() {   // ��� ���
	for (int i = m - 1; i >= 0; i--) {
		cout << print[i] << ' ';
	}
	cout << '\n';
}

void algo::func() {   // �Լ� ����
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