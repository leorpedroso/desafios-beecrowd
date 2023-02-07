#include <iostream>
#include <string>

using namespace std;

#define MAXN 100000

int mults[4 * MAXN]; // árvore de segmentos de maiores
int n; // quantidade de elementos no vetor

// chamar com: no = 1 (raiz), inicio = 0 (início do vetor), fim = n - 1 (fim do vetor)
void constroi(int vetor[], int no, int inicio, int fim) { // inicializa a árvore do vetor
    if (inicio == fim) { // se está numa folha
        mults[no] = vetor[fim];
    } else {
        int metade = (inicio + fim) / 2; // metade do vetor
        constroi(vetor, 2 * no, inicio, metade); // constrói o filho esquerdo
        constroi(vetor, 2 * no + 1, metade + 1, fim); // constrói o filho direito
        int a = mults[2 * no];
        int b = mults[2 * no + 1];

        if ( a == 0 || b == 0) mults[no] = 0;
        else if (a == b) mults[no] = 1;
        else mults[no] = -1;
        // mults[no] = mults[2 * no] * mults[2 * no + 1];
    }
}

void atualiza(int posicao, int valor, int no, int inicio, int fim) {
    if (inicio == fim) {
        if (valor == 0) mults[no] = 0;
        else if (valor > 0) mults[no] = 1;
        else mults[no] = -1;
        // mults[no] = valor;
    }
    else {
        int metade = (inicio + fim) / 2; // calcula metade
        if (posicao <= metade) // verifica se a atualização é à esquerda
            atualiza(posicao, valor, 2 * no, inicio, metade); // atualiza no filho esquerdo
        else // caso contrário a atualização é à direita
            atualiza(posicao, valor, 2 * no + 1, metade + 1, fim);

        int a = mults[2 * no];
        int b = mults[2 * no + 1];

        if ( a == 0 || b == 0) mults[no] = 0;
        else if (a == b) mults[no] = 1;
        else mults[no] = -1;
        // mults[no] = mults[2 * no] * mults[2 * no + 1];
    }
}

int busca(int i, int j, int no, int inicio, int fim) {
    if (i > j) {
        return 1;
    }
    if (inicio == i && fim == j) {
        return mults[no];
    }

    int metade = (inicio + fim) / 2;

    return busca(i, min(metade, j), 2 * no, inicio, metade) * busca(max(i, metade + 1), j, 2 * no + 1, metade + 1, fim);
}

int main() {
    int N, K;
    while (cin >> N) {
        cin >> K;

        int values[N];
        string output;

        for (int i=0; i<N; i++) {
            int in;
            cin >> in; 
            if (in == 0) {
                values[i] = 0;
            }

            else if (in > 0) {
                values[i] = 1;
            }

            else if (in < 0) values[i] = -1;
        }

        constroi(values, 1, 0, N-1);
        
        for (int i=0; i<K; i++) {
            char op;
            int first, second;
            cin >> op >> first >> second;

            if (op == 'C') {
                atualiza(first-1, second, 1, 0, N-1);
            }
            else {
                int mul = busca(first-1, second-1, 1, 0, N-1);
                
                if (mul > 0) output.push_back('+');
                if (mul < 0) output.push_back('-');
                if (mul == 0) output.push_back('0');
            }
        }
        cout << output << endl;
    }

    return 0;
}