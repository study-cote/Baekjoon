#include <iostream>
using namespace std;

int main()
{
    int t; // the number of test case
    cin >> t;
    
    for (int i=0; i<t; i++) {
        int h=0, w, n; // height, width, nth customer
        cin >> h >> w >> n;
        
        int cnt = 0, x = 0; // x = room number
        do {
            x++;
            cnt = x*h;
        } while(cnt<n);
        
        int y = n%h; // floor
        if (y==0)
            y = h;
           
        int tmp = y * 100 + x; // sum x and y
        cout << tmp << "\n";
    }
    return 0;
}