#include <stdio.h>
#include <stdlib.h>
#include "listacircular.h"

int main()
{
    int quantidade_cliente;
    int cliente_cabeca;
    int criterio1;
    int criterio2;
    int b,v;
    scanf("%d %d %d %d", &quantidade_cliente, &cliente_cabeca, &criterio1, &criterio2);

    lista *lista_circular=cria_nova_lista();
    for(int i=0;i<quantidade_cliente;i++)
        inserenalista(lista_circular, i);

    no *atendente_1=procuraNo(lista_circular,cliente_cabeca);
    no *atendente_2=atendente_1;
    no *auxiliar_1;
    no *auxiliar_2;

    for(int i=0;i<criterio1;i++){
        atendente_1=atendente_1->Back;
    }
    for(int j=0;j<criterio2;j++){
        atendente_2=atendente_2->Next;
    }

    while(listavazia(lista_circular)==0){
        printf("%d %d\n", atendente_1->Cliente, atendente_2->Cliente);
        auxiliar_1=atendente_1->Next;
        auxiliar_2=atendente_2->Back;
        if(atendente_1==atendente_2)
            removelista(lista_circular, atendente_1->Cliente);
        else{
            removelista(lista_circular, atendente_1->Cliente);
            removelista(lista_circular, atendente_2->Cliente);
        }
        if(listavazia(lista_circular)==1){
            atendente_1=atendente_2=auxiliar_1=auxiliar_2=NULL;
            break;
        }
        auxiliar_1=procuraNo(lista_circular, auxiliar_1->Cliente);
        auxiliar_2=procuraNo(lista_circular, auxiliar_2->Cliente);
        atendente_1=auxiliar_1;
        atendente_2=auxiliar_2;
        for(b=0;b<criterio1;b++)
            atendente_1=atendente_1->Back;
        for(v=0;v<criterio2;v++)
            atendente_2=atendente_2->Next;
    }
    free(atendente_1);
    free(atendente_2);
    free(auxiliar_1);
    free(auxiliar_2);
    free(lista_circular);
    return 0;
}
