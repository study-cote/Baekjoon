#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int *input; // 입력 저장할 int 배열
vector<int> check; // 조합에 사용한 벡터
stack<int> result; // 더한 결과들 모은 스택

void blackjack(int n) {
    do {
        int sum=0;
        for (int i=0; i<n; i++) {
            if(check[i]) // 조합에서 선택된 카드
                sum += input[i]; // 카드의 값 더하기
        }
        result.push(sum); // 선택한 세 카드의 값 더한 것 스택에 저장
    } while(prev_permutation(check.begin(), check.end())); // 조합 위해 접근할 요소의 위치 변경

    return;
}

int main() {
    int n, m, val=0; // N:카드의 개수, M: 목표 숫자
    cin >> n >> m;

    // 각 카드의 숫자를 저장하기 위한 배열 할당
    input = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++) {
        if (i<3) // blackjack()의 prev_permutation에서 사용하기 위한 벡터
            check.push_back(1); // 값이 1인 요소의 개수가 r을 의미
        else check.push_back(0);
    }

    // 각 카드의 숫자 입력 받아서 저장
    for (int i=0; i<n; i++)
        cin >> input[i];
    
    blackjack(n);

    // 조건에 맞는 가장 큰 값을 얻기 위해 스택 내의 값끼리 비교
    while(!result.empty()) {
        if (val < result.top() && result.top() <= m)
            val = result.top();
        result.pop();
    }

    cout << val;

    return 0;
}