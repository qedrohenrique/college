#include <stdio.h>

int main(){

    int m,n,soma,tamanho,i;
    char stringNumero[50];

    while(1){

        scanf("%d %d", &m, &n);

        if(m==0&&n==0) break;
        soma = m+n;

        tamanho = sprintf(stringNumero, "%d", soma); //Salva soma em stringNumero como uma string, retorna o tamanho da string.
        stringNumero[tamanho+1]='\0';

        for(i=0;i<tamanho;i++){
            if(stringNumero[i]!='0') printf("%c", stringNumero[i]);
        }

        printf("\n"); //Final de cada caso de teste
    }

    return 0;
}