#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    
    double answer = double(v-a)/double(a-b) + 1;
    
    if (answer <= 0) // if answer <= 0 considers as 1 day
        answer = 1;
    else
        answer = ceil(answer); // consider float points
        
    printf("%d", (int)answer);
    return 0;
}