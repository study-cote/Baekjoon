#include <iostream>
using namespace std;

void findprime(int a, int b) {
    bool num[b+1] = {false};

    num[0] = true;
    num[1] = true;

    for (int i=2; i<=b; i++) {
        cout << i << endl;
        if (num[i])
            continue;
        
        for (int j=i+i; j<=b; j+=i)
            num[j] = true;
    }

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