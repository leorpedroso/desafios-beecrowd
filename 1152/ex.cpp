#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
#define INF 0x3f3f3f3f


typedef pair<int, int> dupla; // define uma dupla de inteiros a ser usada no heap
vector< pair<int, int> > grafo[MAXN];// define o grafo por lista de adjacência

int antecessor[MAXN];// define a árvore como um vetor de antecessores, sendo a raiz o zero

void min_prim(int m) {
    priority_queue< dupla, vector <dupla> , greater<dupla> > heap; // heap mínimo

    int adicionado[MAXN];// vetor que indica se um vértice foi adicionado na árvore
    int custos[MAXN];// vetor que indica o menor custo adjacente na árvore

    memset(adicionado, 0, sizeof(adicionado));
    memset(custos, INF, sizeof(custos));// coloca todos os custos iguais a infinito

    heap.push(make_pair(0, 0));// adiciona o vértice inicial na árvore

    while (!heap.empty()) { // executa até adicionar todos os vértices na árvore
        int vertice = heap.top().second;// seleciona o vértice do topo
        heap.pop();// elimina o topo
        adicionado[vertice] = 1;//faz com que o vértice esteja na arvore
        for(int i = 0; i < grafo[vertice].size(); i++) { //Percorre os adjacentes
            int adjacente = grafo[vertice][i].second; // identifica o adjacente
            if (adicionado[adjacente] == 0 && grafo[vertice][i].first < custos[adjacente]) {
                custos[adjacente] = grafo[vertice][i].first; // atualiza o melhor custo
                heap.push(make_pair(custos[adjacente], adjacente));// insere a dupla no heap
                antecessor[adjacente] = vertice; // atualiza o antecessor do adjacente.
            }
        }
    }
}

int main() {
    int m, n;
    while(cin >> m >> n) {
        if (m==0 && n==0) break;

        for (int i=0; i<m; i++) {
            grafo[i].clear();
            antecessor[i] = -1;
        }

        int total_cost = 0;
        for (int i=0; i<n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            grafo[x].push_back(make_pair(z, y));
            grafo[y].push_back(make_pair(z, x));
            total_cost += z;
        }

        min_prim(m);

        int min_count = 0;

        for (int i=1; i<m; i++) {
            // cout << antecessor[i] << " - " << i << endl;
            for (auto j : grafo[i]) {
                if (j.second == antecessor[i])
                    min_count += j.first;
            }
        }
        cout << total_cost - min_count << endl;
    }

    return 0;
}