#include <iostream>
using namespace std;

int main()
{
    int n, cnt=0; // input
    cin >> n;
  
    while(n>0) {
        if (n%5==0) { // 5kg
            n-=5;
            cnt++;
        }
        
        else if (n%3==0) { // 3kg
            n-=3;
            cnt++;
        }
        
        else if (n>5) { // if combination of 5kg and 3kg is needed
            n-=5;
            cnt++;
        }
        
        else { // can't move with 5kg and 3kg
            printf("-1");
            return 0;
        }
    }
    
    printf("%d", cnt);
    return 0;
}