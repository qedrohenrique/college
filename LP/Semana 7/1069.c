#include <stdio.h>
#include <string.h>
 
int main(){

    int i, j; //auxiliares
    int casos = 0, diamante;
    char solo[1000]; //Entrada de "<", ">" e "."

    scanf("%d", &casos);
    while (casos--){

        scanf("%s", solo);
        diamante = 0; //Reiniciar os diamantes achados para cada caso

        for (i = 0; i < strlen(solo); i++){

            if (solo[i] == '\0') break; //Nenhum diamante encontrado

            if (solo[i] == '<'){
                for (j = i; j< strlen(solo); j++){
                    if (solo[j] == '>'){
                        diamante++;
                        solo[j] = '1';
                        break;              //Encontra a metade restante do diamante e substitui por 1 (encontrado)
                    }
                }
            }
        }

        printf("%d\n", diamante); //Diamantes achados 
    }
    return 0;
}