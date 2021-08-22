#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::ios_base;
using std::string;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b, c, d;
	int sum, up = 0;
	cin >> a >> b;
	if (a.length() > b.length()) {
		c.reserve(a.length() + 1);
		d.reserve(a.length() + 1);
	}
	else {
		c.reserve(b.length() + 1);
		d.reserve(b.length() + 1);
	}
	while (!a.empty() && !b.empty()) {
		sum = a.back() + b.back() + up - 96;
		up = sum / 10;
		c.push_back(sum % 10 + 48);
		a.pop_back();
		b.pop_back();
	}
	while (!a.empty()) {
		sum = a.back() + up - 48;
		up = sum / 10;
		c.push_back(sum % 10 + 48);
		a.pop_back();
	}
	while (!b.empty()) {
		sum = b.back() + up - 48;
		up = sum / 10;
		c.push_back(sum % 10 + 48);
		b.pop_back();
	}
	if (up) {
		c.push_back('1');
	}
	while (!c.empty()) {
		d.push_back(c.back());
		c.pop_back();
	}
	cout << d;

	return 0;
}