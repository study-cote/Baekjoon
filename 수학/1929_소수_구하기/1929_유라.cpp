#include <iostream>
using namespace std;

void findprime(int a, int b) {
    // 에라토스테네스의 체 
    bool num[b+1] = {false};

    // true는 소수가 아닌 것을 의미
    num[0] = true;
    num[1] = true;

    // 소수 걸러내는 과정
    for (int i=2; i<=b; i++) {
        if (num[i])
            continue;
        
        // i의 배수는 소수가 아니므로, true 체크
        for (int j=i+i; j<=b; j+=i)
            num[j] = true;
    }

    // 범위 내의 소수만 출력
    while(a<=b) {
        if (!num[a])
            cout << a << " ";
        a++;
    }

    return;
}

int main() {
    int a, b;
    cin >> a >> b;

    findprime(a, b);

    return 0;
}
