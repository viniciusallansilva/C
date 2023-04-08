#ifndef _QUICK_H_
#define _QUICK_H_
/*funcao que troca dois elementos do vetor mediante ao seu dois indice*/
void troca(int *array, int i, int j);
/*funcao responsavel pela particao*/
int particao(int *array ,int begin, int end);
/*funcao recursiva que ira dividir para conquistar o vetor inteiro*/
void quicksort(int *array, int start, int end);
#endif // _QUICK_H_
