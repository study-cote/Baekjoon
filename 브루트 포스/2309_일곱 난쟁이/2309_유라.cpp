#include <iostream>
#include <algorithm>
using namespace std;

int height[9];

void whoisseven(int sum) {
    
    for (int i=0; i<8; i++) {
        for (int j=i+1; j<9; j++) {
            if ((sum-height[i]-height[j]) == 100) { // 7명의 합이 100인지 검사
                height[i] = 101; // 정렬시에 뒤로 가게 하기 위해서 101로 재정의
                height[j] = 101;
                return; // 찾는 즉시 종료 (아무 정답이나 인정)
            }
        }
    }

    return;
}

int main() {
    int sum=0;
    for (int i=0; i<9; i++) {
        cin >> height[i];
        sum += height[i]; // 전체 난쟁이의 합
    }

    whoisseven(sum);

    sort(height, height+9); // 오름차순 정렬

    for (int i=0; i<7; i++) {
        cout << height[i] << "\n"; // 정답 출력
    }

    return 0;
}