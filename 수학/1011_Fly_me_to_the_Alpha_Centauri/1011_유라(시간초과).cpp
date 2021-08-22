#include <iostream>
using namespace std;

unsigned int distance(unsigned int x, unsigned int y) {
    unsigned int dist = y - x;

    if (dist <= 2)
        return dist;
    else {
        unsigned int ans=1, move=1;
        while(dist>1) {
            dist -= move;
            ans += 1;
            if (dist-move > move)
                move += 1;
        }
        return ans;
    }
}

int main() {
    int t; // testcase #
    cin >> t;
    
    while(t--) {
        unsigned int x, y; // input + unsigned int: ~2^32
        cin >> x >> y;
        cout << distance(x, y) << endl;
    }

    return 0;
}