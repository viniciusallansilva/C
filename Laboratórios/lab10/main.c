#include <stdio.h>
#include <stdlib.h>
#include "tabelahash.h"

int main(){
    int N, colisoes;
    scanf("%d", &N);
    int *tabela_hash=cria_tabela_hash(N);
    colisoes=organiza_tabela(tabela_hash, N);
    destroi_tabela(tabela_hash);
    printa_na_tela(colisoes);
    return 0;
}
