#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Variavel global que guarda a soma de todas a itera��es feita no programa*/
long long int iteracoes=0;

/*funcao que aloca vetor um vetor auxiliar*/
long long int * cria_vetor(long long int tamanho){
    long long int *novo;
    novo=(long long int *)malloc(tamanho*sizeof(long long int));
    return novo;
}

/*funcao Merge que junta dois vetores ordenados*/
void Merge(long long int *array, long long int begin, long long int middle, long long int end){
    long long int iteracoes_local=0;//soma as iteracoe de cada merge
    long long int *vetor_auxiliar,indice1,indice2,tamanho,i,j,k,tam_vetor_auxiliar;
    int end1=0,end2=0;
    tamanho=end-begin+1;
    indice1=begin;
    indice2=middle+1;
    tam_vetor_auxiliar=indice2-indice1;
    vetor_auxiliar=cria_vetor(tamanho);
    if(vetor_auxiliar!=NULL){
        for(i=0;i<tamanho;i++){
            if(!end1 && !end2){
                if(array[indice1]<=array[indice2]){//faz a comparacao entre os dois indices do vetor;
                    vetor_auxiliar[i]=array[indice1++];
                    tam_vetor_auxiliar--;
                }
                else{
                    iteracoes_local=iteracoes_local+(tam_vetor_auxiliar);
                    vetor_auxiliar[i]=array[indice2++];
                }
                if(indice1>middle)end1=1;//caso algum vetor ja estiver acabado, ele determina como completo a epenas copia o q sobrou
                if(indice2>end)end2=1;//caso algum vetor ja estiver acabado, ele determina como completo a epenas copia o q sobrou
            }else{
                if(!end1){
                    vetor_auxiliar[i]=array[indice1++];//vetor 2 já foi comparado inteiro entao só resta copar o vetor 1 para o auxiliar
                }
                else
                    vetor_auxiliar[i]=array[indice2++];//vetor 1 já foi comparado inteiro entao só resta copar o vetor 2 para o auxiliar
            }
        }
        for(j=0,k=begin;j<tamanho;j++,k++)
            array[k]=vetor_auxiliar[j];
    }
    free(vetor_auxiliar);//liberacao do vetor auxiliar usado
    iteracoes=iteracoes+iteracoes_local;//transfere para as iteracoes totais
}

/*funcao que dividi um vetor em 2 menores pela metade usando recursso ate o  tamanho minimo possivel*/
void MergeSort(long long int *array, long long int begin, long long int end){
    int middle;
    if(begin<end){
        middle=floor((begin+end)/2);//posicao central
        MergeSort(array, begin, middle);//continua dividindo o vetor mas do comeco ate a metade
        MergeSort(array, middle+1, end);//continua dividindo o vetor mas da metade+1 ate o fim
        Merge(array, begin, middle, end);//junta as duas aprtes divididass
    }
}

int main()
{
    long long int N, i;
    scanf("%lld", &N);
    long long int vector[N];
    for(i=0;i<N;i++){
        scanf("%lld", &vector[i]);
    }
    MergeSort(vector, 0, N);
    printf("%lld\n", iteracoes);
    return 0;
}
