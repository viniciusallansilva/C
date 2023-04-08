#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "quick.h"

void troca(int *array, int i, int j){
    int k=array[i];
    array[i]=array[j];
    array[j]=k;
}

int particao(int *array ,int begin, int end){
    int indice=begin;
    int indice2;
    for(indice2=begin;indice2<end;indice2++){
        if(array[indice2]<=array[end]){
            troca(array, indice, indice2);
            indice++;
        }
    }
    troca(array, indice, end);
    return indice;
}

void quicksort(int *array, int start, int end){
    if(start>=end)return;
    int pivot=particao(array, start, end);
    quicksort(array, start, pivot-1);
    quicksort(array, pivot+1, end);
}
