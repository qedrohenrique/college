#include <stdio.h>

int main(){

    int matriz, linha, coluna;

    while(scanf("%d", &matriz)!=EOF){

        for(linha = 0; linha < matriz; linha++){
            for(coluna = 0;coluna < matriz; coluna++){
                if(linha + coluna == matriz - 1) printf("2");
                else if(linha == coluna) printf("1");
                else printf("3");
            }
            printf("\n");
        }
    }
	 return 0;
}