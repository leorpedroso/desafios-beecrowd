#include <iostream>
#include <string>

#define MAX 100000

using namespace std;

int cjt[MAX]; // conjunto do elemento i
int n[MAX]; // quantidade de elementos no conjunto
int points[MAX];

void constroi() { //função que inicializa o conjunto disjunto
    for(int i = 0; i < MAX; i++) {
        cjt[i] = i; // inicialmente o elemento está no conjunto que só o contem
        n[i] = 1; // inicialmente o conjunto somente tem um elemento
    }
}

// ok
int busca(int i) { // função que procura o conjunto em que está um elemento
    if(i != cjt[i]) // verifica se é o topo do conjunto
        cjt[i] = busca(cjt[i]); // se não for o topo procura o topo e comprime caminho

    return cjt[i]; // retorna o topo do conjunto
}

void une(int i, int j) { // função que une os conjuntos de dois elementos
    int si = busca(i), sj = busca(j); // procura o topo dos conjuntos de i e j
    if(si != sj) { // somente une se estiverem em conjuntos diferentes
        if(n[si] >= n[sj]) { // coloca o de menor quantidade no de maior
            cjt[sj] = si; // sj não é mais topo, agora o topo dele é si
            n[si] += n[sj]; // atualiza a quantidade no topo
            points[si] += points[sj];
        } else {
            cjt[si] = sj; // si não é mais topo, agora o topo dele é sj
            n[sj] += n[si]; // atualiza a quantidade no topo
            points[sj] += points[si];
        }
    }
}

int main() {
    int N, M;
    
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        
        int wins = 0;
        
        constroi();

        for (int i=0; i<N; i++) {
            cin >> points[i];
        }

        for (int i=0; i<M; i++) {
            int Q, A, B;
            cin >> Q >> A >> B;
            if (Q == 1) {
                une(A-1, B-1);
            }
            else {
                int g1 = busca(A-1);
                int g2 = busca(B-1);
                int rafa = busca(0);
                int p1 = 0, p2 = 0;

                if (g1 == rafa && points[rafa] > points[g2])
                    wins++;

                else if (g2 == rafa && points[rafa] > points[g1])
                    wins++;
            }
        }
        
        cout << wins << endl;
    }
    
    return 0;
}