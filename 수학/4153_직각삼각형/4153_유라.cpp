#include <iostream>
#include <cmath>
using namespace std;

void is_triangle(int a, int b, int c) {
    a = a*a;
    b = b*b;
    c = c*c;

    if (a+b==c)
        cout << "right" << endl;
    else
        cout << "wrong" << endl;
    
    return;
}

int main() {
    int a,b,c;

    while(1) {
        cin >> a >> b >> c;
        if (a==0 && b==0 && c==0)
            break;
        if (a<c && b<c)
            is_triangle(a, b, c);
        else if(a<b && c<b)
            is_triangle(a, c, b);
        else
            is_triangle(b, c, a);
    }

    return 0;
}