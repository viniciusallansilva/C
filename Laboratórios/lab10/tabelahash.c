#include <stdio.h>
#include <stdlib.h>
#include "tabelahash.h"

int HASH(int numero, int tamanho_tabela){
    return numero%tamanho_tabela;//conta que retorna o resto de X por tamanho tabela
}

int * cria_tabela_hash(int tamanho_da_tabela){
    int* tabela_hash=(int*)calloc(tamanho_da_tabela, sizeof(int));//calloca o tamanho necessario do vetor, é necessario que seja callocado pq necessitamos de vetores vazios
    return tabela_hash;
}

void destroi_tabela(int * tabela_hash){
    free(tabela_hash);// libera espaco na memoria do vetor de inteiro antes callocado
}

void printa_na_tela(int numero_colisoes){
    printf("%d\n", numero_colisoes);//printa na tela o numero total de colisoes
}

int organiza_tabela(int* tabela_hash, int tamanho_da_tabela){
    int i, numero, resto, colisoes=0;
    for(i=0;i<tamanho_da_tabela;i++){
        scanf("%d", &numero);
        resto=HASH(numero, tamanho_da_tabela);//chama a funcao resto baseado no numero que o usuario colocou e pelo tamanho do vetor recebido
        while(tabela_hash[resto]!=0){
            resto++;//como a posicao do resto e diferente de zero, houve colisao entao ele avanca
            colisoes++;
            if(resto==tamanho_da_tabela)//caso o indice do vetor chegue no final, voltamos pro inicio do vetor
                resto=0;
        }
        tabela_hash[resto]=numero;
    }
    return colisoes;
}
