#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
	int X;
	int Y;
} Dados;

int main(){
	int P,indice,j;
	int entrada,x,y;
	int indice_idade=0;
	int soma=0;
	int quantidade_idade=0;
	int capacidade_memoria=5;
	int idade_existe=0;
	scanf("%d", &P);

	Dados *nuvem;
	nuvem=(Dados* )malloc(capacidade_memoria*sizeof(Dados));

	Dados *nuvem2;
	nuvem2=(Dados* )malloc(capacidade_memoria*sizeof(Dados));

	for(indice=0;indice<P;indice++){
		scanf("%d %d %d", &entrada, &x, &y);
		if(entrada==0){
			if(quantidade_idade==capacidade_memoria){
				capacidade_memoria=2*capacidade_memoria;
				*nuvem2=*nuvem;
				nuvem=(Dados* )malloc(capacidade_memoria*sizeof(Dados));
				*nuvem=*nuvem2;
				nuvem2=(Dados* )malloc(capacidade_memoria*sizeof(Dados));
			}

			for(int z=0;z<quantidade_idade;z++){
				if(y==nuvem[z].Y){
					nuvem[z].X+=x;
					idade_existe=1;
				}
			}
			if(idade_existe==0){
				nuvem[indice_idade].X=x;
				nuvem[indice_idade].Y=y;
				quantidade_idade++;
				indice_idade++;
			}
			idade_existe=0;
		}

		else if(entrada==1){
			for(j=0;j<quantidade_idade;j++){
				if(nuvem[j].Y>=x && nuvem[j].Y<=y){
					soma+=nuvem[j].X;
				}
			}
			printf("%d\n", soma);
			soma=0;
		}
	}
	free (nuvem);
	return 0;
}
