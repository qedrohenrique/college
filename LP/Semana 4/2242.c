#include <stdio.h>
#include <string.h>

int main(){

    char risada[51], vogais[51], resultado;
    int i=0, j=0, comprimento=0;

    scanf("%s", risada);

    //Criar string somente com as vogais da risada.

    for(i=0; risada[i]; i++){
        if(risada[i]=='a'||risada[i]=='e'||risada[i]=='u'||risada[i]=='i'||risada[i]=='o'){
            vogais[j]=risada[i];
            j++;
        }
    }
    vogais[j]='\0';

    //Comparar a risada na E->D com a risada da D->E, imprimir resposta.
    
    comprimento=strlen(vogais);
    
    for(i=0, j=comprimento-1; i<comprimento; i++, j--){
        if(vogais[i]!=vogais[j]){
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");

    return 0;
}