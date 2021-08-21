#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int T, x, y;
	long long int dif, a;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		dif = y - x;

		a = (long long int)sqrt(dif);
		if (dif <= a * (a + 1) - a) {
			cout << a * 2 - 1 << '\n';
		}
		else if (dif <= a * (a + 1)) {
			cout << a * 2 << '\n';
		}
		else if (dif <= (a + 1) * (a + 2) - (a + 1)) {
			cout << (a + 1) * 2 - 1 << '\n';
		}
		else {
			cout << (a + 1) * 2 << '\n';
		}
	}

	return 0;
}