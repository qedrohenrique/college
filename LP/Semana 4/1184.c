#include <stdio.h>

int main (){

    double matriz[12][12], somaTotal=0, media;
    int n=1, x=0, y=0;
    int linha, coluna;
    char operacao;

    scanf("%c", &operacao);

    for(linha=0; linha<12; linha++){
        for(coluna=0; coluna<12; coluna++){
            scanf("%lf", &matriz[linha][coluna]);
        }
    }

//SOMA
    for(y=0; y<11; y++){
        for(x=0; x!=12; x++){
            if(x+n<12) somaTotal+=matriz[x+n][y];
            else break;
        }
        n++;
    }

//MEDIA

    media=somaTotal/66.0;

//IMPRESSAO
    if(operacao=='S') printf("%.1lf\n", somaTotal);

    if(operacao=='M') printf("%.1lf\n", media);

    return 0;
}