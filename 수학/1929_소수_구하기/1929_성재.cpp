#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

class eratos {
	int m, n;
	bool* arr;

public:
	eratos(int a, int b) : m(a), n(b) {       // ������
		arr = new bool[n + 1];
		arr[1] = false;      // 1�� �Ҽ��� �ƴ�
		for (int i = 2; i <= n; i++) {   // �迭 �ʱ�ȭ
			arr[i] = true;
		}
	}
	~eratos() {          // �Ҹ���
		delete[] arr;
	}

	void printAnswer();   // ����� ��� �� ���
};

void eratos::printAnswer() {   // ����� ��� �� ���
	int max = (int)sqrt(n);     // �ּ� �ڱ� �������� �˻��ϹǷ� ��Ʈ(n)������ ���� �տ��� �ɷ����°� ������

	for (int i = 2; i < n; i++) {       // ¦���� 2�� ����� �� �ɷ����Ƿ� ���� ���
		if (2 * i > n) {
			break;
		}
		arr[2 * i] = false;
	}

	for (int i = 3; i <= max; i++) {   // 3 �̻��� �Ҽ����� �˻�
		if (arr[i]) {     // �Ҽ��� ��츸 �˻�
			for (int j = i; j < n; j += 2) {    // �ڱ��ڽź��� ���� �Ҽ��� ���� �̹� �ɷ������Ƿ� �ڱ��ڽź��� ����, ¦���� �̹� �ɷ������Ƿ� Ȧ���� ����
				if (i * j > n) {
					break;
				}
				arr[i * j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {   // �Ҽ� ���
		if (arr[i]) {
			cout << i << '\n';
		}
	}
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int m, n;

	cin >> m >> n;
	eratos temp(m, n);
	temp.printAnswer();    // ��� ���

	return 0;
}