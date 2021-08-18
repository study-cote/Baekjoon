#include <iostream>
using namespace std;

int main()
{
    int n, num = 1, row = 1;
    scanf("%d", &n);
    
    while(1) {
        if (n <= num){
            printf("%d", row);
            break;
        }
        num += (row * 6);
        row++;
    }

    return 0;
}