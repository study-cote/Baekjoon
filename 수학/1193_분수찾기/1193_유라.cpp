#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    if (n==1) {
        printf("1/1");
        return 0;
    }
    
    int num = 1;
    int row = 2;
    
    // to find row
    while(1) {
        num += row;
        if (n <= num)
            break;
        row++;
    }
    
    int sum = row + 1; // sum of fraction

    if (row % 2 == 0)
        down = num - n + 1;
        up = sum - down;
    else
        up = num - n + 1;
        down = sum - up;
 
    print("%d/%d", up, down);
    return 0;
}