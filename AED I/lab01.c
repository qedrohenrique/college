/* Programa: LES lab1
   Autor: Pedro Henrique de Almeida
   Versao: 1.0 - 16/05/2021
*/
 
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
// ########################## TAD X.h ######################################
struct list{
    int last;
    int listsize;
    int list[100];
};
typedef struct list unifesplist;
// ###################### Funcoes e Procedimentos do programa ##############
void startlist (unifesplist *listAux){
    int j;
    listAux->listsize = 0;
    for(j = 0; j<100; j++)
        listAux->list[j] = 0;
    listAux->last = 0;
};
 
 
int insertelement (unifesplist *listAux, int bookAux){
 
    int result;
 
    if(listAux->listsize < 10){
 
        listAux->listsize++;
        listAux->list[listAux->listsize-1] = bookAux;
        listAux->last = listAux->listsize-1;
 
        printf("Sua reserva foi realizada\n");
        
        result = 1;
    }else{
        printf("Lista de reserva cheia\n");
        result = 0;
    }
    return result;
}
 
int removeelement (unifesplist *listAux, int bookAux){
    
    int result;
    int k, p;
 
    for(k = 0; k<listAux->listsize; k++){
 
        if(listAux->list[k] == bookAux){
 
            for(p = k; p < listAux->listsize; p++){
                listAux->list[p] = listAux->list[p+1];
            }
 
            listAux->listsize--;
            listAux->last = listAux->listsize - 1;
 
            result = 1;
            printf("O livro foi retirado com sucesso\n");
            return result;
        }else if(k==listAux->last){
            printf("Voce nao possui reserva desse livro\n");
            result = 0;
            return result;
        }
    }
     if(k == 0 && listAux->listsize == 0){
        printf("Voce nao possui reserva desse livro\n");
        result = 0;
        return result;
    }
}
 
// ############################ Principal ###################################
int main(){
 
    int moves, movetype, book, reservas = 0, retiradas = 0, caso = 0;
    int i;
    unifesplist mylist;
 
    scanf("%d", &moves);
 
    startlist(&mylist);
 
    for (i=0; i<moves; i++){
 
        scanf("%d %d", &movetype, &book);
 
        //RESERVAR
        if(movetype==1){
            caso = insertelement(&mylist, book);
            if (caso == 1) reservas++;
        }
        //RETIRAR
        if(movetype==2){
            caso = removeelement(&mylist, book);
            if (caso == 1) retiradas++;
        }
    }
 
    printf("Voce realizou %d reservas e %d retiradas\n", reservas, retiradas);
 
    return 0;
}
