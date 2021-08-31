#include <iostream>
using namespace std;

int n, **arr;

void whoisbig() {
    for (int i=0; i<n; i++) {
        int k=0; // 등수
        for (int j=0; j<n; j++) {
            // 본인 제외
            if (i==j)
                continue;
            // 덩치 큰 사람 찾기 -> 나보다 몸무게 x , 키 y 가 더 큰 사람
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
                k++;
        }
        cout << k+1 << " "; // 출력
    }
    return;
}

int main() {
    cin >> n;

    // N x 2 배열 할당
    arr = (int**)malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++)
        arr[i] = (int*)malloc(sizeof(int) * 2);

    for (int i=0; i<n; i++) {
        // [i][0] : x, [i][1] : y
        cin >> arr[i][0] >> arr[i][1];
    }

    whoisbig();

    return 0;
}