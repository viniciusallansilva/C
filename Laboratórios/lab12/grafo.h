#ifndef _GRAFO_H_
#define _GRAFO_H_

struct grafo{
    int numero_vertices;
    int numero_arestas;
    int** arestas;
    int** tempos;
    int* vizinhos;
};

typedef struct grafo Grafo;

int* cria_vetor(int tamanho);

void libera_vetor(int* vetor);

int** cria_matriz(int NV);

void libera_matriz(int** matriz, int NV);

Grafo *cria_Grafo(int quantidade_vertices, int quantidade_arestas);

void libera_Grafo(Grafo* gr);

void insereAresta(Grafo* gr, int orig, int dest,int tempo, int e_digrafo);

void removeAresta(Grafo* gr, int origem, int destino);

void printa_grafo(Grafo* gr);

void menorCaminho_Grafo(Grafo *gr, int inicio, int* anterior, int *distancia);

int segundo_menor_tempo(Grafo*gr,int origem, int **distancia);

int comparador(int vertices);

#endif // _GRAFO_H_
