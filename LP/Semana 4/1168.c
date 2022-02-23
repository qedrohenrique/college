#include <stdio.h>

int main(){

    int numcasos,total,i, n;
    char numero[101];

    scanf("%d", &numcasos);

    for(n=0;n<numcasos;n++){

        i=0;
        total=0;

        scanf("%s", numero);
        while(1){
        if(numero[i]=='\0') break;
        if(numero[i]=='1') total+=2;
        if(numero[i]=='2') total+=5;
        if(numero[i]=='3') total+=5;
        if(numero[i]=='4') total+=4;
        if(numero[i]=='5') total+=5;
        if(numero[i]=='6') total+=6;
        if(numero[i]=='7') total+=3;
        if(numero[i]=='8') total+=7;
        if(numero[i]=='9') total+=6;
        if(numero[i]=='0') total+=6;
        i++;
        }

        printf("%d leds\n", total);
    }



    return 0;
}