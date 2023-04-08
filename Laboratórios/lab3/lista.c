#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

// cria no e faz ele apontar pra ele msm e de volve seu endereco
NoCir *CriaNoCDup(int posicao_cliente){
    NoCir *p_no=(NoCir *)calloc(1, sizeof(NoCir));
    p_no->Cliente=posicao_cliente;
    p_no->prox=p_no->ant=p_no;
    return p_no;
}

//cria uma lista com seu inicio e fim apontando para NULL e devolve seu endereco
Lista *CriaListaCDup(){
    Lista *L = (Lista*) calloc(1, sizeof(Lista));
    L->ini=L->fim=NULL;
    return L;
}

//devolve TRUE se lista estiver vazia
int ListaEstaVazia(Lista *L){
    return(L->ini==NULL);
}

//insere elemento no inicio da lista
void insereNoInicioLista(Lista *L, int posicao_cliente){
    NoCir *p_no=CriaNoCDup(posicao_cliente);

    //se ela tiver vazia
    if(ListaEstaVazia(L)){
        L->ini=p_no;
        L->fim=p_no;
    }
    //caso ja exista elementos
    else{
        p_no->prox=L->ini;
        L->ini->ant=p_no;
        L->ini=p_no;
        L->ini->ant=L->fim;
        L->fim->prox=L->ini;
    }
}

void removeNoLista(Lista *L, int cliente){
    if(!ListaEstaVazia(L)){
        NoCir *p_no=L->ini;
        if(L->ini->Cliente==cliente){
            //apenas 1 elemento
            if(L->ini==L->fim){
                L->ini=L->fim=NULL;
                free(p_no);
            }
            //mais de 1 elemento
            else{
                L->ini=L->ini->prox;
                p_no->prox->ant=L->fim;
                L->fim->prox=L->ini;
                free(p_no);
            }
        }
        //elemento no meio da lista ou nao esta na lista
        else{
            p_no=p_no->prox;
            while(p_no!=L->ini){
                if(p_no->Cliente==cliente){
                    p_no->ant->prox=p_no->prox;
                    p_no->prox->ant=p_no->ant;
                    if(p_no==L->fim){
                        L->fim=p_no->ant;
                    }
                    free(p_no);
                    break;
                }
                else{
                    p_no=p_no->prox;
                }
            }
        }
    }
}

NoCir *procura_no(Lista *L, int posicao_cliente){
    NoCir *p_no=L->ini;
    if(p_no->Cliente==posicao_cliente){
            return p_no;
    }
    p_no=p_no->prox;
    while(p_no!=L->ini){
        if(p_no->Cliente==posicao_cliente){
            return p_no;
        }
        else{
            p_no=p_no->prox;
        }
    }
    return p_no;
}
