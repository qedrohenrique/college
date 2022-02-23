#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[51];
    double preco;
}fruta;            // Tipo de variável p/ facilitar 

fruta frutas[10000];

int main(){
	
	char fruta_comprada[51];
	int casos, tamanho_lista_disponiveis, tamanho_lista_comprado, qnt, s;
    	int aux, aux2;
	double total;

	scanf("%d", &casos);

	while(casos--){

		scanf("%d", &tamanho_lista_disponiveis);
		for(aux=0;aux<tamanho_lista_disponiveis;aux++) scanf("%s %lf", frutas[aux].nome, &frutas[aux].preco); // Lista de frutas e seus precos

		scanf("%d", &tamanho_lista_comprado);
		for(aux=0, total=0;aux<tamanho_lista_comprado;aux++){

			scanf("%s %d", fruta_comprada, &qnt); // Lista de frutas a serem compradas

			for(aux2=0,s=0;aux2<tamanho_lista_disponiveis && s==0;aux2++)
				if(strcmp(fruta_comprada,frutas[aux2].nome)==0){
					total+=frutas[aux2].preco * qnt;
					s=1; //Sair do Loop interno
				}

		}

		printf("R$ %.2lf\n", total); // Resultado da instancia
	}
	
	return 0;
}
