#include <iostream>
using std::cin;
using std::cout;

class square {
	int x, y, w, h;

public:
	void inputData();
	void answer();
};

void square::inputData() {
	cin >> x >> y >> w >> h;
}

void square::answer() {
	int min;

	if (x < y) {
		min = x;
	}
	else {
		min = y;
	}
	if (w - x < min) {
		min = w - x;
	}
	if (h - y < min) {
		min = h - y;
	}

	cout << min;
}

int main(void) {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	square temp;
	temp.inputData();
	temp.answer();

	return 0;
}