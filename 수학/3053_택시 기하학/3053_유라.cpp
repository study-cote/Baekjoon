#include <iostream>
#include <math.h> // to use M_PI
using namespace std;

double non_euclidean(int r){
    return 2 * (r * r);
}

double euclidean(int r) {
    return (r * r) * M_PI;
}

int main() {
    int r;
    cin >> r;

    printf("%.6f\n", euclidean(r));
    printf("%.6f", non_euclidean(r));

    return 0;
}