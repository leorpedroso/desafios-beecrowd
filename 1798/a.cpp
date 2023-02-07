// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define MAXP 10000
int valores[MAXN]; // vetor com os valores dos itens
int pesos[MAXN]; // vetor com os pesos dos itens
int quantidades[MAXN];
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
            for (int i=1; i * pesos[item] <= peso && i <= quantidades[item]; i++) {
                solucao = max(solucao,
                              i * valores[item] + tabela[1 - atual][peso - i * pesos[item]]);
            }
            // colocar a solução encontrada na posição correspondente da tabela
            tabela[atual][peso] = solucao;
        }
    }
    // Retorna a solução equivalente na última linha calculada com o peso total
    return tabela[atual][peso_mochila];
}

/*
    peso maximo -> comprimento do cano -> T

*/

int main(){
    int T;
    cin >> n >> T;

    memset(tabela, 0, sizeof tabela);

    fill_n(valores, T, 0);
    fill_n(pesos, T, 0);
    fill_n(quantidades, T, 0);

    for (int i=0; i<n; i++) {
        cin >> pesos[i] >> valores[i];
        quantidades[i] = T/pesos[i];
    }

    cout << mochila(T) << endl;

    return 0;
}