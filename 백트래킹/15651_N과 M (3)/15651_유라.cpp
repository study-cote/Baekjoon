#include <iostream>
#include <stack>
using namespace std;

int n, m;
int check[7];

void combination(int num) {
    if (num == m) {
        for (int i=0; i<m; i++) {
            cout << check[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i=0; i<n; i++) {
        check[num] = i+1;
        combination(num+1);
    }
    
    return;
}

int main() {
    cin >> n >> m; // nCm

    combination(0);
   
    return 0;
}