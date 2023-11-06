#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, C, R1, R2;
    while(cin >> L >> C >> R1 >> R2) {
        if (L+C+R1+R2 == 0) break;

        if((R1*2 <= L) && (R1*2 <= C) && 
        (R2*2 <= L) && (R2*2 <= C)) {
            double dist = sqrt((R1-(L-R2))*(R1-(L-R2)) + (R1-(C-R2))*(R1-(C-R2)));
            if (dist >= R1+R2) {
                cout << "S" << endl;
            }            
            else {
                cout << "N" << endl;
            }
        }
        else cout << "N" << endl;

    }

}