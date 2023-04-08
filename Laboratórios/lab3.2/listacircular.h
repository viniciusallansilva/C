#ifndef _LISTACIRCULAR_H_
#define _LISTACIRCULAR_H_

typedef struct NoCircular{
    int Cliente;
    struct NoCircular *Next;
    struct NoCircular *Back;
}no;

typedef struct ListaCircular{
    no *inicio;
    no *fim;
}lista;

lista * cria_nova_lista();

no * cria_novo_no(int posicao);

int listavazia(lista *L);

void inserenalista(lista *L, int posicao);

void removelista(lista *L, int posicao);

void printa_lista(lista *L);

no *procuraNo(lista *L, int posicao);

#endif // _LISTACIRCULAR_H_

