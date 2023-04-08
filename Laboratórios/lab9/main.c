#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    int i,j,altura_DN,altura_amigo,v,b;
    int quantidade_elementos;
    scanf("%d", &quantidade_elementos);//le do teclado a quantidade de elementos

    int *numeros_DN=(int*)malloc(quantidade_elementos*sizeof(int));//vetor de inteiro alocado dinamicamente
    //int numeros_DN[quantidade_elementos];

    for(i=0;i<quantidade_elementos;i++)
        scanf("%d", &numeros_DN[i]);//preenche o vetor numeros_DN com os numeros lidos

    p_no raiz_DN=NULL;//inicializa um ponteiro para raiz como NULL

    for(v=0;v<quantidade_elementos;v++)
        raiz_DN=inserir(raiz_DN,numeros_DN[v]);//cria a arvore e sempre devolvendo a raiz da arvore de DN

    free(numeros_DN);//liberamos o vetor para n ocupar espaço na memoria

    altura_DN=altura(raiz_DN);//guardamos o valor da altura para podermos liberar a arvore

    destruir_arvore(raiz_DN);//funcao recursiva que destroi a arvore, ja que ela foi alocada na memoria, precisa ser liberada



    /*PARTE DO AMIGO*/


    p_no raiz_amigo=NULL;//inicializa um outro ponteiro da raiz da arvore do amigo de DN

    int *numeros_amigo=(int*)malloc(quantidade_elementos*sizeof(int));//alocamos dinamicamente o vetor
    //int numeros_amigo[quantidade_elementos];

    for(j=0;j<quantidade_elementos;j++)
        scanf("%d", &numeros_amigo[j]);//prrenche o vetor numeros_amigos com os valores lido

    for(b=0;b<quantidade_elementos;b++)
        raiz_amigo=inserir(raiz_amigo,numeros_amigo[b]);//cria a arvore do amigo e sempre devolve a raiz da arvore do amigo

    free(numeros_amigo);//liberamos o vetor dinamico do amigo para ganharmos espaco da memoria

    altura_amigo=altura(raiz_amigo);//guardamos o valor da altura para podermos liberar a arvore

    destruir_arvore(raiz_amigo);//funcao recursiva que destroi a arvore, ja que ela foi alocada na memoria, precisa ser liberada

    printf("%d %d\n", altura_DN, altura_amigo);//escreve na tela as dois valores da altura

    return 0;
}
