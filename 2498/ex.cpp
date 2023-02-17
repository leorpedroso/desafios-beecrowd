// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define MAXP 10000
int valores[MAXN]; // vetor com os valores dos itens
int pesos[MAXN]; // vetor com os pesos dos itens
int n; // quantidade de itens
int tabela[2][MAXP + 1]; // tabela dinâmica (só duas linhas), inicializada com zeros

int mochila(int peso_mochila) {
    int atual = 0; // variável que indica a linha atual
    for (int item = n - 1; item >= 0; item--) {
        // troca a linha atual no início de cada iteração
        atual = 1 - atual;
        for (int peso = 0; peso <= peso_mochila; peso++) {
            // obter a melhor solução da linha anterior sem colocar o item
            int solucao = tabela[1 - atual][peso];
            // escolher a melhor solução entre a de carregar o item ou não
            if (pesos[item] <= peso &&
            solucao < valores[item] + tabela[1 - atual][peso - pesos[item]]) {
                solucao = valores[item] + tabela[1 - atual][peso - pesos[item]];
            }
            // colocar a solução encontrada na posição correspondente da tabela
            tabela[atual][peso] = solucao;
        }
    }
    // Retorna a solução equivalente na última linha calculada com o peso total
    return tabela[atual][peso_mochila];
}

int main(){
    int c;
    int caso = 1;
    while(cin >> n >> c) {

        memset(tabela, 0, sizeof tabela);
        if (n == 0 && c == 0) break;

        fill_n(valores, c, 0);
        fill_n(pesos, c, 0);

        for (int i=0; i<n; i++) {
            cin >> pesos[i] >> valores[i];
        }

        cout << "Caso " << caso << ": " << mochila(c) << endl;
        
        caso++;
    }

    return 0;
}