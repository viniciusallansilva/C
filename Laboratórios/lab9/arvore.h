#ifndef _ARVORE_H_
#define _ARVORE_H_
/*
ESTRUTURA DO NO DA ARVORE
*/
typedef struct noarvore{
    int value;
    struct noarvore* left;
    struct noarvore* right;
}No;
/*
DECLARO PONTEIRO PARA NO COMO P_NO
*/
typedef No* p_no;
/*
FUNCAO VAZIA QUE DESTROI ARVORE RECURSIVAMENTE
*/
void destruir_arvore(p_no raiz);
/*
FUNCAO QUE SEMPRE DEVOLVE A RAIZ DA ARVORE E INSERE UM VALOR NOVO NELA USANDO A LOGICA DE BUSCA
*/
p_no inserir(p_no raiz, int valor);
/*
FAZ A CONTAGEM DA ALTURA DA ARVORE USANDO RECURSAO
*/
int altura(p_no raiz);
/*
FUNCAO VAZIA RECURSIVA QUE IMPRIMI ARVORE PARA ETAPAS DE TESTES DO PROGRAMA
*/
void imprime(p_no raiz);

void libera_no(p_no no);
#endif // _ARVORE_H_
