#include <iostream>
#define MAX 9
using namespace std;

int board[MAX][MAX]; // 스도쿠 판
bool row[MAX][MAX+1] = {false}; // 각 열에 1~9 있는지 체크
bool col[MAX][MAX+1] = {false}; // 각 행에 1~9 있는지 체크
bool square[MAX][MAX+1] = {false}; // 3x3 배열에 1~9 있는지 체크

void sudoku(int idx) {
    if (idx == 81) {// 보드 완성되면 정답 출력
        for (int i=0; i<MAX; i++) {
            for (int j=0; j<MAX; j++) {
                cout << board[i][j] << " ";
            }
        cout << "\n";
        }
        exit(0); // 백트래킹 추가적으로 하지 않게 완전 종료
    }

    int r = idx / MAX; // 현재 행
    int c = idx % MAX; // 현재 열

    if (board[r][c] == 0) { // 채워야 할 부분
        for (int i=1; i<=MAX; i++) {
            if (!row[r][i] && !col[c][i] && !square[(r/3*3)+(c/3)][i]) { // 조건 다 만족하는 경우에만 보드 채우기
                row[r][i] = col[c][i] = square[(r/3*3)+(c/3)][i] = true;
                board[r][c] = i; // 보드 채우기
                sudoku(idx+1);
                // 조건에 맞지 않았을 경우 (=exit 못하고 백트래킹 진행하는 경우) 초기화
                board[r][c] = 0;
                row[r][i] = col[c][i] = square[(r/3*3)+(c/3)][i] = false; 
            }
        }
    }

    else sudoku(idx+1); // 다음 인덱스 계속 탐색
}

int main() {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            cin >> board[i][j];

            if(board[i][j] != 0) {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                square[(i/3*3)+(j/3)][board[i][j]] = true;
            }
        }
    }

    sudoku(0);

    return 0;
}