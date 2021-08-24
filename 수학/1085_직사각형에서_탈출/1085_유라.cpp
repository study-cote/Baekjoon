#include <iostream>
using namespace std;

int main() {
    int x,y,w,h,dist=0;
    cin >> x >> y >> w >> h;

    dist = x;
    if (y < dist)
        dist = y;

    // x axis
    if (w<x && x-w < dist)
        dist = x-w;
    if (w>x && w-x < dist)
        dist = w-x;
    
    // y axis
    if (h<y && y-h < dist)
        dist = y-h;
    if (h>y && h-y < dist)
        dist = h-y;
        
    cout << dist;

    return 0;
}