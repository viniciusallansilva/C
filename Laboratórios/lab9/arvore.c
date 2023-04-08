#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

p_no inserir(p_no raiz, int valor){
    p_no novo;
    if(raiz==NULL){//quando a arvore nao existe, o primeiro no recebido como NULL vira a raiz
        novo=malloc(sizeof(No));
        novo->left=novo->right=NULL;
        novo->value=valor;
        return novo;
    }
    //usando recursao ele procura o local para inserir
    if(valor<raiz->value)
        raiz->left=inserir(raiz->left, valor);//tenta inserir pra esquerda
    else
        raiz->right=inserir(raiz->right, valor);//tenta inserir pra direita
    return raiz;
}

int altura(p_no raiz){
    int high_left, high_right;
    if(raiz==NULL)//arvore com altura 0
        return 0;
    high_left=altura(raiz->left);
    high_right=altura(raiz->right);
    //a funcao tenta ir por todos os caminhos ate achar o maior, o maior sera a altura
    if(high_left>high_right)
        return high_left+1;
    else
        return high_right+1;
}

void libera_no(p_no no){
    if(no==NULL)
        return;
    //usando recursao vai liberando a memoria alocada ate chegar nas folhas das arvores
    libera_no(no->left);
    libera_no(no->right);
    free(no);
    //no=NULL;
}

void destruir_arvore(p_no raiz){
    if(raiz==NULL)
        return;
    libera_no(raiz);//chama a funcao recursiva que se destruira
    //free(raiz);//libera a raiz
}

void imprime(p_no raiz){
    if(raiz==NULL)return;
    imprime(raiz->left);//
    printf("%d\n", raiz->value);
    imprime(raiz->right);
}
