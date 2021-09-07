#include <iostream>
using std::cin;
using std::cout;

class startlink {
	int n, half_n, min = 1000000000;
	int* visit1, * visit2, ** arr;

	void inputData();    // ������ �Է�
	void backtracking(int, int);    // ��Ʈ��ŷ
	void printData();    // ��� ���

public:
	~startlink() {   // �Ҹ���
		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
		delete[] visit1;
		delete[] visit2;
	}

	void func();    // �Լ� ����
};

void startlink::inputData() {   // ������ �Է�
	cin >> n;
	half_n = n / 2;
	visit1 = new int[half_n];
	visit2 = new int[half_n];
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {  // �Է�
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < n; i++) {   // �������� ������ ��ħ
		for (int j = 0; j < i; j++) {
			arr[i][j] += arr[j][i];
		}
	}
}

void startlink::backtracking(int cur, int count) {   // ��Ʈ��ŷ
	if (count == half_n) {
		for (int i = cur; i < n; i++) {    // ���þȵ� ������ ä��
			visit2[i - count] = i;
		}

		int sum1 = 0, sum2 = 0;
		for (int i = 1; i < half_n; i++) {    // �� ���
			for (int j = 0; j < i; j++) {
				sum1 += arr[visit1[i]][visit1[j]];
				sum2 += arr[visit2[i]][visit2[j]];
			}
		}

		if (sum1 < sum2) {    // ���̰� �ּ� ���
			if (sum2 - sum1 < min) {
				min = sum2 - sum1;
			}
		}
		else if (sum1 - sum2 < min) {
			min = sum1 - sum2;
		}

		return;
	}

	for (int i = cur; i < half_n + 1 + count; i++) {    // �湮 ��Ʈ��ŷ
		visit1[count] = i;
		backtracking(i + 1, count + 1);
		if (i - count < half_n) {
			visit2[i - count] = i;
		}
	}
}

void startlink::printData() {   // ��� ���
	cout << min;
}

void startlink::func() {   // �Լ� ����
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