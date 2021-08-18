#include <iostream>
using namespace std;

int main(){
    int a, b, c; // input: a-fixed cost, b-variable cost, c-price for sale
    scanf("%d %d %d", &a, &b, &c);

    if (c <= b) // avoid division by 0
        printf("-1");
    else {
        printf("%d", (a/(c-b)+1));
    }
    return 0;
}