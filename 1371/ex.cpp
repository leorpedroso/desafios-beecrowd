#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    while(cin >> N && N) {
        int i = 1;
        while(true) {
            long long sqr = i*i;
            long long nxt = (i+1) * (i+1);
            if(sqr > N) break;
            cout << sqr;
            if (nxt <= N) cout << " ";
            i++;
        }
        cout << endl;

    }

    return 0;
}