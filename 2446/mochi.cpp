// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <bits/stdc++.h>

using namespace std;

void print_table(vector<bool> table, int index) {
    cout << "INDEX " << index << endl;
    for (auto b : table) {
        cout << b << ' ';
    }
    cout << endl;
}

int mochila(int M, int V, int val[]) {

    vector<bool> table(V+1);

    table[0] = true;

    //  moedas = [25, 10, 5, 1]
    //                      *
    //  0   1   2   3   4   5
    //  f   f   t   t   f   f
    //        
    for (int j=0; j<M; j++) {
        for (int i=V; i>=val[j]; i--) {
            if (val[j] == i) {
                table[i] = true;
            }
            table[i] = table[i] || table[i-val[j]];
        }
        // print_table(table, j);
    }

    return table[V];
}

int main(){
    int V, M;
    cin >> V >> M;

    int arr[M];
    int i=0;
    while (cin >> arr[i]) {
        i++;
    }

    cout << (mochila(M, V, arr) ? 'S' : 'N');
    cout << endl;

}