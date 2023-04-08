#ifndef _TABELAHASH_H_
#define _TABELAHASH_H_

/*
FUNCAO RESPONSAVEL POR GERAR O INDICE A QUAL O NUMERO VAI SER COLADO NA TABELA
*/
int HASH(int numero, int tamanho_tabela);
/*
FUNCAO RESPONSAVEL POR CRIA UM VETOR DANIMICO DE INTEIROS
*/
int * cria_tabela_hash(int tamanho_da_tabela);
/*
FUNCAO VAZIA QUE LIBERA O ESPACO NA MEMORIA OCUPADO PELO VETOR DINAMICO
*/
void destroi_tabela(int * tabela_hash);
/*
FUNCAO QUE PRINTA NA TELA O NUMERO TOTAL DE COLISAO
*/
void printa_na_tela(int numero_colisoes);
/*
FUNCAO RESPONSAVEL POR COLOCAR O NUMERO NA POSICAO CERTA DO VETOR
ELA TAMBEM CONTA O NUMERO DE COLISAO DE DEVOLVE ESSE VALOR
*/
int organiza_tabela(int* tabela_hash, int tamanho_da_tabela);
#endif // _TABELAHASH_H_
