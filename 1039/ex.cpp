#include <bits/stdc++.h>

using namespace std;

int main() {
    int R1, R2, X1, X2, Y1, Y2;
    while (cin >> R1 >> X1>> Y1>> R2>> X2>> Y2) {
        bool state =true;
        
        //dist entre dois centros deve ser menor que raio 2
        float dist = sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
        state = dist + R2 <= R1;
        cout << (state ? "RICO" : "MORTO") << endl;
    }

}