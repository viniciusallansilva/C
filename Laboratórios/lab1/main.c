#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000

// Função que le do teclado o tamanho da matriz
int leTamanhoMatriz(){
    int tam;
    scanf("%d", &tam);
    return tam;
}

//Lê do teclado as informações da matriz
void leMatriz(int Matriz[][MAX], int TamanhoMatriz){
    int i,j;//índices para percorrer a matiz
    for(i=0;i<TamanhoMatriz;i++){
        for(j=0;j<TamanhoMatriz;j++){
            scanf("%d", &Matriz[i][j]);
        }
    }
}

//Devolve um inteiro correspondente a soma da diagonal principal
int SomaDiagPrin(int Matriz[][MAX], int TamanhoMatriz){
    int i;//índice para percorrer a matriz
    int soma=0;
    for(i=0;i<TamanhoMatriz;i++){
        soma+=Matriz[i][i];
    }
    return soma;
}

//Devolve um inteiro correspondente a soma da diagonal secundária
int SomaDiagSec(int Matriz[][MAX], int TamanhoMatriz){
    int i,j;//índices para percorrer a matriz
    int soma=0;
    for(i=0;i<TamanhoMatriz;i++){
        for(j=0;j<TamanhoMatriz;j++){
            soma+=Matriz[i][TamanhoMatriz-j-1];
        }
    }
    return soma;
}

//devolve 0 se for par e 1 se for impar
int e_impar(int numero){
    if(numero%2==0){
        return 0;
    }
    return 1;
}

int ContaColunasPar(int Matriz[][MAX], int TamanhoMatriz){
    int i,j;//índices para percorrer a matriz
    int soma_col=0,soma_total=0;
    for(i=0;i<TamanhoMatriz;i++){
        for(j=0;j<TamanhoMatriz;j++){
            soma_col+=Matriz[j][i];
        }
        if(e_impar(soma_col)==0){
            soma_total++;
        }
    }
    return soma_total;
}

int ContaLinhasImpar(int Matriz[][MAX],int TamanhoMatriz){
    int i,j;//índices para percorrer a matriz
    int soma_lin=0,soma_total=0;
    for(i=0;i<TamanhoMatriz;i++){
        for(j=0;j<TamanhoMatriz;j++){
            soma_lin+=Matriz[i][j];
        }
        if(e_impar(soma_lin)==1){
            soma_total++;
        }
    }
    return soma_total;
}

void saida(int a, int b, int c, int d){
    printf("%d %d %d %d",a,b,c,d);
}
int main(){
    int TamMatriz=leTamanhoMatriz();
    //Cria matriz quadrada
    int Matriz[MAX][MAX];

    leMatriz(Matriz, TamMatriz);

    saida(SomaDiagPrin(Matriz, TamMatriz), SomaDiagSec(Matriz, TamMatriz), ContaColunasPar(Matriz, TamMatriz), ContaLinhasImpar(Matriz,TamMatriz));

    return 0;
}
