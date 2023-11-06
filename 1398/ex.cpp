#include <bits/stdc++.h>

using namespace std;

// 131071 in binary
#define BIN_131071 "11111111111111111"
#define BIN_LEN 17

int main() {
    string s;
    while(cin >> s) {
        // ler input multilinha
        while(s.at(s.length()-1) != '#' ){
            string str;
            cin >> str;
            s.append(str);
        }

        int curr = 0;

        if (s.length()-1 == 1 && s.at(0) == '0') {
            cout << "YES" << endl;
            continue;
        }
        if (s.length()-1 < 17) {
            cout << "NO" << endl;
            continue;
        }
        
        for(int i=0; i<s.length()-1; i++) {
            char c = s.at(i);
            int n;
            if (c == '1') n = 1;
            else n = 0;

            curr = (curr*2 + n) % 131071;
        }

        cout << (curr == 0 ? "YES" : "NO") << endl;

    }

    return 0;
}