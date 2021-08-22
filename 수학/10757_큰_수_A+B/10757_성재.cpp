#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;

class plus {
	string a, b, c;
	int sum, up;

public:
	plus() : sum(0), up(0) {}      // ������

	void inputData();     // ������ �Է�
	void printAnswer();   // ����� ��� �� ���
};

void plus::inputData() {    // ������ �Է�
	cin >> a >> b;
}

void plus::printAnswer() {             // ����� ��� �� ���
	if (a.length() > b.length()) {       // a, b �߿� �� �� string�� ���̷� c ũ�� ����
		c.reserve(a.length() + 1);
	}
	else {
		c.reserve(b.length() + 1);
	}

	while (!a.empty() && !b.empty()) {         // a, b�� �� ���ڸ� ���� ���ϱ�
		sum = (a.back() - '0') + (b.back() - '0') + up;   // a + b + �ø���
		up = sum / 10;     // �ø���
		c.push_back(sum % 10 + '0');   // �ø��� ���� ������
		a.pop_back();
		b.pop_back();
	}
	while (!a.empty()) {     // a ���ڸ� ������ ���
		sum = a.back() + up - '0';
		up = sum / 10;
		c.push_back(sum % 10 + '0');
		a.pop_back();
	}
	while (!b.empty()) {     // b ���ڸ� ������ ���
		sum = b.back() + up - '0';
		up = sum / 10;
		c.push_back(sum % 10 + '0');
		b.pop_back();
	}
	if (up) {      // �� ���ϰ� �ø��� ������ ���
		c.push_back('1');
	}

	std::reverse(c.begin(), c.end());    // c�� �����ڸ����� �տ� ��������Ƿ� ���ڿ� ������
	cout << c;
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	plus temp;
	temp.inputData();     // ������ �Է�
	temp.printAnswer();   // ��� ���

	return 0;
}