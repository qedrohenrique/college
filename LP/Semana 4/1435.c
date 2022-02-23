#include <stdio.h>

int main ()
{

	int tamanho, coluna, linha, inicio, final, elemento;

	while (1){
		scanf("%d", &tamanho);

		int array[tamanho][tamanho];

		if (tamanho == 0) return 0;

		inicio = 0;
		final = tamanho;
		elemento = 1;

		while(1){
			for (linha = inicio; linha < final; linha++)
				for (coluna = inicio; coluna < final; coluna++) array[linha][coluna] = elemento;

			if (final == 0) break;

			final--;
			inicio++;
			elemento++;
		}

		for (linha = 0; linha < tamanho; linha++){

			for (coluna = 0; coluna < tamanho; coluna++){
				if (coluna == 0)
					printf("%3d", array[linha][coluna]);
				else
					printf(" %3d", array[linha][coluna]);
			}
			printf("\n");
		}

		printf("\n");
	}
}