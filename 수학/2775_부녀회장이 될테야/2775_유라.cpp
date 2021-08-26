/* I implement both functions including and excepting loop.
Excepting loop is simpler but including loop takes less time. */

#include <iostream>
using namespace std;

int numofperson(int k, int n) { // including loop
    if (k==0) // room #n of 0 floor has n person
        return n;
    else {
        int ans = 0;
        while(n>0) {
            ans += numofperson(k-1, n);
            n--;
        }
        return ans;
    }
}

int numofperson_simple(int k, int n) { // except loop
    if (k==0)
        return n;
    else if (n==1)
        return 1;
    else
        return numofperson_simple(k, n-1) + numofperson_simple(k-1, n);
}

int main()
{
    int t;
    cin >> t;
    
    for (int i=0; i<t; i++) {
        int k, n; // k: floor, n: room #
        cin >> k >> n;
        cout << numofperson(k, n) << "\n";
    }
    
    return 0;
}
