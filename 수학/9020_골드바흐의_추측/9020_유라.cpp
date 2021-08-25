#include <iostream>
using namespace std;
#define SIZE 10000

int find_min_prime(int a, bool arr[]) {
    int j;
    for (j=a-1; j>=2; j--) {
        if (!arr[j])
            break; 
    }
    return j;
}

int find_max_prime(int b, bool arr[]) {
    int j;
    for (j=b+1; j<=SIZE; j++) {
        if (!arr[j])
            break;
    }
    return j;
}

int main() {
    int t, n, k, a, b;
    cin >> t;

    // 에라토스테네스의 체
    bool arr[SIZE+1] = {false};
    arr[0] = true;
    arr[1] = true;
    for (int i=2; i<=SIZE; i++) {
        if (arr[i])
            continue;
        for (int j=i+i; j<=SIZE; j+=i)
            arr[j] = true;
    }

    // testcase
    for (int i=0; i<t; i++) {
        cin >> n;
        k = n/2;
        if (!arr[k]) {
            cout << k << " " << k << endl;
        }
        else {
            a=k, b=k;
            a=find_min_prime(a, arr);
            b=find_max_prime(b, arr);
            while(a+b!=n) {
                if (a+b>n)
                    a=find_min_prime(a, arr);
                else
                    b=find_max_prime(b, arr);
            }
            cout << a << " " << b << endl;
        }
    }
    return 0;
}