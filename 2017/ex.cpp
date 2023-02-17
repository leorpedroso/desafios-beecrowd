#include <bits/stdc++.h>
using namespace std;

#define MAX 100000


int main(){
    string x;
    cin >> x;

   
    int k;
    cin >> k;

    string arr[5];
    int dists[5] = { 0 };

    for (int i=0; i<5; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<x.size(); i++) {
        for (int j=0; j<5; j++) {
            if (x[i] != arr[j][i]) {
                dists[j] += 1;
            }
        }
    }

    // for (int i=0; i<5; i++) {
    //     cout << dists[i] << ' ';
    // }

    int mindist = MAX;
    int minindex = -1;
    for (int i=0; i<5; i++) {
        if (dists[i] < mindist) {
            mindist = dists[i];
            minindex = i+1;
        }
    }

    if (mindist <= k) {
        cout << minindex << endl;
        cout << mindist << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}