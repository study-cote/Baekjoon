#include <iostream>
using namespace std;

int main()
{
    int n, num = 1, row = 1;
    scanf("%d", &n);
    
    while(1) { // to find row
        if (n <= num){
            printf("%d", row);
            break;
        }
        num += (row * 6); // num: total number of nodes from now + row 'n' consists of '6n' nodes.
        row++;
    }

    return 0;
}
