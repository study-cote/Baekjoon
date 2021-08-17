#include <iostream>
using std::cin;
using std::cout;

class findFrac {
	int data, count, sum;

public:
	findFrac(int n) : data(n), count(1), sum(0) {
		
	}
	void answer();
};

void findFrac::answer() {
	for (;;count++) {
		sum += count;
		if (data <= sum) {
			break;
		}
	}

	if (count % 2) {
		cout << sum - data + 1 << '/' << count - (sum - data);
	}
	else {
		cout << count - (sum - data) << '/' << sum - data + 1;
	}
}

int main(void) {
	int num;

	cin >> num;
	findFrac temp(num);
	temp.answer();

	return 0;
}