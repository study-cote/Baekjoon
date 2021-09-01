#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 1~n 까지의 요소를 가지는 벡터
    vector<int> v;
    for (int i=1; i<=n; i++)
        v.push_back(i);

    // nPm
    do {
        for (int i=0; i<m; i++)
            cout << v[i] << " ";
        cout << "\n";
        // 시간 초과 발생했었는데, cout << endl; 이 원인이었음.
        // endl은 버퍼를 flush 하는 것을 겸하기 때문에 느리다 (시간 많이 걸린다) 고 함.
        reverse(v.begin()+m, v.end());
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}