#include <iostream>
using std::cin;
using std::cout;

class cal {
	int n, min = 1000000001, max = -1000000001;
	int* num, * oper_num;

	void inputData();    // ������ �Է�
	void backtracking(int, int);    // ��Ʈ��ŷ

public:
	~cal() {    // �Ҹ���
		delete[] num;
		delete[] oper_num;
	}

	void answer();    // �Լ� ���� �� ��� ���
};

void cal::inputData() {   // ������ �Է�
	cin >> n;
	num = new int[n];
	for (int i = 0; i < n; i++) {   // ���� �Է�
		cin >> num[i];
	}
	oper_num = new int[4];
	for (int i = 0; i < 4; i++) {   // ������ ���� �Է�
		cin >> oper_num[i];
	}
}

void cal::backtracking(int sum, int cur) {    // ��Ʈ��ŷ
	if (cur < n) {
		for (int i = 0; i < 4; i++) {
			if (oper_num[i]) {
				switch (i) {
				case 0:   // +
					oper_num[i]--;
					backtracking(sum + num[cur], cur + 1);
					oper_num[i]++;
					break;
				case 1:   // -
					oper_num[i]--;
					backtracking(sum - num[cur], cur + 1);
					oper_num[i]++;
					break;
				case 2:   // *
					oper_num[i]--;
					backtracking(sum * num[cur], cur + 1);
					oper_num[i]++;
					break;
				case 3:   // /
					oper_num[i]--;
					backtracking(sum / num[cur], cur + 1);
					oper_num[i]++;
					break;
				}
			}
		}
	}
	else {
		if (sum > max) {
			max = sum;
		}
		if (sum < min) {
			min = sum;
		}
	}
}

void cal::answer() {
	inputData();

	backtracking(num[0], 1);

	cout << max << '\n';
	cout << min << '\n';
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cal temp;
	temp.answer();

	return 0;
}