#include <iostream>
#define MAX 20
using namespace std;

int n, diff=1000000001; // diff: 두 팀 간의 차이 (최솟값이 되어야하므로 초기값을 크게 넣어주었음)
int power[MAX+1][MAX+1]; // 능력치 저장할 배열
bool check[MAX+1] = {false}; // 방문여부 체크할 배열

void maketeams(int idx, int pos) {
    if (idx == n/2) { // 두 팀으로 나눠질 때 (-> 문제에서 요구하는 사항)
        int start = 0;
        int link = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (check[i] && check[j]) // 방문한 idx일 경우, 스타트팀의 능력치로 더해줌
                    start += power[i][j];  
                if (!check[i] && !check[j]) // 반대는 링크팀의 능력치로 더해줌
                    link += power[i][j]; // 이중 for문 돌면서 [i][j]와 [j][i]의 경우를 모두 넣을 수 있기 때문에 굳이 [i][j]+[j][i] 해주지 않아도 됨
            }
        }
        
        if (abs(start-link) < diff) // 기존에 구해놨던 차이보다 현재 차이가 더 작을 경우, diff 값 변경해주기
            diff = abs(start-link);

        return;
    }

    for (int i=pos; i<=n; i++) { // 방문한 idx는 제외하고 방문하지 않은 idx만 방문 (-> i=pos)
            check[i] = true; // 방문 체크
            maketeams(idx+1, i+1); // 재귀 (백트래킹), idx는 팀원의 수 세는 용, i는 다음에 방문할 idx 
            check[i] = false; // 초기화
    }

    return;
}

int main() {
    cin >> n;

    // 능력치 입력
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> power[i][j];
        }
    }

    maketeams(0, 1); // 백트래킹 시작, 처음 시작할 때는 팀원 0명, 방문해야 할 인덱스 == 첫번째 (여기서는 1)

    cout << diff; // 정답 출력

    return 0;
}