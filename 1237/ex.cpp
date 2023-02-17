#include <bits/stdc++.h>
using namespace std;

#define MAX 500
// char sequencia1[MAX];
// char sequencia2[MAX];
// int tabela[2][MAX + 1];// tabela dinâmica

char sequencia1[MAX];
char sequencia2[MAX];
int tabela[MAX + 1][MAX + 1];// tabela dinâmica

// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

int LCSubStr(char* X, char* Y, int m, int n)
{
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.  
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].
 
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring
 
    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}


int main () {
    while (cin.getline(sequencia1, MAX)) {
        cin.getline(sequencia2, MAX);

        cout << LCSubStr(sequencia1, sequencia2, strlen(sequencia1), strlen(sequencia2)) << endl;

    }
    return 0;
}