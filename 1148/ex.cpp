#include <bits/stdc++.h>
#define MAXN 501
#define INF 0x3f3f3f3f

using namespace std;

int grafo[MAXN][MAXN];// matriz de adjacência do grafo (se o arco não existir o valor é INF)
int intermediario[MAXN][MAXN];// vértice intermediário no caminho de i (linha) a v (coluna)
int custos[MAXN][MAXN];// custo do caminho de i (linha) ate v (coluna)

void floyd_warshall(int n) {
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            custos[u][v] = grafo[u][v]; // o custo inicial de u até v é o da aresta
        }
        custos[u][u] = 0; // o custo do caminho de cada vértice até ele mesmo é zero
    }

    for (int k = 0; k < n; k++) { // percorre cada possível vértice intermediário
        for (int i = 0; i < n; i++) { // percorre cada possível origem do caminho
            for (int j = 0; j < n; j++ ) { // percorre cada possível destino do caminho
                if((custos[i][k] + custos[k][j] < custos[i][j])
                    && (custos[k][j] != numeric_limits<int>::max())
                    && (custos[i][k] != numeric_limits<int>::max())
                ) {
                    custos[i][j] = custos[i][k] + custos[k][j]; // atualiza o custo
                    intermediario[i][j] = k; // coloca k no caminho entre i e j
                }
            }
        }
    }

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++)
    //         cout << custos[i][j] << "\t\t";
        
    //     cout << endl;
    // }
}

int main() {
    int N, E;
    while (cin >> N >> E) {
        if (N==0 && E==0) break;

        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                grafo[i][j] = numeric_limits<int>::max();

        for (int i=0; i<E; i++) {
            int X, Y, H;
            cin >> X >> Y >> H;
            
            grafo[X-1][Y-1] = H;
            if (grafo[Y-1][X-1] != numeric_limits<int>::max()) {
                grafo[X-1][Y-1] = 0;
                grafo[Y-1][X-1] = 0;
            }
        }

        floyd_warshall(N);

        // for (int i=0; i<N; i++) {
        //     for (int j=0; j<N; j++)
        //         cout << custos[i][j] << "\t\t";
            
        //     cout << endl;
        // }

        int K;
        cin >> K;

        for (int i=0; i<K; i++) {
            int O, D;
            cin >> O >> D;

            if (custos[O-1][D-1] != numeric_limits<int>::max())
                cout << custos[O-1][D-1] << endl;
            else
                cout << "Nao e possivel entregar a carta" << endl;
        }
        cout << endl;
    }
    return 0;
}