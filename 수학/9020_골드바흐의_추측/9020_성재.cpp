#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class primeFactor {
	const int arr_size = 10000;
	int T, n;
	bool* arr;

	void cal();          // �����佺�׳׽��� ü
	void printAnswer();  // ��� ���

public:
	primeFactor(int data) : T(data) {   // ������
		arr = new bool[arr_size];
		for (int i = 2; i < arr_size; i++) {   // �迭 �ʱ�ȭ
			arr[i] = true;
		}
	}
	~primeFactor() {   // �Ҹ���
		delete[] arr;
	}

	void inputData();   // ������ �Է�
};

void primeFactor::cal() {          // �����佺�׳׽��� ü
	int max = (int)sqrt(arr_size);     // �ּ� �ڱ� �������� �˻��ϹǷ� ��Ʈ(n)������ ���� �տ��� �ɷ����°� ������

	for (int i = 4; i < arr_size; i += 2) {       // ¦���� 2�� ����� �� �ɷ����Ƿ� ���� ���
		arr[i] = false;
	}

	int temp;
	for (int i = 3; i <= max; i++) {   // 3 �̻��� �Ҽ����� �˻�
		if (arr[i]) {     // �Ҽ��� ��츸 �˻�
			temp = i * 2;
			for (int j = i * i; j < arr_size; j += temp) {    // �ڱ��ڽź��� ���� �Ҽ��� ���� �̹� �ɷ������Ƿ� �ڱ��ڽź��� ����, ¦���� �̹� �ɷ������Ƿ� Ȧ���� ����
				arr[j] = false;
			}
		}
	}
}

void primeFactor::printAnswer() {     // ��� ���
	for (int i = n / 2; i > 1; i--) {
		if (arr[i] && arr[n - i]) {
			cout << i << ' ' << n - i << '\n';
			break;
		}
	}
}

void primeFactor::inputData() {   // ������ �Է�
	cal();

	for (int i = 0; i < T; i++) {
		cin >> n;
		printAnswer();
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int T;

	cin >> T;
	primeFactor temp(T);
	temp.inputData();

	return 0;
}