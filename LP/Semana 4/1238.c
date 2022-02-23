#include <stdio.h>

int main(){

    int casos;
    int j,i;
    int tam1, tam2, tamMaior;
    char a[51],b[51];

    scanf("%d", &casos);

    for (i=0; i<casos; i++){
        scanf("%s %s", a, b);

        tam1 = strlen(a);
        tam2 = strlen (b);
        if(tam1>tam2) tamMaior = tam1;
        else tamMaior = tam2;

        for(j=0; j<tamMaior; j++){
            if(j<tam1) printf("%c", a[j]);
            if(j<tam2) printf("%c", b[j]);
        }

        printf("\n");
    }

    return 0;
}
    