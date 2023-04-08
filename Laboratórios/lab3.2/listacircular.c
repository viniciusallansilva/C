#include "listacircular.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

lista * cria_nova_lista(){
    lista *novo=(lista *)malloc(sizeof(lista));
    novo->inicio=novo->fim=NULL;
    return novo;
}

no * cria_novo_no(int posicao){
    no* novo=(no*)malloc(sizeof(no));
    novo->Cliente=posicao;
    novo->Next=novo;
    novo->Back=novo;
    return novo;
}

int listavazia(lista *L){
    if((L->inicio && L->fim )== NULL)
        return 1;
    return 0;
}

void inserenalista(lista *L, int posicao){
    no* novo=cria_novo_no(posicao);
    //Se ela estiver vazia
    if(listavazia(L)==1){
        L->inicio=novo;
        L->fim=novo;
    }
    else{//Ja existem elementos
        novo->Next=L->inicio;
        L->inicio->Back=novo;
        L->inicio=novo;
        L->inicio->Back=L->fim;
        L->fim->Next=L->inicio;
    }
}

void removelista(lista *L, int posicao){
    no *no_procurador=L->inicio;
    do{
        if(no_procurador->Cliente==posicao){
            if(L->inicio==L->fim){
                L->inicio=NULL;
                L->fim=NULL;
                free(no_procurador);
                return;
            }
            else if(no_procurador==L->inicio){
                L->inicio=no_procurador->Next;
                L->inicio->Back=L->fim;
                L->fim->Next=L->inicio;
                free(no_procurador);
                return;
            }
            else if(no_procurador==L->fim){
                L->fim=no_procurador->Back;
                L->fim->Next=L->inicio;
                L->inicio->Back=L->fim;
                free(no_procurador);
                return;
            }
            else{
                no_procurador->Back->Next=no_procurador->Next;
                no_procurador->Next->Back=no_procurador->Back;
                free(no_procurador);
                return;
            }
        }
        else{
            no_procurador=no_procurador->Next;
        }
    }while(no_procurador!=L->fim);
}

void printa_lista(lista *L){
    no* novo=L->inicio;
    do{
        printf("%d\n", novo->Cliente);
        novo=novo->Next;
    }
    while(novo!=L->inicio);
}

no *procuraNo(lista *L, int posicao){
    no *novo=L->inicio;
    do{
        if(novo->Cliente==posicao)
            return novo;
        else
            novo=novo->Next;
    }while(novo!=L->inicio);
    return novo;
}
