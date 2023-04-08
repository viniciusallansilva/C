#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    int vertices, arestas;
    scanf("%d %d", &vertices, &arestas);
    Grafo* mapa_unicamp=cria_Grafo(vertices, arestas);

    int U,V,W;
    for(int i=0;i<arestas;i++){
        scanf("%d %d %d", &U,&V,&W);
        insereAresta(mapa_unicamp,U,V,W,0);
    }
    int *anterior=cria_vetor(vertices);
    int *distancia=cria_vetor(vertices);

    menorCaminho_Grafo(mapa_unicamp,0,anterior,distancia);
    if(comparador(vertices)==0)
        removeAresta(mapa_unicamp,anterior[anterior[anterior[vertices-1]]],anterior[anterior[vertices-1]]);
    else
        removeAresta(mapa_unicamp,anterior[vertices-1],vertices-1);

    menorCaminho_Grafo(mapa_unicamp,0,anterior, distancia);

    printf("%d\n", distancia[vertices-1]);

    libera_vetor(anterior);
    libera_vetor(distancia);
    libera_Grafo(mapa_unicamp);
    return 0;
}
