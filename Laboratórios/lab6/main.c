#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quick.h"

int main()
{
    int numeros_no_quarto, numero_bonito,indice;//Variaveis que serao armazenados a quantidade de numeros no quarto e o indice do numero bonito
    scanf("%d %d", &numeros_no_quarto, &numero_bonito);

    int array[numeros_no_quarto];

    for(indice=0;indice<numeros_no_quarto;indice++){//laco para colocar no vetor os numeros no quarto
        scanf("%d", &array[indice]);
    }

    quicksort(array,0, numeros_no_quarto-1);//chamada da funcao quick sort que ordenara o vetor com os numeros no quarto

    printf("%d\n", array[numero_bonito-1]);//escrevemos na tela o numero bonito, mas descontamos 1 pq o vetor comeca com indice 0

    return 0;
}
