#include <stdio.h>
#include <string.h>

typedef struct{
	char string[51];
} word;   //Para fazer uma matriz de strings

int main (){

	int casos, maior;
	int i, aux, atual;

	scanf("%d\n", &casos);
	while (casos != 0){

		aux = casos; //Casos será alterado
		word palavra[aux];
		i = 0; //Reiniciar i

		while (casos--) scanf(" %s", palavra[i++].string); //Ler todas as palvras

		maior = 0;   //Achar a palavra maior
		for(i = 0; i < aux; i++){	
			atual = strlen(palavra[i].string);
			if (atual > maior)
				maior = atual;
		}

		for (i = 0; i < aux; i++) printf("%*s\n", maior, palavra[i].string);

		scanf("%d", &casos);
		if (casos != 0) printf("\n");

	}	
    return 0;
}