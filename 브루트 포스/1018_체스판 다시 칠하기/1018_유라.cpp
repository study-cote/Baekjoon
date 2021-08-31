#include <iostream>
using namespace std;

int n,m;
char **chess;

void howmanysquare() {
    int min = 999999;

    for(int r=0,c=0; r+7<n; c++) {
        // 현재 행 혹은 열에서 8x8 을 만들 수 없는 경우 체크
        if (c+7>=m) {
            r++;
            c=0;

            if (r+7>=n)
                break;
        }

        // 8 x 8 배열
        int cnt = 0;
        do {
            int square = 0; // 네모의 개수
            bool black=false, white=false;
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {

                    if (j==0 && i==0) { // 맨 위의 첫번째 요소가 B인지 W인지 검사
                        if (chess[r+i][c+j]=='B') {
                            black = true;
                        }
                        else white = true;

                        if (cnt!=0) { // 첫번째 요소가 B 혹은 W 여도, 반대로 채우는게 네모를 더 적게 칠하는 경우가 있기 때문에 두 번 돌리기
                            black = (!black);
                            white = (!white);
                        }
                    }

                    if(black) {
                        if ((j%2==0 && chess[r+i][c+j]!='B') || (j%2!=0 && chess[r+i][c+j]=='B')) { // BWB에 해당되지 않는 경우 칠해야 하는 네모 수 +1
                            square++;
                        }
                    }
                    else {
                        if ((j%2==0 && chess[r+i][c+j]!='W') || (j%2!=0 && chess[r+i][c+j]=='W')) { // WBW에 해당되지 않는 경우 칠해야 하는 네모 수 +1
                            square++;
                        }   
                    }
                
                    if (j==7) { // 다음 행의 시작은 현재 행의 시작과 반대여야 함
                        black=!black;
                        white=!white;
                    }

                    
                }
            }

            if (square < min) { // 가장 적게 칠하는 횟수 찾기
                min = square;
            }

            cnt++;

        } while (cnt<2);
    }

    cout << min;
    return;
}

int main() {
    cin >> n >> m;

    // n x m 배열 할당
    chess = (char**)malloc(sizeof(char*) * n);
    for (int i=0; i<n; i++)
        chess[i] = (char*)malloc(sizeof(char) * m);

    // 네모 판 입력
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> chess[i][j];
        }
    }

    howmanysquare();

    return 0;
}