#include <iostream>
using namespace std;

int findroom(int k, int n) {
    if (k==0) // room #n of 0 floor has n person
        return n;
    else {
        int ans = 0;
        while(n>0) {
            ans += findroom(k-1, n);
            n--;
        }
        return ans;
    }
}

int main()
{
    int t;
    cin >> t;
    
    for (int i=0; i<t; i++) {
        int k, n; // k: floor, n: room #
        cin >> k >> n;
        cout << findroom(k, n) << "\n";
    }
    
    return 0;
}
