#include <iostream>
#include <string>
using namespace std;

void moviename(int n) {
    int num=665, cnt=0;
    
    while(cnt<n) {
        num++; // 영화이름이 될 숫자
        string s = to_string(num); // 666이 들어있는지 찾기 위해 스트링으로 변경
        if (s.find("666") != -1) // 666 포함하는지 검사
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
