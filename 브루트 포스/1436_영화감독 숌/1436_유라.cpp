#include <iostream>
#include <string>
using namespace std;

void moviename(int n) {
    int num=665, cnt=0;
    
    while(cnt<n) {
        num++;
        string s = to_string(num);
        if (s.find("666") != -1)
            cnt++;
    }

    cout << num;

    return;
}

int main() {
    int n;
    cin >> n;

    moviename(n);

    return 0;
}