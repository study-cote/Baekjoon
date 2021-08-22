#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int count = 0;
	cin >> n;
	switch (n) {
	case 4:
		cout << -1;
		return 0;
	case 7:
		cout << -1;
		return 0;
	}
	switch (n % 3) {
	case 1:
		n -= 10;
		count = 2;
		break;
	case 2:
		n -= 5;
		count = 1;
		break;
	}
	cout << (n / 15) * 3 + (n % 15) / 3 + count;

	return 0;
}