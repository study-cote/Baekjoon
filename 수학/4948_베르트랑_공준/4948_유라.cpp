#include <iostream>
using namespace std;

int findprime(int t) {
    int start=t+1, end=2*t+1, count=0;
    int num[end] = {false};

    num[0] = true;
    num[1] = true;

    for(int i=2; i<=end; i++) {
        if (num[i])
            continue;
        for(int j=i+i; j<=end; j+=i)
            num[j] = true;
    }

    while(start<=end) {
        if(!num[start])
            count++;
        start++;
    }

    return count;
}

int main() {
    int t;

    while(1) {
        cin >> t;
        if (t==0)
            break;
        cout << findprime(t) << endl;
    }

    return 0;
}