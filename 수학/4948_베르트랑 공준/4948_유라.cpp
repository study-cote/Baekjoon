#include <iostream>
using namespace std;

int findprime(int t) {
    // 에라토스테네스의 체
    int start=t+1, end=2*t, count=0;
    int num[end+1] = {false}; // 제시하는 범위만큼의 배열 만듦 

    num[0] = true;
    num[1] = true;

    for(int i=2; i<=end; i++) {
        if (num[i])
            continue;
        for(int j=i+i; j<=end; j+=i)
            num[j] = true;
    }

    // 범위 내의 소수 개수 세기
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
