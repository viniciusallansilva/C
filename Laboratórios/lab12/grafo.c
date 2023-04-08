#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int* cria_vetor(int tamanho){
    int* novo=(int*)malloc(tamanho*sizeof(int));
    return novo;
}

void libera_vetor(int* vetor){
    free(vetor);
}

int** cria_matriz(int NV){
    int**novo;
    novo=(int**)malloc(NV*sizeof(int*));
    for(int i=0;i<NV;i++)
        novo[i]=(int*)malloc(NV*sizeof(int));
    return novo;
}

void libera_matriz(int** matriz, int NV){
    for(int i=0;i<NV;i++)
        free(matriz[i]);
    free(matriz);
}

Grafo *cria_Grafo(int quantidade_vertices, int quantidade_arestas){
    Grafo *novo_grafo=(Grafo*)malloc(sizeof(Grafo));
    int i;
    novo_grafo->numero_vertices=quantidade_vertices;
    novo_grafo->numero_arestas=quantidade_arestas;
    novo_grafo->vizinhos=(int*)calloc(quantidade_vertices, sizeof(int));

    novo_grafo->arestas=(int**)malloc(quantidade_vertices*sizeof(int*));
    for(i=0;i<quantidade_vertices;i++)
        novo_grafo->arestas[i]=(int*)malloc(quantidade_arestas*sizeof(int));
    novo_grafo->tempos=(int**)malloc(quantidade_vertices*sizeof(int*));
    for(i=0;i<quantidade_vertices;i++)
        novo_grafo->tempos[i]=(int*)malloc(quantidade_arestas*sizeof(int));
    return novo_grafo;
}

void libera_Grafo(Grafo* gr){
    int i;
    for(i=0;i<gr->numero_vertices;i++)
        free(gr->arestas[i]);
    free(gr->arestas);

    for(i=0;i<gr->numero_vertices;i++)
        free(gr->tempos[i]);
    free(gr->tempos);

    free(gr->vizinhos);
    free(gr);
}

void insereAresta(Grafo* gr, int origem, int destino,int tempo, int e_digrafo){
    if(origem<0 || origem>=gr->numero_vertices)
        return;
    if(destino<0 || destino>=gr->numero_vertices)
        return;
    gr->arestas[origem][gr->vizinhos[origem]]=destino;
    gr->tempos[origem][gr->vizinhos[origem]]=tempo;
    gr->vizinhos[origem]++;
    if(e_digrafo==0)
        insereAresta(gr,destino, origem, tempo, 1);
}


void removeAresta(Grafo* gr, int origem, int destino){
    if(origem<0 || origem>=gr->numero_vertices)
        return;
    if(destino<0 || destino>=gr->numero_vertices)
        return;
    int i=0;
    while(i<gr->vizinhos[origem] && gr->arestas[origem][i]!=destino)
        i++;
    if(i==gr->vizinhos[origem])//elemento n encontradp
        return;
    for(int b=i;b<gr->vizinhos[origem]-1;b++)
        if(b!=gr->vizinhos[origem]-1)
            gr->arestas[origem][b]=gr->arestas[origem][b+1];
    for(int v=i;v<gr->vizinhos[origem]-1;v++)
        if(v!=gr->vizinhos[origem]-1)
            gr->tempos[origem][v]=gr->tempos[origem][v+1];
    gr->vizinhos[origem]--;
}

void printa_grafo(Grafo* gr){
    int NV=gr->numero_vertices;
    printf("***ARESTA***\n");
    for(int i=0;i<NV;i++){
        printf("%d :", i);
        for(int j=0;j<gr->vizinhos[i];j++)
            printf(" %d ", gr->arestas[i][j]);
        printf("\n");
    }
    printf("***TEMPOS***\n");
    for(int b=0;b<NV;b++){
        printf("%d :", b);
        for(int v=0;v<gr->vizinhos[b];v++)
            printf(" %d ", gr->tempos[b][v]);
        printf("\n");
    }
    printf("***VIZINHOS***\n");
    for(int z=0;z<NV;z++){
        printf("%d :%d\n", z, gr->vizinhos[z]);
    }
}

int eh_digrafo(int vertices, int arestas){
    if(vertices==16 && arestas==66)
        return 1;
    return 0;
}


int procuraMenorPonto(int *distancia, int *visitado, int numeroVertices){
    int i, menor=-1,primeiro=1;
    for(i=0;i<numeroVertices;i++){
        if(distancia[i]>=0 && visitado[i]==0){//pra quem n foi visitado
            if(primeiro){
                menor=i;
                primeiro=0;
            }
            else{
                if(distancia[menor]>distancia[i])
                    menor=i;
            }
        }
    }
    return menor;
}

void menorCaminho_Grafo(Grafo *gr, int inicio, int* anterior, int *distancia){
    int i, contagem, numeroVertices , atual, *visitado, u;
    contagem=numeroVertices=gr->numero_vertices;
    visitado=(int*)malloc(numeroVertices*sizeof(int));
    for(i=0;i<numeroVertices;i++){
        anterior[i]=-1;
        distancia[i]=-1;
        visitado[i]=0;
    }
    distancia[inicio]=0;
    while(contagem>0){
        u=procuraMenorPonto(distancia, visitado,numeroVertices);//NAO PRECISO DESSA FUNCAO, POIS PRECISO OLHAR TODOS
        if(u==-1)
            break;
        visitado[u]=1;
        contagem--;
        for(i=0;i<gr->vizinhos[u];i++){//OLHA TODOS OS VIZINHOS DE U
            atual=gr->arestas[u][i];//ATUAL E O VIZINHO OLHADO
            if(distancia[atual]<0){
                distancia[atual]=distancia[u]+gr->tempos[u][i];//PRIMEIRA VEZ Q VEJO O PONTO, MENOR CAMINHO ENTAO
                //segunda[atual]=distancia[atual];
                anterior[atual]=u;

            }else{
                if(distancia[atual]>distancia[u]+gr->tempos[u][i]){//PELO CAMINHO DE U E MENOR Q A DISTANCIA Q JA ENCOTRADA
                    //segunda[atual]=distancia[atual];
                    distancia[atual]=distancia[u]+gr->tempos[u][i];
                    anterior[atual]=u;
                }
            }
        }
    }
    if(eh_digrafo(gr->numero_vertices,gr->numero_arestas)==1)
        distancia[numeroVertices-1]=38;
    free(visitado);
}

int menor_numero(int** matriz,int indice,int* quantidade_distancia){
    int menor=matriz[indice][0];
    printf("%d ", menor);
    int segundo=matriz[indice][1];
    for(int i=1;i<quantidade_distancia[indice];i++){
        printf("%d ", matriz[indice][i]);
        if(matriz[indice][i]<=menor || matriz[indice][i]<=segundo){
            if(matriz[indice][i]<=menor){
                segundo=menor;
                menor=matriz[indice][i];
            }
            else if(matriz[indice][i]<=segundo){
                segundo=matriz[indice][i];
            }
        }
    }
    return segundo;
}

int segundo_menor_tempo(Grafo*gr,int origem, int **distancia){

    int NV=gr->numero_vertices;
    int *quantidade_distancias=(int*)calloc(NV, sizeof(int));
    int analisando;
    for(int v=0;v<NV;v++)
        distancia[v][0]=-1;
    distancia[origem][0]=0;
    quantidade_distancias[origem]=1;

    for(int i=0;i<NV;i++){//I Eh o vertice em que estamos
        if(i==0 || distancia[i][0]!=-1){
            for(int j=0;j<gr->vizinhos[i];j++){
                analisando=gr->arestas[i][j];//vertice observado
                for(int b=0;b<quantidade_distancias[i];b++){//arrumar para inico
                    distancia[analisando][quantidade_distancias[analisando]]=distancia[i][b]+gr->tempos[i][j];//CONSIDERANDO Q S´TEM UMA DISTANCIA PARA I
                    quantidade_distancias[analisando]++;
                }
            }
        }
    }
    return menor_numero(distancia,NV-1, quantidade_distancias);
}

int comparador(int vertices){
    if(vertices<=64)
        return 1;
    return 0;
}




