/*
Programa: Lab 04 - LDDE
Autor: Pedro Henrique de Almeida
Versao: 1.0 - 20/06/2021
*/

// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>
// ########################## TAD X.h ######################################
struct elemento{
     int info;
     struct elemento *prox;
     struct elemento *ant;
};
typedef struct elemento tipoElementoLDDE;
struct estruturaLDDE{
     tipoElementoLDDE *primeiro;
     tipoElementoLDDE *ultimo;
     int tamanho;
};
typedef struct estruturaLDDE tipoListaLDDE;

// ###################### Funcoes e Procedimentos do programa ##############
void inicializaLista (tipoListaLDDE *listaAux){
     listaAux->primeiro = NULL;
     listaAux->ultimo = NULL;
     listaAux->tamanho=0;
}

void insereLista(tipoListaLDDE *listaAux){
    tipoElementoLDDE *novoElem = malloc(sizeof(tipoElementoLDDE));
    scanf("%d", &novoElem->info);
    if (listaAux->tamanho == 0) listaAux->primeiro = novoElem;
    else listaAux->ultimo->prox = novoElem;
    novoElem->ant = listaAux->ultimo;
    listaAux->ultimo=novoElem;
    if(listaAux->tamanho == 9){
        novoElem->prox = listaAux->primeiro;
        listaAux->primeiro->ant = listaAux->ultimo;
    }else{
        novoElem->prox = NULL;
    }
    listaAux->tamanho++;
}

void insereNovo(tipoListaLDDE *listaAux){
    int pos, i;
    tipoElementoLDDE *aux = listaAux->primeiro;
    tipoElementoLDDE *novoElem = malloc(sizeof(tipoElementoLDDE));
    scanf("%d %d", &novoElem->info, &pos);

    if(listaAux->tamanho == 0){
        listaAux->primeiro = novoElem;
        listaAux->ultimo = novoElem;
        novoElem->ant = NULL;
        novoElem->prox = NULL;
    }else{
        for(i = 0; i < pos; i++)aux = aux->prox;
        
        if(listaAux->tamanho > 1){
            aux->ant->prox = novoElem;
            novoElem->ant = aux->ant;
        }else{
            aux->prox = novoElem;
            novoElem->ant = aux;
        }

        aux->ant = novoElem;
        novoElem->prox = aux;

        if(pos == 0) listaAux->primeiro = novoElem;
        else if(pos >= listaAux->tamanho) listaAux->ultimo = novoElem;
    }
    listaAux->tamanho++;
}

void printaLista(tipoListaLDDE *listaAux){
    tipoElementoLDDE *aux;
    aux = listaAux->primeiro;
    while(aux != NULL){
        printf("%d ", aux->info);
        if(aux == listaAux->ultimo) aux = NULL;
        else aux = aux->prox;
    }
    if(listaAux->tamanho > 0) printf("\n");
}

void procuraRemoveTripla(tipoListaLDDE *listaAux){
    tipoElementoLDDE *segundo = listaAux->primeiro;
    tipoElementoLDDE *terceiro = segundo->prox;
    tipoElementoLDDE *primeiro = listaAux->ultimo;
    while(listaAux->tamanho > 2 && primeiro != NULL){
        if(primeiro->info + segundo->info + terceiro->info == 10){
            if(listaAux->tamanho == 3){                                 //TRIPLA UNICA
                listaAux->primeiro = NULL;
                listaAux->ultimo = NULL;
            }else if(primeiro == listaAux->primeiro){                   //TIPO TRIPLA 1
                listaAux->primeiro = terceiro->prox;
                listaAux->primeiro->ant = listaAux->ultimo;
                listaAux->ultimo->prox = listaAux->primeiro;
            }else if(segundo == listaAux->ultimo){                      //TIPO TRIPLA 2
                listaAux->primeiro = terceiro->prox;
                listaAux->ultimo = primeiro->ant;
                listaAux->ultimo->prox = listaAux->primeiro;
                listaAux->primeiro->ant = listaAux->ultimo;
            }else if(primeiro == listaAux->ultimo){                   //TIPO TRIPLA 3
                listaAux->ultimo = primeiro->ant;
                listaAux->primeiro = terceiro->prox;
                listaAux->ultimo->prox = listaAux->primeiro;
                listaAux->primeiro->ant = listaAux->ultimo;
            }else if(terceiro == listaAux->ultimo){                    //TIPO TRIPLA 4
                listaAux->ultimo = primeiro->ant;
                listaAux->ultimo->prox = listaAux->primeiro;
                listaAux->primeiro->ant = primeiro->ant;
            }else{                                                     //TRIPLA NO MEIO
                terceiro->prox->ant = primeiro->ant;
                primeiro->ant->prox = terceiro->prox;
            }
            listaAux->tamanho -= 3;

            if(listaAux->tamanho > 2){
                primeiro = listaAux->ultimo;
                segundo = listaAux->primeiro;
                terceiro = segundo->prox;
            }else primeiro = NULL;

        }else if(primeiro == listaAux->ultimo->ant)
            primeiro = NULL;
        else{
            primeiro = primeiro->prox;
            segundo = segundo->prox;
            terceiro = terceiro->prox;
        }
    }
}
// ############################ Principal ###################################
int main(){
    tipoListaLDDE minhaLista;
    inicializaLista(&minhaLista);
    int i, j;

    for(i = 0; i < 10; i++) insereLista(&minhaLista);
    printaLista(&minhaLista);

    for(j = 0; j < 5; j++){
        insereNovo(&minhaLista);
        if(minhaLista.tamanho > 2) procuraRemoveTripla(&minhaLista);
        printaLista(&minhaLista);
    }

    if(minhaLista.tamanho == 0) printf("ganhou\n");
    else printf("perdeu\n");

    return 0;
}