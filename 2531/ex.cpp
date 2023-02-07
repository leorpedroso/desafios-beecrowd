#include <iostream>
#include <limits>

using namespace std;

#define MAXN 100000

struct SegTreeNode {
    int low;
    int high;
};

SegTreeNode segTree[4 * MAXN];
int maiores[4 * MAXN]; // árvore de segmentos de maiores
int menores[4 * MAXN]; // árvore de segmentos de menores
int n; // quantidade de elementos no vetor


// chamar com: no = 1 (raiz), inicio = 0 (início do vetor), fim = n - 1 (fim do vetor)
void constroi(int vetor[], int no, int inicio, int fim) { // inicializa a árvore do vetor
    if (inicio == fim) { // se está numa folha
        segTree[no].high = vetor[fim];
        segTree[no].low = vetor[fim];
    } else {
        int metade = (inicio + fim) / 2; // metade do vetor
        constroi(vetor, 2 * no, inicio, metade); // constrói o filho esquerdo
        constroi(vetor, 2 * no + 1, metade + 1, fim); // constrói o filho direito
        segTree[no].high = max(segTree[2 * no].high, segTree[2 * no + 1].high);
        segTree[no].low = min(segTree[2 * no].low, segTree[2 * no + 1].low);
    }
}

void atualiza(int posicao, int valor, int no, int inicio, int fim) {
    if (inicio == fim) {
        segTree[no].high = valor;
        segTree[no].low = valor;
    }
    else {
        int metade = (inicio + fim) / 2; // calcula metade
        if (posicao <= metade) // verifica se a atualização é à esquerda
            atualiza(posicao, valor, 2 * no, inicio, metade); // atualiza no filho esquerdo
        else // caso contrário a atualização é à direita
            atualiza(posicao, valor, 2 * no + 1, metade + 1, fim);

        segTree[no].high = max(segTree[2 * no].high, segTree[2 * no + 1].high); // atualiza a soma do nó
        segTree[no].low = min(segTree[2 * no].low, segTree[2 * no + 1].low); // atualiza a soma do nó
    }
}

SegTreeNode busca(int i, int j, int no, int inicio, int fim) {
    if (i > j) {
        SegTreeNode node;
        node.high = numeric_limits<int>::min();
        node.low = numeric_limits<int>::max();
        return node;
    }
    if (inicio == i && fim == j) {
        return segTree[no];
    }

    int metade = (inicio + fim) / 2;

    SegTreeNode n1 = busca(i, min(metade, j), 2 * no, inicio, metade);
    SegTreeNode n2 = busca(max(i, metade + 1), j, 2 * no + 1, metade + 1, fim);
    SegTreeNode n;

    n.high = max(n1.high, n2.high);
    n.low = min(n1.low, n2.low);
    return n;
}

int main() {

    int N;
    while (cin >> N) {

        int prices[N];

        for (int i=0; i<N; i++) {
            scanf("%d", &prices[i]);
            // cin >> prices[i]; 
        }

        constroi(prices, 1, 0, N-1);

        int Q;
        cin >> Q;
        
        for (int i=0; i<Q; i++) {
            int op, first, second;
            scanf("%d %d %d", &op, &first, &second);
            // cin >> op >> first >> second;
            
            if (op == 1) {
                atualiza(first-1, second, 1, 0, N-1);
            }
            else {
                SegTreeNode node = busca(first-1, second-1, 1, 0, N-1);
                printf("%d\n",node.high - node.low);
            }
        }

    }

    return 0;
}