#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct no_cir{
    int Cliente;
    struct no_cir *prox;
    struct no_cir *ant;
}NoCir;

typedef struct list_circular_dupla{
    NoCir *ini;
    NoCir *fim;
} Lista;

NoCir *CriaNoCDup(int posicao_cliente);

Lista *CriaListaCDup();

int ListaEstaVazia(Lista *L);

void insereNoInicioLista(Lista *L, int posicao_cliente);

void removeNoLista(Lista *L, int val);

NoCir *procura_no(Lista *L,int posicao_cliente);

#endif // _LISTA_H_
