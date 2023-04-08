#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    int N;//numero de clientes
    scanf("%d", &N);
    int C;//cliente cabeca
    scanf("%d", &C);
    int k;//criterio de escolha primeiro atendente
    scanf("%d", &k);
    int l;//segundo criterio de esoclha atendente
    scanf("%d", &l);

    Lista *Listacir=CriaListaCDup();

    for(int i=0;i<N;i++){
        insereNoInicioLista(Listacir,i);
    }
    NoCir *at_1=procura_no(Listacir,C);//Nó atendente 1
    NoCir *at_2=at_1;//Nó atendente 2
    NoCir *aux1;
    NoCir *aux2;
    for(int j=0;j<k;j++){
            at_1=at_1->ant;
        }
    for(int m=0;m<l;m++){
            at_2=at_2->prox;

        }

    while(!ListaEstaVazia(Listacir)){
        printf("%d %d\n", at_1->Cliente, at_2->Cliente);
        aux1=at_1->prox;
        aux2=at_2->ant;
        if(at_1->Cliente==at_2->Cliente){
            removeNoLista(Listacir, at_1->Cliente);

        }
        else{
            removeNoLista(Listacir, at_1->Cliente);
            removeNoLista(Listacir, at_2->Cliente);
        }
        if(ListaEstaVazia(Listacir)){
            aux1=aux2=at_1=at_2=NULL;
            break;
        }
        aux1=procura_no(Listacir, aux1->Cliente);
        aux2=procura_no(Listacir, aux2->Cliente);
        at_1=aux1;
        at_2=aux2;
        for(int b=0;b<k;b++){
            at_1=at_1->ant;
        }
        for(int v=0;v<l;v++){
            at_2=at_2->prox;
        }
    }
    free(Listacir->ini);
    free(Listacir->fim);
    free(Listacir);
    free(aux1);
    free(aux2);
    free(at_1);
    free(at_2);
    return 0;
}
