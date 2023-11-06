#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for(int i=0; i<tests; i++) {
        long long N;
        cin >> N;
        /*
            N = r*(r+1)/2;
            2N = r*(r+1)
            2N = r^2 + r
            r^2 + r - 2N = 0
            -1 +- sqrt(1 - 4*1*-2N) / 2
            -1 +- sqrt(1 + 8N) / 2
            -1 + sqrt(1 + 8N) / 2
        */

        long long rows = (-1 + sqrt(1 + 8*N)) / 2;

        cout << rows << endl;
    }

    return 0;
}