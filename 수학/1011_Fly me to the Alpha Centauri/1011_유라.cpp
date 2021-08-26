/* TODO: find i (line16) using sqrt() */

#include <iostream>
#include <cmath>
using namespace std;

unsigned int distance(unsigned int x, unsigned int y) {
    unsigned int dist = y - x;
    if (dist <= 2)
        return dist;
    
    else {
        unsigned int i = 2;
        
        while(1) {
            // find minimum number that number^2 is larger than dist
            if (pow(i, 2) >= dist)
                break;
            i++;
        }

        // calculate the answer
        if (dist <= (pow(i, 2) + pow(i-1, 2))/2)
            return 2 * i - 2;
        else
            return 2 * i - 1;
        
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
 
    while(t--) {
        unsigned int x, y;
        cin >> x >> y;
        cout << distance(x, y) << endl;
    }
    return 0;
}