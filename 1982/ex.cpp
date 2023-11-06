#include <bits/stdc++.h>

using namespace std;

typedef struct PONTO {
    double x,y;
} ponto;

vector<ponto> pontos;

ponto extremo;// extremo esquerdo inferior
bool compara(ponto p1,ponto p2) {// compara pela tangente do angulo
    double dx1=p1.x-extremo.x, dx2=p2.x-extremo.x;
    double dy1=p1.y-extremo.y,dy2=p2.y-extremo.y;

    if(dx1== 0) return dy1== 0 || (dx2== 0 && dy1<dy2);
    if(dx2== 0) return dy2!= 0;

    if(dy1*dx2==dy2*dx1) return dx1<dx2;
    if(dx1*dx2< 0) return dy1*dx2>dy2*dx1;

    return dy1*dx2<dy2*dx1;
}

bool esquerda(ponto p1,ponto p2,ponto p3) {// verifica se p3 está a esquerda de p1->p2
    return((p1.x-p3.x) * (p2.y-p3.y) - (p2.x-p3.x) * (p1.y-p3.y)) > 0;
}

vector<ponto> convexo() {
    extremo=pontos[0];
    for(int i= 1 ;i< (int)pontos.size();i++)
        if(pontos[i].x<extremo.x|| (pontos[i].x==extremo.x&&pontos[i].y<extremo.y))
            extremo=pontos[i];
            
        sort(pontos.begin(),pontos.end(),compara);
        vector<ponto> envoltorio;
        envoltorio.push_back(pontos[0]);
        
        int n= 1;
        for(int i= 1;i< (int)pontos.size();i++) {
            while(n> 1 && !esquerda(envoltorio[n- 2],envoltorio[n- 1],pontos[i])){
                n--;
                envoltorio.pop_back();
            }
            
            envoltorio.push_back(pontos[i]);
            n++;
        }
            
        return envoltorio;
}

double distancia(ponto p1, ponto p2) {// distância entre dois pontos
    double dx=p1.x-p2.x,dy=p1.y-p2.y;
    return sqrt(dx*dx+dy*dy);
}

double perimetro(vector<ponto> poligono) {
    double resultado= 0;
    for(int i= 1;i< (int)poligono.size();i++)// soma cada lado do polígono
        resultado += distancia(poligono[i- 1], poligono[i]);
    
    return resultado;
}

int main() {
    int N;

    while(cin >> N && N) {
        pontos.clear();
        for(int i=0; i<N; i++) {
            int X, Y;
            cin >> X >> Y;
            ponto p;
            p.x = X;
            p.y = Y;
            pontos.push_back(p);
        }

        vector<ponto> v = convexo();

        // for(int i=0; i<v.size(); i++) {
        //     cout << v[i].x << "," << v[i].y << " ";
        // }
        // cout << endl;
        v.push_back(v[0]);
        double total = perimetro(v);

        cout << "Tera que comprar uma fita de tamanho " << fixed << setprecision(2) << total << "." << endl;
    }

}