#include <stdio.h>
 
int main()
{
    int i, nCifra = 0, casos = 0, letraCodificada = 0;
    char palavra[51];

    scanf("%d", &casos);

    while(casos--){

        scanf("%s", palavra);
        scanf("%d", &nCifra);

        for (i = 0; i < 50; i++){
            if (palavra[i] == '\0') break;

            if ((palavra[i] - nCifra) < 65) letraCodificada = (palavra[i] - nCifra) + 26; // 65 em ASCII é A.
            else letraCodificada = palavra[i] - nCifra;

            printf("%c", letraCodificada);
        }

        printf("\n"); //Final de cada caso
    }
    return 0;
}